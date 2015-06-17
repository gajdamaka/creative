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
    $pane->access = array(
      'plugins' => array(),
    );
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
    $pane = new stdClass();
    $pane->pid = 'new-ca42731d-1df0-4386-b021-836216d0d162';
    $pane->panel = 'main';
    $pane->type = 'page_tabs';
    $pane->subtype = 'page_tabs';
    $pane->shown = TRUE;
    $pane->access = array(
      'plugins' => array(
        0 => array(
          'name' => 'role',
          'settings' => array(
            'rids' => array(
              0 => 3,
            ),
          ),
          'context' => 'logged-in-user',
          'not' => FALSE,
        ),
      ),
    );
    $pane->configuration = array(
      'type' => 'both',
      'id' => 'tabs',
      'override_title' => 0,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => '',
      'css_class' => 'clearfix',
    );
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'ca42731d-1df0-4386-b021-836216d0d162';
    $display->content['new-ca42731d-1df0-4386-b021-836216d0d162'] = $pane;
    $display->panels['main'][0] = 'new-ca42731d-1df0-4386-b021-836216d0d162';
    $pane = new stdClass();
    $pane->pid = 'new-c67fd8d2-8653-4558-b234-9894061b89f7';
    $pane->panel = 'main';
    $pane->type = 'page_messages';
    $pane->subtype = 'page_messages';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = 'c67fd8d2-8653-4558-b234-9894061b89f7';
    $display->content['new-c67fd8d2-8653-4558-b234-9894061b89f7'] = $pane;
    $display->panels['main'][1] = 'new-c67fd8d2-8653-4558-b234-9894061b89f7';
    $pane = new stdClass();
    $pane->pid = 'new-f3c31caa-17a8-4307-a3d3-deb8734122e5';
    $pane->panel = 'main';
    $pane->type = 'page_content';
    $pane->subtype = 'page_content';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'context' => 'argument_page_content_1',
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
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = 'f3c31caa-17a8-4307-a3d3-deb8734122e5';
    $display->content['new-f3c31caa-17a8-4307-a3d3-deb8734122e5'] = $pane;
    $display->panels['main'][2] = 'new-f3c31caa-17a8-4307-a3d3-deb8734122e5';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['site_template__main_layout'] = $handler;

  return $export;
}
