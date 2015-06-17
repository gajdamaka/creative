<?php
/**
 * @file
 * API for CTools access plugins.
 */

/**
 * Main function for defining the CTools API access plugin.
 *
 * @param string $path
 *   Path to file (__FILE__ constant).
 * @param array $data
 *   Additional data for plugin definition.
 *
 * @return array
 *   Updated plugin definition.
 */
function ctools_api_access($path, array $data) {
  $data['summary'] = _ctools_api_func('access_base_summary');
  $data['callback'] = _ctools_api_func('access_base_callback');
  $data['settings form'] = _ctools_api_func('access_base_settings_form');

  return $data;
}

/**
 * Base callback for output summary for access rule.
 *
 * @param array $conf
 *   Configuration options.
 * @param \ctools_context $context
 *   Visibility context.
 * @param array $plugin
 *   Plugin definition.
 *
 * @return string
 *   Access summary.
 */
function _ctools_api_access_base_summary(array $conf, \ctools_context $context, array $plugin) {
  $func = _ctools_api_callback('access', 'pane', $plugin['name'], 'summary');

  return empty($func) ? TRUE : $func($conf, $context, $plugin);
}

/**
 * Base callback for checking accessibility.
 *
 * @param array $conf
 *   Configuration options.
 * @param \ctools_context $context
 *   Visibility context.
 * @param array $plugin
 *   Plugin definition.
 *
 * @return bool
 *   Access state.
 */
function _ctools_api_access_base_callback(array $conf, \ctools_context $context, array $plugin) {
  $func = _ctools_api_callback('access', 'pane', $plugin['name'], 'check');

  return empty($func) ? TRUE : $func($conf, $context, $plugin);
}

/**
 * Base settings form for CTools access plugin.
 *
 * @param array $form
 *   Form items.
 * @param array $form_state
 *   Form state.
 * @param array $conf
 *   Configuration options.
 *
 * @return array
 *   Updated form.
 */
function _ctools_api_access_base_settings_form(array $form, array &$form_state, array $conf = array()) {
  $func = _ctools_api_callback('access', 'pane', $form_state['plugin']['name'], 'settings_form');
  $items = array();

  if (!empty($func)) {
    $func($items, $form_state, $conf);
  }

  $form['settings'] = array_merge($form['settings'], $items);

  return $form;
}
