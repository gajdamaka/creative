<?php
/**
 * @file
 * Layout for the "Footer" mini panel.
 */

$plugin = ctools_api_layout(__FILE__, array(
  'title' => t('Footer'),
  'category' => t('Page parts'),
  'regions' => array(
    'copyright' => t('Copyright'),
  ),
));
