<?php
/**
 * @file
 * Theme functions and callbacks.
 */

/**
 * Relative path to theme.
 */
define('CREATIVE_THEME_PATH', $GLOBALS['theme_path']);

/**
 * Implements hook_html_head_alter().
 */
function creative_html_head_alter(array &$head_elements) {
  $head_elements['system_meta_content_type']['#attributes'] = array(
    'charset' => 'utf-8',
  );

  if (isset($head_elements['system_meta_generator'])) {
    unset($head_elements['system_meta_generator']);
  }
}

/**
 * Implements hook_css_alter().
 */
function creative_css_alter(array &$css) {
  $css = array_diff_key($css, array(
    'modules/system/system.theme.css' => FALSE,
    'modules/system/system.menus.css' => FALSE,
  ));
}

/**
 * Implements hook_preprocess().
 *
 * @uses _creative_include_layout_additional_assets()
 */
function creative_preprocess(array &$variables, $hook) {
  if (isset($variables['page']['#handler'])) {
    $variables['classes_array'] = array_merge($variables['classes_array'], explode(' ', $variables['page']['#handler']->conf['body_classes_to_add']));

    drupal_add_js('http://html5shiv.googlecode.com/svn/trunk/html5.js', ['type' => 'external']);
  }

  if (!empty($variables['layout']) && is_array($variables['layout'])) {
    $layout = $variables['layout'];
    $layout_name = $layout['name'];
    // Load assets, if they are exist, from:
    // <THEME_PATH>/css/includes/<LAYOUT_NAME>.css
    // <THEME_PATH>/js/includes/<LAYOUT_NAME>.js
    _creative_include_layout_additional_assets($layout_name);

    // If authorized user has an administration permissions, then, for
    // it, can be loaded additional assets:
    // <THEME_PATH>/css/includes/<LAYOUT_NAME>-admin.css
    // <THEME_PATH>/js/includes/<LAYOUT_NAME>-admin.js
    if ($variables['is_admin']) {
      _creative_include_layout_additional_assets("$layout_name-admin");
    }

    // The values of "libraries" array must consist of arrays with
    // arguments which will be passed into "drupal_add_library" function.
    //
    // @code
    // 'libraries' => array(
    //   // System library.
    //   array('system', 'ui.draggable'),
    //   // Library defined by "Libraries" module.
    //   array('swiper'),
    // );
    // @endcode
    if (!empty($layout['libraries'])) {
      foreach ($layout['libraries'] as $arguments) {
        if (!empty($arguments) && is_array($arguments)) {
          foreach (array('libraries_load', 'drupal_add_library') as $func) {
            if (call_user_func_array($func, $arguments)) {
              break;
            }
          }
        }
      }
    }
  }
}

/**
 * Implements hook_theme_registry_alter().
 */
function creative_theme_registry_alter(&$theme_registry) {
  foreach (array('panels_flexible') as $hook) {
    if (isset($theme_registry[$hook])) {
      $theme_registry[$hook]['function'] = "_parallel_$hook";
    }
  }
}

/**
 * Implements hook_panels_default_style_render_region().
 */
function creative_panels_default_style_render_region(array $variables) {
  // Remove all <div class="panel-separator"></div> blocks.
  return implode('', $variables['panes']);
}

/**
 * Implements template_preprocess_views_view().
 */
function creative_preprocess_views_view(array &$variables) {
  /* @var \view $variables['view'] */
  $variables['title'] = $variables['view']->get_title();
}

/**
 * Load additional assets (CSS or/and JS) for the panels layout.
 *
 * @param string $file_name
 *   File name without extension.
 */
function _creative_include_layout_additional_assets($file_name) {
  foreach (array('css', 'js') as $type) {
    $file_relative_path = CREATIVE_THEME_PATH . "/$type/includes/$file_name.$type";

    if (file_exists(DRUPAL_ROOT . '/' . $file_relative_path)) {
      call_user_func("drupal_add_$type", $file_relative_path, array(
        'group' => constant(strtoupper($type) . '_THEME'),
      ));
    }
  }
}

/**
 * Override for "theme_panels_flexible".
 *
 * @param array $variables
 *   An array of variables to preprocess.
 *
 * @return string
 *   HTML markup.
 */
function _creative_panels_flexible(array $variables) {
  $output = '';

  foreach ($variables['content'] as $region_name => $content) {
    if (!empty($variables['settings']['items'])) {
      $item = $variables['settings']['items'][$region_name];
      $content = '<section role="region" class="' . $item['class'] . '">' . $content . '</section>';
    }

    $output .= $content;
  }

  return $output;
}
