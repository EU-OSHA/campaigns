<?php
/**
 * @file
 * osha_newsletter.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_handlers().
 */
function osha_newsletter_default_page_manager_handlers() {
  $export = array();

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_view__panel_context_e5608b83-de87-4dc2-b38d-a924687f8249';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = 5;
  $handler->conf = array(
    'title' => 'Newsletter custom page',
    'no_blocks' => 1,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(
      0 => array(
        'identifier' => 'Content: ID',
        'keyword' => 'node_nid',
        'name' => 'entity:node',
        'entity_id' => '129',
        'id' => 1,
      ),
    ),
    'relationships' => array(),
    'name' => '',
    'access' => array(
      'logic' => 'and',
      'plugins' => array(
        0 => array(
          'name' => 'path_visibility',
          'settings' => array(
            'visibility_setting' => '1',
            'paths' => 'node/129',
          ),
          'context' => 'empty',
          'not' => FALSE,
        ),
      ),
    ),
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
          0 => 1,
          1 => 'main-row',
        ),
        'parent' => 'canvas',
      ),
      'main-row' => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'center',
          1 => 'left',
        ),
        'parent' => 'main',
      ),
      'center' => array(
        'type' => 'region',
        'title' => 'left',
        'width' => 50,
        'width_type' => '%',
        'parent' => 'main-row',
        'class' => 'col-md-6',
        'hide_empty' => 1,
      ),
      'left' => array(
        'type' => 'region',
        'title' => 'right',
        'width' => 50,
        'width_type' => '%',
        'parent' => 'main-row',
        'class' => 'col-md-6',
        'hide_empty' => 1,
      ),
      1 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'title',
        ),
        'parent' => 'main',
        'class' => '',
        'hide_empty' => 1,
      ),
      'title' => array(
        'type' => 'region',
        'title' => 'title',
        'width' => 100,
        'width_type' => '%',
        'parent' => '1',
        'class' => 'col-md-12',
        'hide_empty' => 1,
      ),
    ),
  );
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'center' => NULL,
      'left' => NULL,
      'title' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '%node:title_field';
  $display->uuid = 'adc7b505-859a-4f9b-b4c8-d4521309bbbe';
  $display->storage_type = 'unknown';
  $display->storage_id = '';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-6d2d9e1e-9d24-49fb-a150-f65f9a820d65';
  $pane->panel = 'center';
  $pane->type = 'block';
  $pane->subtype = 'osha_newsletter-osha_newsletter_subscribe_extra';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 1,
    'override_title_text' => '%title',
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
  $pane->uuid = '6d2d9e1e-9d24-49fb-a150-f65f9a820d65';
  $display->content['new-6d2d9e1e-9d24-49fb-a150-f65f9a820d65'] = $pane;
  $display->panels['center'][0] = 'new-6d2d9e1e-9d24-49fb-a150-f65f9a820d65';
  $pane = new stdClass();
  $pane->pid = 'new-2222cba6-cbc9-482c-b9aa-11c6e7aaee39';
  $pane->panel = 'left';
  $pane->type = 'block';
  $pane->subtype = 'osha_newsletter-osha_newsletter_latest';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 1,
    'override_title_text' => '%title',
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
  $pane->uuid = '2222cba6-cbc9-482c-b9aa-11c6e7aaee39';
  $display->content['new-2222cba6-cbc9-482c-b9aa-11c6e7aaee39'] = $pane;
  $display->panels['left'][0] = 'new-2222cba6-cbc9-482c-b9aa-11c6e7aaee39';
  $pane = new stdClass();
  $pane->pid = 'new-3f7319cc-a101-49fb-92e0-e71fa38ab8b3';
  $pane->panel = 'title';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:title_field';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'hidden',
    'formatter' => 'title_linked',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(
      'title_style' => 'h1',
      'title_link' => '',
      'title_class' => '',
      'field_formatter_class' => '',
    ),
    'context' => 'argument_entity_id:node_1',
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
  $pane->uuid = '3f7319cc-a101-49fb-92e0-e71fa38ab8b3';
  $display->content['new-3f7319cc-a101-49fb-92e0-e71fa38ab8b3'] = $pane;
  $display->panels['title'][0] = 'new-3f7319cc-a101-49fb-92e0-e71fa38ab8b3';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['node_view__panel_context_e5608b83-de87-4dc2-b38d-a924687f8249'] = $handler;

  return $export;
}
