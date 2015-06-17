<?php
/**
 * @file
 * panels_everywhere_main_layout.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_handlers().
 */
function panels_everywhere_main_layout_default_page_manager_handlers() {
  $export = array();

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'site_template__main_layout';
  $handler->task = 'site_template';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Main layout',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'name' => 'main_layout',
  );
  $display = new panels_display();
  $display->layout = 'main';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'header' => NULL,
      'main' => NULL,
      'footer' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '3854abf9-3bc9-4281-b503-8549477ccefc';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-102953c4-7655-4b05-ad6f-c3251898e7a7';
    $pane->panel = 'footer';
    $pane->type = 'panels_mini';
    $pane->subtype = 'footer';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '102953c4-7655-4b05-ad6f-c3251898e7a7';
    $display->content['new-102953c4-7655-4b05-ad6f-c3251898e7a7'] = $pane;
    $display->panels['footer'][0] = 'new-102953c4-7655-4b05-ad6f-c3251898e7a7';
    $pane = new stdClass();
    $pane->pid = 'new-8be49b04-2140-48d3-83eb-e179edcc1d50';
    $pane->panel = 'header';
    $pane->type = 'panels_mini';
    $pane->subtype = 'header';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '8be49b04-2140-48d3-83eb-e179edcc1d50';
    $display->content['new-8be49b04-2140-48d3-83eb-e179edcc1d50'] = $pane;
    $display->panels['header'][0] = 'new-8be49b04-2140-48d3-83eb-e179edcc1d50';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['site_template__main_layout'] = $handler;

  return $export;
}
