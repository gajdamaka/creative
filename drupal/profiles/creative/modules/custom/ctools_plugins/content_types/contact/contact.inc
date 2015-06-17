<?php
/**
 * @file
 * CTools "Contact" content type.
 *
 * @author Sergey Bondarenko <broken@propeople.com.ua>
 */

$plugin = ctools_api_content_type(__FILE__, array(
  'title' => t('Contact'),
  'category' => t('Page parts'),
  'top level' => TRUE,
  'theme hooks' => array(
    'default' => t('Default'),
    'minimized' => t('Minimized'),
  ),
));

/**
 * Drupal form implementation with settings for custom content type.
 */
function _ctools_api_content_types_contact_settings_form_pane(array &$form, array &$form_state) {
  foreach (array(
    'street' => t('Street'),
    'build' => t('Build'),
    'zip' => t('Zip code'),
    'city' => t('City'),
    'phone' => t('Phone'),
    'email' => t('E-mail'),
  ) as $item => $title) {
    $form[$item] = array(
      '#type' => 'textfield',
      '#title' => $title,
    );
  }
}
