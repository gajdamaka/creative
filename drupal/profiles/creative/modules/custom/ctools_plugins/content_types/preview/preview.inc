<?php
/**
 * @file
 * CTools "Preview" content type.
 *
 * @author Sergey Bondarenko <broken@propeople.com.ua>
 */

$plugin = ctools_api_content_type(__FILE__, array(
  'title' => t('Preview'),
  'category' => t('Page parts'),
  'top level' => TRUE,
  'required context' => new \ctools_context_optional(t('Node'), 'node'),
  'theme hooks' => array(
    'slider' => t('Slider'),
  ),
));

/**
 * CTools custom content type render callback.
 */
function _ctools_api_content_types_preview_preprocess_pane(array &$variables, array &$arguments, \ctools_context $context = NULL) {
  if (!empty($context->data)) {
    $node = process_entity($context->keyword, $context->data);

    $variables['override_title_text'] = $context->title;
    $variables['image'] = '';

    if (!empty($node[$variables['image_field']])) {
      $media = $node[$variables['image_field']];

      if (isset($media['fid'])) {
        $variables['image'] = $media;
      }
    }
  }
}

/**
 * Drupal form implementation with settings for custom content type.
 */
function _ctools_api_content_types_preview_settings_form_pane(array &$form, array &$form_state) {
  $form['image'] = array(
    '#type' => 'managed_file',
    '#title' => t('Image'),
    '#widget' => 'imce',
  );

  $options = array();

  foreach (field_info_instances('node') as $content_type => $fields) {
    $options[$content_type] = array();

    foreach ($fields as $field_name => $definition) {
      $options[$content_type][str_replace('field_', '', $field_name)] = "{$definition['label']} ($field_name)";
    }
  }

  $form['image_field'] = array(
    '#type' => 'select',
    '#title' => t('Choose the field with image from context'),
    '#options' => $options,
    '#empty_option' => t('- None -'),
    '#default_value' => '',
  );
}
