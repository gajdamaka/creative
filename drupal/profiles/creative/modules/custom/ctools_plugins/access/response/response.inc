<?php
/**
 * @file
 * Access by HTTP response code.
 *
 * @author Sergey Bondarenko, <broken@propeople.com.ua>
 */

$plugin = ctools_api_access(__FILE__, [
  'title' => t('HTTP Code'),
  'required context' => new \ctools_context_optional(t('Path'), 'string'),
]);

/**
 * Access plugin summary.
 */
function _ctools_api_access_response_summary_pane(array $conf, \ctools_context $context, array $plugin) {
  return t('Will be shown if HTTP status code is "!code"', [
    '!code' => $conf['code'],
  ]);
}

/**
 * Access plugin callback.
 */
function _ctools_api_access_response_check_pane(array $conf, \ctools_context $context, array $plugin) {
  $code = (int) drupal_get_http_header('Status');

  if (empty($code)) {
    drupal_goto('/', [], 301);
  }

  return $code == $conf['code'];
}

/**
 * Access plugin settings form.
 */
function _ctools_api_access_response_settings_form_pane(array &$form, array &$form_state, array $conf = array()) {
  $form['code'] = [
    '#type' => 'textfield',
    '#title' => t('Which error code should be handled?'),
    '#default_value' => 404,
  ];
}
