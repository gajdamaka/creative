<?php
/**
 * @file
 * CTools content type for node output.
 *
 * @author Sergey Bondarenko <broken@propeople.com.ua>
 */

$plugin = ctools_api_content_type(__FILE__, array(
  'title' => t('Node'),
  'category' => t('Node'),
  'required context' => new \ctools_context_required(t('Node'), 'node'),
  'theme hooks' => _ctools_api_content_types_node_get_types(),
));

/**
 * CTools custom content type render callback.
 */
function _ctools_api_content_types_node_preprocess_pane(array &$variables, array &$arguments, \ctools_context $context = NULL) {
  $variables['node'] = array();
}

/**
 * Get node subtypes.
 *
 * @return array
 *   An array with machine name as key and human name as a value.
 */
function _ctools_api_content_types_node_get_types() {
  $content_types = array();

  foreach (node_type_get_types() as $type => $definition) {
    $content_types[$type] = $definition->name;
  }

  return $content_types;
}
