<?php
/**
 * @file
 * Helper functions for taxonomies.
 */

/**
 * Get the whole information about "Anniversaries" taxonomy.
 *
 * @param string $vocabulary_name
 *   The machine name of taxonomy vocabulary.
 * @param bool $load_fields
 *   If TRUE, all values of attached fields will be loaded with each term.
 *
 * @return \stdClass
 *   An object with properties: "vocabulary", "terms", "names", "named".
 */
function taxonomy($vocabulary_name, $load_fields = FALSE) {
  static $taxonomy = array(), $loaded = FALSE;

  if (!$taxonomy || ($load_fields && !$loaded)) {
    $vocabulary = taxonomy_vocabulary_machine_name_load($vocabulary_name);

    if (is_object($vocabulary)) {
      $taxonomy['vocabulary'] = $vocabulary;
      $loaded = $load_fields;

      foreach (taxonomy_get_tree($vocabulary->vid, 0, NULL, $load_fields) as $i => $term) {
        $term->uri = term_uri($term);

        $taxonomy['names'][$term->tid] = $term->name;
        $taxonomy['terms'][$term->tid] = $term;
        $taxonomy['named'][$term->name] = $term;
      }
    }
  }

  return (object) $taxonomy;
}

/**
 * Get the term URI.
 *
 * @param \stdClass $term
 *   Taxonomy term.
 *
 * @return string
 *   Term URI.
 */
function term_uri(\stdClass $term) {
  $uri = taxonomy_term_uri($term);

  return url($uri['path']);
}
