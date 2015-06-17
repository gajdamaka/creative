<?php
/**
 * @file
 * mini_panels_footer.panels_default.inc
 */

/**
 * Implements hook_default_panels_mini().
 */
function mini_panels_footer_default_panels_mini() {
  $export = array();

  $mini = new stdClass();
  $mini->disabled = FALSE; /* Edit this to true to make a default mini disabled initially */
  $mini->api_version = 1;
  $mini->name = 'footer';
  $mini->category = 'Page parts';
  $mini->admin_title = 'Footer';
  $mini->admin_description = '';
  $mini->requiredcontexts = array();
  $mini->contexts = array();
  $mini->relationships = array();
  $display = new panels_display();
  $display->layout = 'footer';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'copyright' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = 'Footer';
  $display->uuid = '73940172-a8fc-462d-815a-17ef2c1259fd';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-1090eb03-c6fa-4abd-bcf3-6245bb594387';
    $pane->panel = 'copyright';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => '',
      'title' => 'Copyright',
      'body' => 'Copyright © Gaydamaka Website 2015',
      'format' => 'plain_text',
      'substitute' => TRUE,
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '1090eb03-c6fa-4abd-bcf3-6245bb594387';
    $display->content['new-1090eb03-c6fa-4abd-bcf3-6245bb594387'] = $pane;
    $display->panels['copyright'][0] = 'new-1090eb03-c6fa-4abd-bcf3-6245bb594387';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-1090eb03-c6fa-4abd-bcf3-6245bb594387';
  $mini->display = $display;
  $export['footer'] = $mini;

  return $export;
}
