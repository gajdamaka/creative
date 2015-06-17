<?php
/**
 * @file
 * CTools content type for output taxonomy terms.
 *
 * @author Sergey Bondarenko <broken@propeople.com.ua>
 */

$plugin = ctools_api_content_type(__FILE__, array(
  'title' => t('Terms'),
  'category' => t('Taxonomy term'),
  'theme hooks' => _ctools_api_content_types_taxonomy_get_types(),
));

/**
 * CTools custom content type render callback.
 */
function _ctools_api_content_types_taxonomy_preprocess_pane(array &$variables, array &$arguments, \ctools_context $context = NULL) {
  $variables['terms'] = array();
  $taxonomy = taxonomy($variables['theme']);

  if (is_object($taxonomy) && !empty($taxonomy->terms)) {
    $variables['terms'] = $taxonomy->terms;
  }
}

/**
 * Get taxonomy vocabularies.
 *
 * @return array
 *   An array with machine name as key and human name as a value.
 */
function _ctools_api_content_types_taxonomy_get_types() {
  $types = array();

  foreach (taxonomy_get_vocabularies() as $vocabulary) {
    $types[$vocabulary->machine_name] = $vocabulary->name;
  }

  return $types;
}
