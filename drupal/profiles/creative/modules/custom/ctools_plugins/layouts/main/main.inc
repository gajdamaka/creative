<?php
/**
 * @file
 * Layout for the "Main" panel.
 */

$plugin = ctools_api_layout(__FILE__, array(
  'title' => t('Main'),
  'category' => t('Panels Everywhere'),
  'regions' => array(
    'header' => t('Header'),
    'main' => t('Content'),
    'footer' => t('footer'),
  ),
));
