<?php
/**
 * @file
 * Helper functions for views.
 */

/**
 * Execute view display.
 *
 * @param string $view_name
 *   View machine name.
 * @param string $display
 *   View display name.
 * @param int $limit
 *   Limit results.
 * @param array $args
 *   An associative array with arguments. Possible values is "uid" and "nid".
 *
 * @return \view
 *   Drupal view.
 */
function view($view_name, $display, $limit = 0, array $args = array()) {
  static $projects = array();

  $id = $args ? implode(':', array_keys($args) + array($display, $limit)) : 0;

  if (empty($projects[$id])) {
    $results = array();
    $view = views_get_view($view_name);

    $view->set_display($display);
    $view->set_items_per_page($limit);
    $view->pre_execute($args);
    $view->execute();

    foreach ($view->result as $i => $item) {
      $data = reset($item->_field_data);
      $results[] = process_entity($data['entity_type'], $data['entity']);
    }

    $projects[$id] = $results;
  }

  return $projects[$id];
}
