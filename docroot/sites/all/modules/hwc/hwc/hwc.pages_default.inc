<?php
/**
 * @file
 * hwc.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function hwc_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'get_your_certificate_page';
  $page->task = 'page';
  $page->admin_title = 'Get your certificate page';
  $page->admin_description = '';
  $page->path = 'get-your-certificate';
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
  $handler->name = 'page_get_your_certificate_page__panel_context_c40663c3-4cd7-4dc9-bd7d-b973c46fc933';
  $handler->task = 'page';
  $handler->subtask = 'get_your_certificate_page';
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
    'contexts' => array(
      0 => array(
        'identifier' => 'Node introduction',
        'keyword' => 'node_intro',
        'name' => 'entity:node',
        'entity_id' => '166',
        'id' => 1,
      ),
      1 => array(
        'identifier' => 'Node form',
        'keyword' => 'node_form',
        'name' => 'entity:node',
        'entity_id' => '240',
        'id' => 2,
      ),
      2 => array(
        'identifier' => 'Bottom text',
        'keyword' => 'node',
        'name' => 'entity:node',
        'entity_id' => '365',
        'id' => 3,
      ),
    ),
    'relationships' => array(),
    'panels_breadcrumbs_state' => 1,
    'panels_breadcrumbs_titles' => 'Get involved
Get your certificate of participation in the Healthy Workplaces Campaign',
    'panels_breadcrumbs_paths' => '',
    'panels_breadcrumbs_home' => 1,
  );
  $display = new panels_display();
  $display->layout = 'practical_tool_details';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'middle' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = 'Get your certificate of participation in the Healthy Workplaces Campaign';
  $display->uuid = '7094f568-dc86-496f-9cdf-6998ee08d501';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-088ac85f-2a70-41c1-943d-96254c313cb5';
    $pane->panel = 'middle';
    $pane->type = 'block';
    $pane->subtype = 'hwc-page_share_widget';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
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
    $pane->uuid = '088ac85f-2a70-41c1-943d-96254c313cb5';
    $display->content['new-088ac85f-2a70-41c1-943d-96254c313cb5'] = $pane;
    $display->panels['middle'][0] = 'new-088ac85f-2a70-41c1-943d-96254c313cb5';
    $pane = new stdClass();
    $pane->pid = 'new-f1f54bc0-e636-4d65-b40d-93b52f37ab71';
    $pane->panel = 'middle';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_image';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'hidden',
      'formatter' => 'image',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(
        'field_formatter_class' => '',
        'image_style' => 'medium_large',
        'image_link' => '',
      ),
      'context' => 'context_entity:node_1',
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
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = 'f1f54bc0-e636-4d65-b40d-93b52f37ab71';
    $display->content['new-f1f54bc0-e636-4d65-b40d-93b52f37ab71'] = $pane;
    $display->panels['middle'][1] = 'new-f1f54bc0-e636-4d65-b40d-93b52f37ab71';
    $pane = new stdClass();
    $pane->pid = 'new-776ad9ec-3f62-4e53-bd4c-47b5db890ed9';
    $pane->panel = 'middle';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:body';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'hidden',
      'formatter' => 'text_default',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(),
      'context' => 'context_entity:node_1',
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
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = '776ad9ec-3f62-4e53-bd4c-47b5db890ed9';
    $display->content['new-776ad9ec-3f62-4e53-bd4c-47b5db890ed9'] = $pane;
    $display->panels['middle'][2] = 'new-776ad9ec-3f62-4e53-bd4c-47b5db890ed9';
    $pane = new stdClass();
    $pane->pid = 'new-57b2ddd5-2735-4619-be9c-de992ec04f1e';
    $pane->panel = 'middle';
    $pane->type = 'node_content';
    $pane->subtype = 'node_content';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'links' => 0,
      'no_extras' => 0,
      'override_title' => 1,
      'override_title_text' => '',
      'identifier' => '',
      'link' => 0,
      'leave_node_title' => 0,
      'build_mode' => 'full',
      'context' => 'context_entity:node_2',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 3;
    $pane->locks = array();
    $pane->uuid = '57b2ddd5-2735-4619-be9c-de992ec04f1e';
    $display->content['new-57b2ddd5-2735-4619-be9c-de992ec04f1e'] = $pane;
    $display->panels['middle'][3] = 'new-57b2ddd5-2735-4619-be9c-de992ec04f1e';
    $pane = new stdClass();
    $pane->pid = 'new-ea2c2eaa-3113-4264-bd15-53f2e6869b18';
    $pane->panel = 'middle';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:body';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'hidden',
      'formatter' => 'text_default',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(),
      'context' => 'context_entity:node_3',
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
    $pane->position = 4;
    $pane->locks = array();
    $pane->uuid = 'ea2c2eaa-3113-4264-bd15-53f2e6869b18';
    $display->content['new-ea2c2eaa-3113-4264-bd15-53f2e6869b18'] = $pane;
    $display->panels['middle'][4] = 'new-ea2c2eaa-3113-4264-bd15-53f2e6869b18';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['get_your_certificate_page'] = $page;

  return $pages;

}
