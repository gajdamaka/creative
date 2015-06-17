<?php
/**
 * @file
 * API for CTools content types.
 */

/**
 * Main function for defining the CTools API content type.
 *
 * @param string $path
 *   Path to file (__FILE__ constant).
 * @param array $data
 *   Additional data for plugin definition.
 *
 * @return array
 *   Updated plugin definition.
 */
function ctools_api_content_type($path, array $data) {
  static $theme_registry = array(), $theme_path = '';

  if (empty($theme_registry)) {
    $theme_registry = theme_get_registry();
    $theme_path = drupal_get_path('theme', variable_get('theme_default'));
  }

  $content_type = pathinfo($path, PATHINFO_FILENAME);

  $data['render callback'] = _ctools_api_func('content_types_base_render');
  $data['admin info'] = _ctools_api_func('content_types_base_admin_info');
  $data['edit form'] = _ctools_api_func('content_types_base_settings_form');

  if (!isset($data['category'])) {
    $data['category'] = t('CTools content types');
  }

  _ctools_api_set_plugin_theme($data, 'content_types', $content_type);

  foreach ($data['theme suggestions'] as $hook => $suggestion) {
    if (!isset($theme_registry[$suggestion])) {
      continue;
    }

    $assets_path = str_replace("$theme_path/templates/", '', $theme_registry[$suggestion]['path']);

    foreach (array('css', 'js') as $type) {
      $data[$type][] = "$theme_path/$type/$assets_path/$content_type--$hook.$type";
    }
  }

  return $data;
}

/**
 * Base render for admin preview.
 *
 * @param string $content_type
 *   Machine name of the pane.
 * @param array $conf
 *   Pane settings.
 * @param array $context
 *   Pane context.
 *
 * @see _ctools_api_content_types_base_render()
 *
 * @return \stdClass
 *   Pane block.
 */
function _ctools_api_content_types_base_admin_info($content_type, array $conf, array $context) {
  return call_user_func_array(_ctools_api_func('content_types_base_render'), func_get_args());
}

/**
 * Base render for CTools API content type.
 *
 * @param string $content_type
 *   Pane machine name.
 * @param array $conf
 *   Saved data.
 * @param array $args
 *   Pane arguments.
 * @param \ctools_context $context
 *   Pane context.
 *
 * @return \stdClass
 *   Drupal block.
 */
function _ctools_api_content_types_base_render($content_type, array $conf, array $args, \ctools_context $context = NULL) {
  static $plugins = array(), $processed = array();

  if (empty($plugins)) {
    $plugins = ctools_get_plugins('ctools', 'content_types');
  }

  $func = _ctools_api_callback('content_types', 'pane', $content_type, 'preprocess');

  if (!empty($func)) {
    $func($conf, $args, $context);
  }

  $block = new \stdClass();
  $block->delta = $content_type;
  $block->region = $block->module = CTOOLS_API_MODULE_NAME;
  $block->subject = $block->title = '';

  if (isset($conf['theme'])) {
    if (empty($processed[$content_type])) {
      foreach (array(
        'css' => array(),
        'js' => array(
          'scope' => 'footer',
        ),
      ) as $type => $options) {
        if (isset($plugins[$content_type][$type])) {
          foreach ($plugins[$content_type][$type] as $file) {
            if (file_exists($file)) {
              call_user_func("drupal_add_$type", $file, $options);
            }
          }
        }
      }

      $processed[$content_type] = TRUE;
    }

    $block->content = _ctools_api_apply_plugin_theme('content_types', $content_type, $conf['theme'], $conf);
  }
  else {
    $block->content = t('You must create at least one theme hook and template for output pane content.');
  }

  return $block;
}

/**
 * Base form for each CTools API content type.
 *
 * @param array $form
 *   Form implementation.
 * @param array $form_state
 *   Form state.
 *
 * @return array
 *   Updated form.
 */
function _ctools_api_content_types_base_settings_form(array $form, array &$form_state) {
  $form['#submit'][] = __FUNCTION__ . '_submit';

  $plugin = $form_state['plugin'];
  $items = array();
  $func = _ctools_api_callback('content_types', 'pane', $plugin['name'], 'settings_form');

  if (!empty($func)) {
    $func($items, $form_state);
  }

  $theme = array(
    'theme' => array(
      '#type' => 'select',
      '#title' => t('Choose theme'),
      '#options' => $plugin['theme hooks'],
      '#default_value' => $plugin['name'],
    ),
  );

  if (!empty($plugin['theme hooks'])) {
    $items = array_merge($theme, $items);
  }

  if (isset($form['override_title'])) {
    $form['override_title']['#default_value'] = 1;

    $form['override_title_text'] = array_merge($form['override_title_text'], array(
      '#title' => t('Pane title'),
      '#attributes' => array(
        'placeholder' => t('Title'),
      ),
    ));

    hide($form['override_title']);
  }

  $form += _ctools_api_content_types_base_settings_process_form($items, $form_state, $form_state['conf']);
  $form_state['#elements'] = array_keys($items);

  foreach (array('css', 'js') as $extension) {
    $form['#attached'][$extension][] = CTOOLS_API_MODULE_PATH . "/$extension/form.$extension";

    $plugin_asset = $plugin['path'] . '/' . pathinfo($plugin['file'], PATHINFO_FILENAME) . ".$extension";

    if (file_exists($plugin_asset)) {
      $form['#attached'][$extension][] = $plugin_asset;
    }
  }

  return $form;
}

/**
 * Process for field types.
 *
 * @param array $items
 *   Form items.
 * @param array $form_state
 *   Form state.
 * @param array $conf
 *   Saved data.
 *
 * @return array
 *   Processed items.
 */
function _ctools_api_content_types_base_settings_process_form(array $items, array &$form_state, array $conf) {
  static $once = array();

  $plugin = $form_state['plugin'];

  foreach ($items as $name => &$element) {
    $isset_ajax = isset($element['#ajax']);
    // Attach the file with plugin definition to the form to be
    // sure that everything will be okay on rebuilding state.
    if (empty($once['include_added']) && ($isset_ajax || in_array($element['#type'], array('managed_file')))) {
      $plugin_path = explode($plugin['module'], $plugin['path']);
      form_load_include($form_state, 'inc', $plugin['module'], trim(end($plugin_path), '/') . '/' . $plugin['name']);

      $once['include_added'] = TRUE;
    }

    if ($isset_ajax) {
      $element = array_merge_recursive($element, array(
        '#ajax' => array(
          // _ctools_api_content_types_<PLUGIN_NAME>_<ELEMENT>_ajax_callback.
          'callback' => _ctools_api_func("content_types_{$plugin['name']}_{$name}_ajax_callback"),
        ),
      ));
    }

    switch ($element['#type']) {
      case 'horizontal_tabs':
        $element = array_merge($element, array(
          '#tree' => TRUE,
          '#prefix' => '<div class="form-item horizontal-tabs" id="form-item-' . $name . '">',
          '#suffix' => '</div>',
        ));

        unset($element['#type']);
        break;

      case 'horizontal_tab':
        $element = array_merge($element, array(
          '#tree' => TRUE,
          '#type' => 'fieldset',
        ));
        break;

      case 'link_field':
        $title = '';
        $description = '';
        $titles = array(
          'url' => t('URL'),
          'title' => t('Title'),
        );

        if (!empty($element['#title'])) {
          $title = '<label>' . $element['#title'] . '</label>';
        }

        if (!empty($element['#description'])) {
          $description = '<div class="description">' . $element['#description'] . '</div>';
        }

        $element = array_merge($element, array(
          '#tree' => TRUE,
          '#prefix' => '<div class="form-item form-item-link" id="form-item-' . $name . '">' . $title . '<div class="form-link-item-wrapper">',
          '#suffix' => '</div>' . $description . '</div>',
          'title' => array(
            '#type' => 'textfield',
            '#title' => $titles['title'],
            '#attributes' => array(
              'placeholder' => $titles['title'],
            ),
          ),
          'url' => array(
            '#type' => 'textfield',
            '#title' => $titles['url'],
            '#attributes' => array(
              'placeholder' => $titles['url'],
            ),
          ),
        ));

        unset($element['#type']);
        break;

      case 'managed_file':
        if (!isset($element['#upload_location'])) {
          $element['#upload_location'] = file_default_scheme() . '://';
        }

        // Use one of file browsers.
        if (isset($element['#widget'])) {
          foreach (array(
            'imce' => array(
              '#module' => 'imce',
              // Function to determine the path of JS library.
              '#function' => array('drupal_get_path', array('module', 'imce')),
              '#subfolder' => 'js',
            ),
            'ckfinder' => array(
              '#module' => 'ckeditor',
              '#function' => array('ckfinder_path', array()),
              '#subfolder' => '',
            ),
          ) as $widget => $data) {
            if ($widget != $element['#widget']) {
              continue;
            }
            if (empty($once[$element['#type'] . ':' . $widget])) {
              if (empty($once[$widget]) && module_exists($data['#module'])) {
                list($func, $arguments) = $data['#function'];
                $once[$widget] = trim(call_user_func_array($func, $arguments), '/');
              }

              // In this case the module will not exist.
              if (empty($once[$widget])) {
                continue;
              }
              else {
                $once[$widget] .= '/' . $data['#subfolder'];
              }

              drupal_add_js(sprintf('%s/js/file.js', CTOOLS_API_MODULE_PATH));

              $element['#attached']['js'] = array(
                sprintf("%s/$widget.js", $once[$widget]),
                sprintf("%s/js/$widget.js", CTOOLS_API_MODULE_PATH),
              );

              $stream_wrapper_scheme = file_uri_scheme($element['#upload_location']);
              /* @var \DrupalLocalStreamWrapper $stream_wrapper */
              $stream_wrapper = file_stream_wrapper_get_instance_by_scheme($stream_wrapper_scheme);

              drupal_add_js(array(
                CTOOLS_API_MODULE_NAME . '_' . $widget => array(
                  'scheme' => $stream_wrapper_scheme,
                  'basePath' => DRUPAL_ROOT . '/' . $once[$widget],
                  'language' => $GLOBALS['language']->language,
                  'schemeUrl' => $stream_wrapper->getDirectoryPath(),
                ),
              ), 'setting');

              $once[$element['#type'] . ':' . $widget] = TRUE;
            }

            $element['#attributes']['class'][] = "$widget-files-browser";
          }
        }

        if (empty($once['image_module_enabled'])) {
          $once['image_module_enabled'] = module_exists('image');
        }

        if ($once['image_module_enabled']) {
          // @see _ctools_api_field_managed_file_pre_render.
          $element['#pre_render'][] = _ctools_api_func('field_' . $element['#type'] . '_pre_render');
        }
        break;
    }

    $conf_child = $conf;

    if (isset($conf[$name])) {
      $conf_child = $conf[$name];

      if (is_array($conf[$name]) && isset($conf[$name]['value'])) {
        $conf[$name] = $conf[$name]['value'];
      }

      if ('!default' !== $conf[$name]) {
        $element['#default_value'] = $conf[$name];
      }
    }

    // Make our processing recursive.
    foreach (element_children($element) as $child) {
      $data = call_user_func_array(__FUNCTION__, array(
        array($child => $element[$child]), &$form_state, $conf_child,
      ));

      $element[$child] = reset($data);
    }
  }

  return $items;
}

/**
 * Save the CTools plugin options.
 *
 * @param array $form
 *   Drupal form definition.
 * @param array $form_state
 *   Drupal form state.
 */
function _ctools_api_content_types_base_settings_form_submit(array $form, array &$form_state) {
  static $once = array();

  if (!empty($form_state['#elements'])) {
    foreach ($form_state['#elements'] as $field_name) {
      if (isset($form_state['values'][$field_name])) {
        $form_state['conf'][$field_name] = $form_state['values'][$field_name];
      }

      // Process the files.
      if (isset($form['#type'], $form['#name']) && 'managed_file' === $form['#type'] && empty($once[$form['#name']])) {
        if ($form['#value']['fid'] > 0) {
          $file = file_load($form['#value']['fid']);
          $file->status = FILE_STATUS_PERMANENT;

          file_usage_add(file_save($file), CTOOLS_API_MODULE_NAME, 'user', $GLOBALS['user']->uid);
        }

        $once[$form['#name']] = TRUE;
      }

      // Recursively call this function for sure that all field
      // will be saved correctly.
      foreach (element_children($form) as $child) {
        call_user_func_array(__FUNCTION__, array($form[$child], &$form_state));
      }
    }
  }
}

/**
 * Pre render callback for "managed_file" field type.
 *
 * @see theme_image_style()
 * @see theme_image()
 *
 * @param array $element
 *   Form element.
 *
 * @throws \Exception
 *   When theme is not initialize.
 *
 * @return array
 *   Processed form element.
 */
function _ctools_api_field_managed_file_pre_render(array $element) {
  if (empty($element['#file'])) {
    hide($element['remove_button']);
  }
  else {
    hide($element['upload']);
    hide($element['upload_button']);

    if (!file_validate_is_image($element['#file'])) {
      $info = image_get_info($element['#file']->uri);
      $variables = array(
        'alt' => $element['#file']->filename,
        'path' => $element['#file']->uri,
        'style_name' => 'thumbnail',
        'attributes' => array(
          'class' => 'upload-preview',
        ),
      );

      if (is_array($info)) {
        $variables += $info;
      }

      $element['preview'] = array(
        '#type' => 'markup',
        '#weight' => -10,
        '#markup' => theme('image_style', $variables),
      );
    }
  }

  return $element;
}
