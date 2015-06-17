<?php
/**
 * @file
 * API for Panels layouts.
 */

/**
 * Panels layout plugin constructor.
 *
 * @param string $file
 *   Path to plugin file. The "__FILE__" constant should be used.
 * @param array $data
 *   Additional data for plugin definition.
 *
 * @return array
 *   Updated plugin definition.
 */
function ctools_api_layout($file, array $data) {
  $data['theme'] = $data['icon'] = $data['css'] = _ctools_api_dashes(pathinfo($file, PATHINFO_FILENAME));
  $data['icon'] .= '.png';
  $data['css'] .= '.css';

  return $data;
}
