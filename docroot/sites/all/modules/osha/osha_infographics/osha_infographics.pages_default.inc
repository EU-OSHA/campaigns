<?php
/**
 * @file
 * osha_infographics.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function osha_infographics_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'infographics_list';
  $page->task = 'page';
  $page->admin_title = 'Infographics list';
  $page->admin_description = '';
  $page->path = 'infographics';
  $page->access = array(
    'type' => 'none',
    'settings' => NULL,
  );
  $page->menu = array();
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_infographics_list__panel_context_9a4de1d9-78ec-49c0-b757-48e4ee6f93e0';
  $handler->task = 'page';
  $handler->subtask = 'infographics_list';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Panel',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
  );
  $display = new panels_display();
  $display->layout = 'flexible';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'center' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '757fb462-3de9-449b-bbc4-c78a42c80341';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_infographics_list__panel_context_9a4de1d9-78ec-49c0-b757-48e4ee6f93e0';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-07dfbacc-4221-4fcf-acfe-edfa3b7364a1';
  $pane->panel = 'center';
  $pane->type = 'node';
  $pane->subtype = 'node';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'nid' => '114',
    'links' => 1,
    'leave_node_title' => 0,
    'identifier' => '',
    'build_mode' => 'body',
    'link_node_title' => 0,
    'override_title' => 1,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array(
    'css_id' => '',
    'css_class' => 'section-intorduction',
  );
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '07dfbacc-4221-4fcf-acfe-edfa3b7364a1';
  $display->content['new-07dfbacc-4221-4fcf-acfe-edfa3b7364a1'] = $pane;
  $display->panels['center'][0] = 'new-07dfbacc-4221-4fcf-acfe-edfa3b7364a1';
  $pane = new stdClass();
  $pane->pid = 'new-ae158bb9-a592-4348-945c-df0a1ed0b3ec';
  $pane->panel = 'center';
  $pane->type = 'views';
  $pane->subtype = 'infographic';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_pager_settings' => 0,
    'use_pager' => 0,
    'nodes_per_page' => '0',
    'pager_id' => '0',
    'offset' => '0',
    'more_link' => 0,
    'feed_icons' => 0,
    'panel_args' => 0,
    'link_to_view' => 0,
    'args' => '',
    'url' => '',
    'display' => 'block_1',
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
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = 'ae158bb9-a592-4348-945c-df0a1ed0b3ec';
  $display->content['new-ae158bb9-a592-4348-945c-df0a1ed0b3ec'] = $pane;
  $display->panels['center'][1] = 'new-ae158bb9-a592-4348-945c-df0a1ed0b3ec';
  $display->hide_title = PANELS_TITLE_PANE;
  $display->title_pane = 'new-07dfbacc-4221-4fcf-acfe-edfa3b7364a1';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['infographics_list'] = $page;

  return $pages;

}
