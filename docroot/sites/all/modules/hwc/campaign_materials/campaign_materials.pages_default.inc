<?php
/**
 * @file
 * campaign_materials.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function campaign_materials_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'campaign_materials';
  $page->task = 'page';
  $page->admin_title = 'Campaign materials';
  $page->admin_description = 'Campaign materials';
  $page->path = 'campaign-materials';
  $page->access = array(
    'logic' => 'and',
    'type' => 'none',
    'settings' => NULL,
  );
  $page->menu = '';
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_campaign_materials__panel_context_ba8b43dd-2599-4552-b410-87d5a92d83dc';
  $handler->task = 'page';
  $handler->subtask = 'campaign_materials';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Panel Campaign Materials Page',
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
  $display->layout_settings = array(
    'items' => array(
      'canvas' => array(
        'type' => 'row',
        'contains' => 'column',
        'children' => array(
          0 => 'main',
        ),
        'parent' => NULL,
      ),
      'main' => array(
        'type' => 'column',
        'width' => 100,
        'width_type' => '%',
        'children' => array(
          0 => 'main-row',
          1 => 1,
        ),
        'parent' => 'canvas',
      ),
      'main-row' => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'introduction_section',
        ),
        'parent' => 'main',
        'class' => '',
        'hide_empty' => 1,
      ),
      1 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'campaign_materials',
        ),
        'parent' => 'main',
        'class' => '',
        'hide_empty' => 1,
      ),
      'introduction_section' => array(
        'type' => 'region',
        'title' => 'Introduction section',
        'width' => 100,
        'width_type' => '%',
        'parent' => 'main-row',
        'class' => '',
        'hide_empty' => 1,
      ),
      'campaign_materials' => array(
        'type' => 'region',
        'title' => 'Campaign materials',
        'width' => 100,
        'width_type' => '%',
        'parent' => '1',
        'class' => 'container',
        'hide_empty' => 1,
      ),
    ),
  );
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'introduction_section' => NULL,
      'campaign_materials' => NULL,
    ),
    'introduction_section' => array(
      'style' => '-1',
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '9747aef2-0f57-4a9a-815c-c8298d9a7a53';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-e3d77798-0365-4d83-be3d-db4200a072a3';
    $pane->panel = 'campaign_materials';
    $pane->type = 'views';
    $pane->subtype = 'view_campaign_materials';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_pager_settings' => 0,
      'use_pager' => 1,
      'nodes_per_page' => '10',
      'pager_id' => '0',
      'offset' => '0',
      'more_link' => 0,
      'feed_icons' => 0,
      'panel_args' => 0,
      'link_to_view' => 0,
      'args' => '',
      'url' => '',
      'display' => 'block',
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
    $pane->uuid = 'e3d77798-0365-4d83-be3d-db4200a072a3';
    $display->content['new-e3d77798-0365-4d83-be3d-db4200a072a3'] = $pane;
    $display->panels['campaign_materials'][0] = 'new-e3d77798-0365-4d83-be3d-db4200a072a3';
    $pane = new stdClass();
    $pane->pid = 'new-da09d9e5-65d7-46a5-94d0-da6f6cc3c2a7';
    $pane->panel = 'introduction_section';
    $pane->type = 'node';
    $pane->subtype = 'node';
    $pane->shown = TRUE;
    $pane->access = array(
      'plugins' => array(),
      'logic' => 'and',
    );
    $pane->configuration = array(
      'nid' => '151',
      'links' => 0,
      'leave_node_title' => 0,
      'identifier' => '',
      'build_mode' => 'body',
      'link_node_title' => 0,
      'override_title' => 1,
      'override_title_text' => '',
      'override_title_heading' => 'h3',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => '',
      'css_class' => 'section-introduction',
    );
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'da09d9e5-65d7-46a5-94d0-da6f6cc3c2a7';
    $display->content['new-da09d9e5-65d7-46a5-94d0-da6f6cc3c2a7'] = $pane;
    $display->panels['introduction_section'][0] = 'new-da09d9e5-65d7-46a5-94d0-da6f6cc3c2a7';
  $display->hide_title = PANELS_TITLE_PANE;
  $display->title_pane = 'new-da09d9e5-65d7-46a5-94d0-da6f6cc3c2a7';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['campaign_materials'] = $page;

  return $pages;

}
