<?php
/**
 * @file
 * API for Panels styles.
 */

/**
 * Panels style plugin constructor.
 *
 * @param string $file
 *   Important! "__FILE___" constant must be used.
 * @param array $data
 *   Additional definition of plugin options. Possible values:
 *   - ['title']
 *   - ['description']
 *   - ['theme hooks']
 *
 * @return array
 *   Plugin data.
 */
function ctools_api_style($file, array $data) {
  if (empty($data['renderers']) || !is_array($data['renderers'])) {
    $data['renderers'] = array('pane');
  }

  foreach ($data['renderers'] as $type) {
    $data["render $type"] = _ctools_api_prefix("base_render_$type");
    $data[('pane' == $type ? "$type " : '') . 'settings form'] = _ctools_api_func('base_settings_form');

    _ctools_api_set_plugin_theme($data, 'styles', pathinfo($file, PATHINFO_FILENAME));
  }

  return $data;
}

/**
 * Implements theme_HOOK().
 */
function theme_ctools_api_base_render_region(array $variables) {
  $plugin_name = $variables['style']['name'];
  $func = _ctools_api_callback('styles', 'region', $plugin_name, 'preprocess');

  if (!empty($func)) {
    $func($variables['display'], $variables['settings'], $variables);
  }

  return _ctools_api_apply_plugin_theme('styles__region', $plugin_name, $variables['settings']['theme'], $variables);
}

/**
 * Implements theme_HOOK().
 */
function theme_ctools_api_base_render_pane(array $variables) {
  $settings =& $variables['settings'];
  $content =& $variables['content'];

  foreach (array('title', 'content') as $wrap) {
    $option = $wrap . '_wrapper';

    if (!empty($content->$wrap)) {
      $content->$wrap = render($content->$wrap);

      if (!empty($settings[$option])) {
        $value = '<' . $settings[$option];

        if (!empty($settings[$wrap . '_classes'])) {
          $value .= ' class="' . $settings[$wrap . '_classes'] . '"';
        }

        $value .= '>';
        $value .= preg_replace('/^<.+?>|<\/.+?>(.*)/i', '$1', $content->$wrap);
        $value .= '</' . $settings[$option] . '>';

        $content->$wrap = $value;
      }
    }
  }

  // Collect the CSS settings of panel into array that can be rendered by
  // "drupal_attributes()" function.
  $content->attributes = array();

  foreach (array('class', 'id') as $prop) {
    $object_prop = "css_$prop";

    if (!empty($content->$object_prop)) {
      $content->attributes[$prop] = explode(' ', $content->$object_prop);
      unset($content->$object_prop);
    }
  }

  $content->attributes['class'][] = _ctools_api_dashes($variables['pane']->subtype);
  $func = _ctools_api_callback('styles', 'pane', $settings['theme'], 'preprocess');

  if ($func) {
    $func($content, $settings);
  }

  return _ctools_api_apply_plugin_theme('styles__pane', $variables['style']['name'], $settings['theme'], $variables);
}

/**
 * Main settings form for a style plugin.
 *
 * @param array $settings
 *   Saved, by user, settings.
 * @param \panels_display $display
 *   Panels display object.
 * @param int $pid
 *   Panel ID.
 * @param string $type
 *   The type of a panel.
 * @param array $form_state
 *   Drupal form state.
 *
 * @return array
 *   Drupal form definition.
 */
function _ctools_api_base_settings_form($settings, $display, $pid, $type, $form_state) {
  $form = array();

  $form['theme'] = array(
    '#type' => 'select',
    '#title' => t('Choose theme'),
    '#options' => $form_state['style']['theme hooks'],
    '#default_value' => $form_state['style']['name'],
  );

  if ('pane' == $form_state['type']) {
    $html_elements = array('' => t('- None -'));
    $html_elements += drupal_map_assoc(array(
      'p',
      'h1',
      'h2',
      'h3',
      'h4',
      'h5',
      'h6',
      'div',
      'nav',
      'span',
      'main',
      'figure',
      'section',
      'article',
      'figcaption',
    ));

    $form['title_wrapper'] = array(
      '#type' => 'select',
      '#title' => t('HTML element for title'),
      '#options' => $html_elements,
      '#default_value' => 'h1',
    );

    $form['title_classes'] = array(
      '#title' => t('Type the CSS classes for a title'),
    );

    $form['content_wrapper'] = array(
      '#type' => 'select',
      '#title' => t('HTML element to wrap content'),
      '#options' => $html_elements,
      '#default_value' => 'div',
    );

    $form['content_classes'] = array(
      '#title' => t('Type the CSS classes for content wrapper'),
    );
  }

  $func = _ctools_api_callback('styles', $type, $form_state['style']['name'], 'settings_form');

  if ($func) {
    $func($form, $settings, $display, $pid, $form_state);
  }

  // Process default values and field types.
  foreach ($form as $field_name => $definition) {
    if (isset($settings[$field_name])) {
      $form[$field_name]['#default_value'] = $settings[$field_name];
    }

    if (!isset($definition['#type'])) {
      $form[$field_name]['#type'] = 'textfield';
    }
  }

  return $form;
}
