<?php
/**
 * @file
 * Helper functions for entities.
 */

/**
 * Return values of entity properties.
 *
 * @param string $entity_type
 *   The machine name of entity.
 * @param object $entity
 *   Entity object.
 *
 * @return array
 *   Processed entity object.
 */
function process_entity($entity_type, $entity) {
  $fields = array();

  /* @var \EntityValueWrapper $data */
  foreach (entity_metadata_wrapper($entity_type, $entity) as $item => $data) {
    $fields[str_replace('field_', '', $item)] = $data->value();
  }

  return $fields;
}
