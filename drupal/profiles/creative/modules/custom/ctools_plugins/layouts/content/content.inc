<?php
/**
 * @file
 * Layout for the "Content" mini panel.
 */

$plugin = ctools_api_layout(__FILE__, array(
  'title' => t('Content'),
  'category' => t('Pages'),
  'regions' => array(
    'content' => t('Content'),
  ),
));
