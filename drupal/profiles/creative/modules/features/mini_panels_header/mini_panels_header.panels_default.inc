<?php
/**
 * @file
 * mini_panels_header.panels_default.inc
 */

/**
 * Implements hook_default_panels_mini().
 */
function mini_panels_header_default_panels_mini() {
  $export = array();

  $mini = new stdClass();
  $mini->disabled = FALSE; /* Edit this to true to make a default mini disabled initially */
  $mini->api_version = 1;
  $mini->name = 'header';
  $mini->category = 'Page parts';
  $mini->admin_title = 'Header';
  $mini->admin_description = '';
  $mini->requiredcontexts = array();
  $mini->contexts = array();
  $mini->relationships = array();
  $display = new panels_display();
  $display->layout = 'header';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'title' => NULL,
      'address' => NULL,
      'menu' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '91d0f541-5aaa-4852-9324-f3d9cea6714a';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-fc415b1d-36ca-48e1-afe3-4bba20be78ac';
    $pane->panel = 'address';
    $pane->type = 'contact';
    $pane->subtype = 'contact';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'theme' => 'minimized',
      'street' => 'Pushkin',
      'build' => '11 A',
      'zip' => '49900',
      'city' => 'Dnepropetrowsk',
      'phone' => '+38 099 53 06',
      'email' => 'gaydamaka.vov@gmail.com',
      'override_title' => 0,
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
    $pane->uuid = 'fc415b1d-36ca-48e1-afe3-4bba20be78ac';
    $display->content['new-fc415b1d-36ca-48e1-afe3-4bba20be78ac'] = $pane;
    $display->panels['address'][0] = 'new-fc415b1d-36ca-48e1-afe3-4bba20be78ac';
    $pane = new stdClass();
    $pane->pid = 'new-80301ae4-9043-4fe1-9e11-85812d522cc1';
    $pane->panel = 'menu';
    $pane->type = 'block';
    $pane->subtype = 'system-main-menu';
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
    $pane->uuid = '80301ae4-9043-4fe1-9e11-85812d522cc1';
    $display->content['new-80301ae4-9043-4fe1-9e11-85812d522cc1'] = $pane;
    $display->panels['menu'][0] = 'new-80301ae4-9043-4fe1-9e11-85812d522cc1';
    $pane = new stdClass();
    $pane->pid = 'new-87723c03-afeb-4831-909e-ba0828a50440';
    $pane->panel = 'title';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => 'Site title',
      'title' => '',
      'body' => 'Propeople (SLA)',
      'format' => 'plain_text',
      'substitute' => TRUE,
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => '',
      'css_class' => 'site-title',
    );
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '87723c03-afeb-4831-909e-ba0828a50440';
    $display->content['new-87723c03-afeb-4831-909e-ba0828a50440'] = $pane;
    $display->panels['title'][0] = 'new-87723c03-afeb-4831-909e-ba0828a50440';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-87723c03-afeb-4831-909e-ba0828a50440';
  $mini->display = $display;
  $export['header'] = $mini;

  return $export;
}
