<?php
/**
 * @file
 * panels_everywhere_main_layout.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function panels_everywhere_main_layout_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}
