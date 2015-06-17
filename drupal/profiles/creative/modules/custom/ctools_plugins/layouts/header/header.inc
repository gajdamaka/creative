<?php
/**
 * @file
 * Layout for the "Content" mini panel.
 */

$plugin = ctools_api_layout(__FILE__, array(
  'title' => t('Header'),
  'category' => t('Page parts'),
  'regions' => array(
    'title' => t('Site title'),
    'address' => t('Address'),
    'menu' => t('Menu'),
  ),
));
