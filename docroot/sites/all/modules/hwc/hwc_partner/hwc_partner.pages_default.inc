<?php
/**
 * @file
 * hwc_partner.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_handlers().
 */
function hwc_partner_default_page_manager_handlers() {
  $export = array();

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_view__fop';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = 3;
  $handler->conf = array(
    'title' => 'FOP profile',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'partner' => 'partner',
            ),
          ),
          'context' => 'argument_entity_id:node_1',
          'not' => FALSE,
        ),
        1 => array(
          'name' => 'entity_field_value:node:partner:field_partner_type',
          'settings' => array(
            'field_partner_type' => array(
              'und' => array(
                0 => array(
                  'tid' => '187',
                ),
              ),
            ),
            'field_partner_type_tid' => array(
              0 => '187',
            ),
          ),
          'context' => 'argument_entity_id:node_1',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
    'name' => 'fop',
    'panels_breadcrumbs_state' => 1,
    'panels_breadcrumbs_titles' => 'Campaign partners
National focal points
%node:title-field',
    'panels_breadcrumbs_paths' => '<none>
national-focal-points
<none>',
    'panels_breadcrumbs_home' => 1,
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
          0 => 6,
          1 => 5,
          2 => 4,
          3 => 1,
          4 => 2,
          5 => 3,
        ),
        'parent' => 'canvas',
      ),
      1 => array(
        'type' => 'row',
        'contains' => 'column',
        'children' => array(
          0 => 20,
          1 => 21,
        ),
        'parent' => 'main',
        'class' => 'container profile-2-cols-container-1',
        'hide_empty' => 0,
      ),
      2 => array(
        'type' => 'row',
        'contains' => 'column',
        'children' => array(
          0 => 7,
          1 => 8,
          2 => 9,
        ),
        'parent' => 'main',
        'class' => 'container profile-4-cols-container-2',
        'hide_empty' => 0,
      ),
      3 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'left__',
          1 => 'right__',
        ),
        'parent' => 'main',
        'class' => 'container profile-2-cols-container-3',
        'hide_empty' => 0,
      ),
      'left__' => array(
        'type' => 'region',
        'title' => 'Left',
        'width' => '25.091027461588755',
        'width_type' => '%',
        'parent' => '3',
        'class' => 'col-sm-6 profile-col-left-3',
        'hide_empty' => 0,
      ),
      'right__' => array(
        'type' => 'region',
        'title' => 'Right',
        'width' => '24.908972538411245',
        'width_type' => '%',
        'parent' => '3',
        'class' => 'col-sm-6 profile-col-right-3',
        'hide_empty' => 0,
      ),
      4 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'center_',
        ),
        'parent' => 'main',
        'class' => 'container profile-title-type-container',
        'hide_empty' => 0,
      ),
      'center_' => array(
        'type' => 'region',
        'title' => 'Center',
        'width' => 100,
        'width_type' => '%',
        'parent' => '4',
        'class' => 'col-md-12',
        'hide_empty' => 0,
      ),
      5 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'center__',
        ),
        'parent' => 'main',
        'class' => '',
        'hide_empty' => 0,
      ),
      'center__' => array(
        'type' => 'region',
        'title' => 'Center',
        'width' => 100,
        'width_type' => '%',
        'parent' => '5',
        'class' => '',
        'hide_empty' => 0,
      ),
      6 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'my_title',
        ),
        'parent' => 'main',
        'class' => 'profile-edit-links-container',
        'hide_empty' => 0,
      ),
      'my_title' => array(
        'type' => 'region',
        'title' => 'Center',
        'width' => 100,
        'width_type' => '%',
        'parent' => '6',
        'class' => '',
        'hide_empty' => 0,
      ),
      7 => array(
        'type' => 'column',
        'width' => 50,
        'width_type' => '%',
        'parent' => '2',
        'children' => array(
          0 => 10,
        ),
        'class' => '',
        'hide_empty' => 0,
      ),
      8 => array(
        'type' => 'column',
        'width' => 25,
        'width_type' => '%',
        'parent' => '2',
        'children' => array(
          0 => 11,
        ),
        'class' => '',
        'hide_empty' => 0,
      ),
      9 => array(
        'type' => 'column',
        'width' => 25,
        'width_type' => '%',
        'parent' => '2',
        'children' => array(
          0 => 12,
        ),
        'class' => '',
        'hide_empty' => 1,
      ),
      10 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'region_left',
          1 => 'middle_left',
        ),
        'parent' => '7',
        'class' => '',
        'hide_empty' => 0,
      ),
      11 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'middle_right',
        ),
        'parent' => '8',
        'class' => '',
        'hide_empty' => 0,
      ),
      12 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'right_',
        ),
        'parent' => '9',
        'class' => '',
        'hide_empty' => 1,
      ),
      'region_left' => array(
        'type' => 'region',
        'title' => 'Left',
        'width' => 50,
        'width_type' => '%',
        'parent' => '10',
        'class' => 'col-sm-4 profile-col-left-middle-2',
        'hide_empty' => 0,
      ),
      'middle_left' => array(
        'type' => 'region',
        'title' => 'Middle left',
        'width' => 50,
        'width_type' => '%',
        'parent' => '10',
        'class' => 'col-sm-4 profile-col-left-middle-2',
        'hide_empty' => 0,
      ),
      'middle_right' => array(
        'type' => 'region',
        'title' => 'Middle right',
        'width' => 100,
        'width_type' => '%',
        'parent' => '11',
        'class' => 'col-sm-4 profile-col-left-middle-2',
        'hide_empty' => 0,
      ),
      'right_' => array(
        'type' => 'region',
        'title' => 'Right',
        'width' => 100,
        'width_type' => '%',
        'parent' => '12',
        'class' => 'col-sm-4 profile-col-left-middle-2',
        'hide_empty' => 1,
      ),
      20 => array(
        'type' => 'column',
        'width' => '16.928164897708047',
        'width_type' => '%',
        'parent' => '1',
        'children' => array(
          0 => 22,
        ),
        'class' => 'col-sm-2',
        'hide_empty' => 0,
      ),
      21 => array(
        'type' => 'column',
        'width' => '83.07183510229196',
        'width_type' => '%',
        'parent' => '1',
        'children' => array(
          0 => 23,
          1 => 24,
        ),
        'class' => 'col-sm-10 profile-col-left-1',
        'hide_empty' => 0,
      ),
      22 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'logo',
        ),
        'parent' => '20',
        'class' => '',
        'hide_empty' => 0,
      ),
      'logo' => array(
        'type' => 'region',
        'title' => 'Logo',
        'width' => 100,
        'width_type' => '%',
        'parent' => '22',
        'class' => '',
        'hide_empty' => 0,
      ),
      23 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'title_',
        ),
        'parent' => '21',
        'class' => '',
        'hide_empty' => 0,
      ),
      24 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'statement_',
        ),
        'parent' => '21',
        'class' => '',
        'hide_empty' => 0,
      ),
      'title_' => array(
        'type' => 'region',
        'title' => 'Title',
        'width' => 100,
        'width_type' => '%',
        'parent' => '23',
        'class' => '',
        'hide_empty' => 0,
      ),
      'statement_' => array(
        'type' => 'region',
        'title' => 'Statement',
        'width' => 100,
        'width_type' => '%',
        'parent' => '24',
        'class' => '',
        'hide_empty' => 0,
      ),
    ),
  );
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'center' => NULL,
      'left' => NULL,
      'right' => NULL,
      'left_' => NULL,
      'right_' => NULL,
      'left__' => NULL,
      'right__' => NULL,
      'center_' => NULL,
      'center__' => NULL,
      'left___' => NULL,
      'right___' => NULL,
      'my_title' => NULL,
      'logo' => NULL,
      'region_left' => NULL,
      'middle_left' => NULL,
      'middle_right' => NULL,
      'logo_' => NULL,
      'title' => NULL,
      'statement' => NULL,
      'title_' => NULL,
      'statement_' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '%node:title-field';
  $display->uuid = '536f07b4-59cc-4e7d-84b4-3635ebb5aa94';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'node_view__fop';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-21193c9b-bdf0-46b9-8120-f1d3781f045d';
  $pane->panel = 'center_';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:title_field';
  $pane->shown = TRUE;
  $pane->access = array(
    'plugins' => array(),
  );
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
  $pane->uuid = '21193c9b-bdf0-46b9-8120-f1d3781f045d';
  $display->content['new-21193c9b-bdf0-46b9-8120-f1d3781f045d'] = $pane;
  $display->panels['center_'][0] = 'new-21193c9b-bdf0-46b9-8120-f1d3781f045d';
  $pane = new stdClass();
  $pane->pid = 'new-e6de6658-e548-4fac-affe-129b4f289bb8';
  $pane->panel = 'center_';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_abbreviation_name';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'hidden',
    'formatter' => 'text_plain',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(),
    'context' => 'argument_entity_id:node_1',
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
    'css_class' => 'profile-inline-field',
  );
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = 'e6de6658-e548-4fac-affe-129b4f289bb8';
  $display->content['new-e6de6658-e548-4fac-affe-129b4f289bb8'] = $pane;
  $display->panels['center_'][1] = 'new-e6de6658-e548-4fac-affe-129b4f289bb8';
  $pane = new stdClass();
  $pane->pid = 'new-2f8ed0d0-aabd-40cc-8d5f-2dcd30d81957';
  $pane->panel = 'center_';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_orgtype';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'hidden',
    'formatter' => 'i18n_taxonomy_term_reference_plain',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(
      'title_style' => '_none',
      'title_link' => '',
      'title_class' => '',
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
  $pane->css = array(
    'css_id' => '',
    'css_class' => 'profile-inline-field',
  );
  $pane->extras = array();
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = '2f8ed0d0-aabd-40cc-8d5f-2dcd30d81957';
  $display->content['new-2f8ed0d0-aabd-40cc-8d5f-2dcd30d81957'] = $pane;
  $display->panels['center_'][2] = 'new-2f8ed0d0-aabd-40cc-8d5f-2dcd30d81957';
  $pane = new stdClass();
  $pane->pid = 'new-91027b2b-a9f8-4c30-84cf-608524bd44cd';
  $pane->panel = 'center_';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_bussines_sector';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'hidden',
    'formatter' => 'i18n_taxonomy_term_reference_plain',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(
      'title_style' => '_none',
      'title_link' => '',
      'title_class' => '',
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
  $pane->css = array(
    'css_id' => '',
    'css_class' => 'profile-inline-field',
  );
  $pane->extras = array();
  $pane->position = 3;
  $pane->locks = array();
  $pane->uuid = '91027b2b-a9f8-4c30-84cf-608524bd44cd';
  $display->content['new-91027b2b-a9f8-4c30-84cf-608524bd44cd'] = $pane;
  $display->panels['center_'][3] = 'new-91027b2b-a9f8-4c30-84cf-608524bd44cd';
  $pane = new stdClass();
  $pane->pid = 'new-2c5384eb-8241-4cbf-a6b5-aeb3a1a40523';
  $pane->panel = 'center_';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_website';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'hidden',
    'formatter' => 'link_default',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(),
    'context' => 'argument_entity_id:node_1',
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
    'css_class' => 'profile-inline-field',
  );
  $pane->extras = array();
  $pane->position = 4;
  $pane->locks = array();
  $pane->uuid = '2c5384eb-8241-4cbf-a6b5-aeb3a1a40523';
  $display->content['new-2c5384eb-8241-4cbf-a6b5-aeb3a1a40523'] = $pane;
  $display->panels['center_'][4] = 'new-2c5384eb-8241-4cbf-a6b5-aeb3a1a40523';
  $pane = new stdClass();
  $pane->pid = 'new-01df3ff6-7648-4eb2-a42a-6d35973b8301';
  $pane->panel = 'center__';
  $pane->type = 'block';
  $pane->subtype = 'hwc_partner-hwc_partner_profile_title';
  $pane->shown = TRUE;
  $pane->access = array(
    'plugins' => array(
      0 => array(
        'name' => 'php',
        'settings' => array(
          'description' => 'Page belongs to partner',
          'php' => '$node=menu_get_object(); return hwc_partner_match_user_partner($node);',
        ),
        'not' => FALSE,
      ),
    ),
  );
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
  $pane->uuid = '01df3ff6-7648-4eb2-a42a-6d35973b8301';
  $display->content['new-01df3ff6-7648-4eb2-a42a-6d35973b8301'] = $pane;
  $display->panels['center__'][0] = 'new-01df3ff6-7648-4eb2-a42a-6d35973b8301';
  $pane = new stdClass();
  $pane->pid = 'new-58094813-4281-4753-b1e0-5e58a26999fb';
  $pane->panel = 'left__';
  $pane->type = 'views';
  $pane->subtype = 'partner_content';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_pager_settings' => 0,
    'use_pager' => 0,
    'nodes_per_page' => '4',
    'pager_id' => '0',
    'offset' => '0',
    'more_link' => 0,
    'feed_icons' => 0,
    'panel_args' => 0,
    'link_to_view' => 0,
    'args' => '',
    'url' => '',
    'display' => 'latest_partner_news',
    'context' => array(
      0 => '',
    ),
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
  $pane->uuid = '58094813-4281-4753-b1e0-5e58a26999fb';
  $display->content['new-58094813-4281-4753-b1e0-5e58a26999fb'] = $pane;
  $display->panels['left__'][0] = 'new-58094813-4281-4753-b1e0-5e58a26999fb';
  $pane = new stdClass();
  $pane->pid = 'new-f2daadd7-42ac-4875-a417-a568b0cdb545';
  $pane->panel = 'logo';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_country';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'hidden',
    'formatter' => 'term_country_flag',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(),
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
  $pane->uuid = 'f2daadd7-42ac-4875-a417-a568b0cdb545';
  $display->content['new-f2daadd7-42ac-4875-a417-a568b0cdb545'] = $pane;
  $display->panels['logo'][0] = 'new-f2daadd7-42ac-4875-a417-a568b0cdb545';
  $pane = new stdClass();
  $pane->pid = 'new-ac9c93c6-d4fe-44bb-9888-a4551b9c5af2';
  $pane->panel = 'middle_left';
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
      'title_style' => '_none',
      'title_link' => '',
      'title_class' => '',
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
  $pane->uuid = 'ac9c93c6-d4fe-44bb-9888-a4551b9c5af2';
  $display->content['new-ac9c93c6-d4fe-44bb-9888-a4551b9c5af2'] = $pane;
  $display->panels['middle_left'][0] = 'new-ac9c93c6-d4fe-44bb-9888-a4551b9c5af2';
  $pane = new stdClass();
  $pane->pid = 'new-d05c7360-62ae-4b57-a2fa-af756b871d17';
  $pane->panel = 'middle_left';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_ph_address';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'hidden',
    'formatter' => 'title_linked',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(
      'title_style' => '_none',
      'title_link' => '',
      'title_class' => '',
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
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = 'd05c7360-62ae-4b57-a2fa-af756b871d17';
  $display->content['new-d05c7360-62ae-4b57-a2fa-af756b871d17'] = $pane;
  $display->panels['middle_left'][1] = 'new-d05c7360-62ae-4b57-a2fa-af756b871d17';
  $pane = new stdClass();
  $pane->pid = 'new-e36dcb73-9189-40e8-acaa-bdd2574c9377';
  $pane->panel = 'middle_left';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_ph_cp';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'hidden',
    'formatter' => 'title_linked',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(
      'title_style' => '_none',
      'title_link' => '',
      'title_class' => '',
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
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = 'e36dcb73-9189-40e8-acaa-bdd2574c9377';
  $display->content['new-e36dcb73-9189-40e8-acaa-bdd2574c9377'] = $pane;
  $display->panels['middle_left'][2] = 'new-e36dcb73-9189-40e8-acaa-bdd2574c9377';
  $pane = new stdClass();
  $pane->pid = 'new-ae9e35d5-93e7-411a-9339-ba89a541254a';
  $pane->panel = 'middle_left';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_ph_town';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'hidden',
    'formatter' => 'text_plain',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(),
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
  $pane->position = 3;
  $pane->locks = array();
  $pane->uuid = 'ae9e35d5-93e7-411a-9339-ba89a541254a';
  $display->content['new-ae9e35d5-93e7-411a-9339-ba89a541254a'] = $pane;
  $display->panels['middle_left'][3] = 'new-ae9e35d5-93e7-411a-9339-ba89a541254a';
  $pane = new stdClass();
  $pane->pid = 'new-14135f69-01f9-4197-8453-a08df3cde4e3';
  $pane->panel = 'middle_left';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_country';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'hidden',
    'formatter' => 'i18n_taxonomy_term_reference_plain',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(),
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
  $pane->position = 4;
  $pane->locks = array();
  $pane->uuid = '14135f69-01f9-4197-8453-a08df3cde4e3';
  $display->content['new-14135f69-01f9-4197-8453-a08df3cde4e3'] = $pane;
  $display->panels['middle_left'][4] = 'new-14135f69-01f9-4197-8453-a08df3cde4e3';
  $pane = new stdClass();
  $pane->pid = 'new-eb585847-4795-4b6d-9822-25da45177327';
  $pane->panel = 'middle_left';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_website';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'hidden',
    'formatter' => 'link_default',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(),
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
  $pane->position = 5;
  $pane->locks = array();
  $pane->uuid = 'eb585847-4795-4b6d-9822-25da45177327';
  $display->content['new-eb585847-4795-4b6d-9822-25da45177327'] = $pane;
  $display->panels['middle_left'][5] = 'new-eb585847-4795-4b6d-9822-25da45177327';
  $pane = new stdClass();
  $pane->pid = 'new-249112dd-020c-473e-87b5-653d3edd5346';
  $pane->panel = 'middle_right';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_main_contact';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'inline',
    'formatter' => 'title_linked',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(
      'title_style' => '_none',
      'title_link' => '',
      'title_class' => '',
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
  $pane->uuid = '249112dd-020c-473e-87b5-653d3edd5346';
  $display->content['new-249112dd-020c-473e-87b5-653d3edd5346'] = $pane;
  $display->panels['middle_right'][0] = 'new-249112dd-020c-473e-87b5-653d3edd5346';
  $pane = new stdClass();
  $pane->pid = 'new-b4c58a13-6a77-4758-a4e7-522b788832e0';
  $pane->panel = 'middle_right';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_general_email';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'hidden',
    'formatter' => 'email_spamspan',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(),
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
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = 'b4c58a13-6a77-4758-a4e7-522b788832e0';
  $display->content['new-b4c58a13-6a77-4758-a4e7-522b788832e0'] = $pane;
  $display->panels['middle_right'][1] = 'new-b4c58a13-6a77-4758-a4e7-522b788832e0';
  $pane = new stdClass();
  $pane->pid = 'new-55e46dc6-cbe6-47b9-9228-2dbb98c6c582';
  $pane->panel = 'middle_right';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_general_phone';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'inline',
    'formatter' => 'title_linked',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(
      'title_style' => '_none',
      'title_link' => '',
      'title_class' => '',
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
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = '55e46dc6-cbe6-47b9-9228-2dbb98c6c582';
  $display->content['new-55e46dc6-cbe6-47b9-9228-2dbb98c6c582'] = $pane;
  $display->panels['middle_right'][2] = 'new-55e46dc6-cbe6-47b9-9228-2dbb98c6c582';
  $pane = new stdClass();
  $pane->pid = 'new-073236e5-2fb2-4d90-b25f-72c03c3545bc';
  $pane->panel = 'my_title';
  $pane->type = 'block';
  $pane->subtype = 'hwc_partner-hwc_partner_private_link_0';
  $pane->shown = TRUE;
  $pane->access = array(
    'plugins' => array(),
  );
  $pane->configuration = array(
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'span',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array(
    'css_id' => '',
    'css_class' => 'col-sm-3',
  );
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '073236e5-2fb2-4d90-b25f-72c03c3545bc';
  $display->content['new-073236e5-2fb2-4d90-b25f-72c03c3545bc'] = $pane;
  $display->panels['my_title'][0] = 'new-073236e5-2fb2-4d90-b25f-72c03c3545bc';
  $pane = new stdClass();
  $pane->pid = 'new-5bbbdd62-a5ac-4873-88f9-e44dca3b7ff8';
  $pane->panel = 'my_title';
  $pane->type = 'block';
  $pane->subtype = 'hwc_partner-hwc_partner_private_link_1';
  $pane->shown = TRUE;
  $pane->access = array(
    'plugins' => array(),
  );
  $pane->configuration = array(
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'span',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array(
    'css_id' => '',
    'css_class' => 'col-sm-3',
  );
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '5bbbdd62-a5ac-4873-88f9-e44dca3b7ff8';
  $display->content['new-5bbbdd62-a5ac-4873-88f9-e44dca3b7ff8'] = $pane;
  $display->panels['my_title'][1] = 'new-5bbbdd62-a5ac-4873-88f9-e44dca3b7ff8';
  $pane = new stdClass();
  $pane->pid = 'new-b441ca28-52c6-4cff-b30f-9c6d75feccf3';
  $pane->panel = 'my_title';
  $pane->type = 'block';
  $pane->subtype = 'hwc_partner-hwc_partner_private_link_2';
  $pane->shown = TRUE;
  $pane->access = array(
    'plugins' => array(),
  );
  $pane->configuration = array(
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'span',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array(
    'css_id' => '',
    'css_class' => 'col-sm-3',
  );
  $pane->extras = array();
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = 'b441ca28-52c6-4cff-b30f-9c6d75feccf3';
  $display->content['new-b441ca28-52c6-4cff-b30f-9c6d75feccf3'] = $pane;
  $display->panels['my_title'][2] = 'new-b441ca28-52c6-4cff-b30f-9c6d75feccf3';
  $pane = new stdClass();
  $pane->pid = 'new-d1910e7b-4e97-4602-b684-7bf4508801fc';
  $pane->panel = 'my_title';
  $pane->type = 'entity_field_extra';
  $pane->subtype = 'node:profile_update_link';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'view_mode' => 'full',
    'context' => 'argument_entity_id:node_1',
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
    'css_class' => 'col-sm-3',
  );
  $pane->extras = array();
  $pane->position = 3;
  $pane->locks = array();
  $pane->uuid = 'd1910e7b-4e97-4602-b684-7bf4508801fc';
  $display->content['new-d1910e7b-4e97-4602-b684-7bf4508801fc'] = $pane;
  $display->panels['my_title'][3] = 'new-d1910e7b-4e97-4602-b684-7bf4508801fc';
  $pane = new stdClass();
  $pane->pid = 'new-728f81dd-50eb-4e5c-962d-e0a4805bf01c';
  $pane->panel = 'my_title';
  $pane->type = 'custom_title_tag';
  $pane->subtype = 'custom_title_tag';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'buttons' => NULL,
    'custom_page_title_pattern' => '%node:title',
    'form_build_id' => 'form-mmmHtrOO-yfYIsLIcNw-2P7wGT2ZFSu2g6eN8FSKTK8',
    'form_token' => 'E28-HqZOY91Hovvo90xKds8wBypNCBej7fXVPqyo1qA',
    'form_id' => 'panels_custom_title_tag_edit_form',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 4;
  $pane->locks = array();
  $pane->uuid = '728f81dd-50eb-4e5c-962d-e0a4805bf01c';
  $display->content['new-728f81dd-50eb-4e5c-962d-e0a4805bf01c'] = $pane;
  $display->panels['my_title'][4] = 'new-728f81dd-50eb-4e5c-962d-e0a4805bf01c';
  $pane = new stdClass();
  $pane->pid = 'new-8b0536ff-9636-49a4-a551-63c0a0affeb0';
  $pane->panel = 'region_left';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_logo';
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
      'image_style' => 'medium',
      'image_link' => '',
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
  $pane->uuid = '8b0536ff-9636-49a4-a551-63c0a0affeb0';
  $display->content['new-8b0536ff-9636-49a4-a551-63c0a0affeb0'] = $pane;
  $display->panels['region_left'][0] = 'new-8b0536ff-9636-49a4-a551-63c0a0affeb0';
  $pane = new stdClass();
  $pane->pid = 'new-63f4624d-dc9c-4071-8a5e-784a6a4c42f3';
  $pane->panel = 'right_';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = TRUE;
  $pane->access = array(
    'plugins' => array(
      0 => array(
        'name' => 'php',
        'settings' => array(
          'description' => 'has any profile added',
          'php' => '$data = $contexts[\'argument_entity_id:node_1\']->data;
return (!empty($data->field_facebook_profile) || !empty($data->field_linkedin_profile) ||
        !empty($data->field_slideshare_profile) || !empty($data->field_twitter_profile) ||
        !empty($data->field_youtube_profile));',
        ),
        'not' => FALSE,
      ),
    ),
  );
  $pane->configuration = array(
    'admin_title' => 'Social media profiles title',
    'title' => '',
    'body' => '<p>Social media profiles</p>',
    'format' => 'full_html',
    'substitute' => 1,
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '63f4624d-dc9c-4071-8a5e-784a6a4c42f3';
  $display->content['new-63f4624d-dc9c-4071-8a5e-784a6a4c42f3'] = $pane;
  $display->panels['right_'][0] = 'new-63f4624d-dc9c-4071-8a5e-784a6a4c42f3';
  $pane = new stdClass();
  $pane->pid = 'new-4aa2b7f8-2742-4819-8198-1451447d6d17';
  $pane->panel = 'right_';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_facebook_profile';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'hidden',
    'formatter' => 'link_url',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(),
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
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '4aa2b7f8-2742-4819-8198-1451447d6d17';
  $display->content['new-4aa2b7f8-2742-4819-8198-1451447d6d17'] = $pane;
  $display->panels['right_'][1] = 'new-4aa2b7f8-2742-4819-8198-1451447d6d17';
  $pane = new stdClass();
  $pane->pid = 'new-ec16d60a-9d23-4140-ab63-d2be45264ae1';
  $pane->panel = 'right_';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_twitter_profile';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'hidden',
    'formatter' => 'link_url',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(),
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
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = 'ec16d60a-9d23-4140-ab63-d2be45264ae1';
  $display->content['new-ec16d60a-9d23-4140-ab63-d2be45264ae1'] = $pane;
  $display->panels['right_'][2] = 'new-ec16d60a-9d23-4140-ab63-d2be45264ae1';
  $pane = new stdClass();
  $pane->pid = 'new-e2ca4501-827a-4e8d-8607-5c15b92cc80a';
  $pane->panel = 'right_';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_linkedin_profile';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'hidden',
    'formatter' => 'link_url',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(),
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
  $pane->position = 3;
  $pane->locks = array();
  $pane->uuid = 'e2ca4501-827a-4e8d-8607-5c15b92cc80a';
  $display->content['new-e2ca4501-827a-4e8d-8607-5c15b92cc80a'] = $pane;
  $display->panels['right_'][3] = 'new-e2ca4501-827a-4e8d-8607-5c15b92cc80a';
  $pane = new stdClass();
  $pane->pid = 'new-ded8085b-914b-4ea5-9480-b2180cbe3902';
  $pane->panel = 'right_';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_youtube_profile';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'hidden',
    'formatter' => 'link_url',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(),
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
  $pane->position = 4;
  $pane->locks = array();
  $pane->uuid = 'ded8085b-914b-4ea5-9480-b2180cbe3902';
  $display->content['new-ded8085b-914b-4ea5-9480-b2180cbe3902'] = $pane;
  $display->panels['right_'][4] = 'new-ded8085b-914b-4ea5-9480-b2180cbe3902';
  $pane = new stdClass();
  $pane->pid = 'new-7515db16-a606-4317-8f88-f4d324a87e4c';
  $pane->panel = 'right_';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_slideshare_profile';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'hidden',
    'formatter' => 'link_url',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(),
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
  $pane->position = 5;
  $pane->locks = array();
  $pane->uuid = '7515db16-a606-4317-8f88-f4d324a87e4c';
  $display->content['new-7515db16-a606-4317-8f88-f4d324a87e4c'] = $pane;
  $display->panels['right_'][5] = 'new-7515db16-a606-4317-8f88-f4d324a87e4c';
  $pane = new stdClass();
  $pane->pid = 'new-54c3bd59-33be-45ad-a4ae-83c6726aea74';
  $pane->panel = 'right_';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_google_plus_profile';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'hidden',
    'formatter' => 'link_url',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(),
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
  $pane->position = 6;
  $pane->locks = array();
  $pane->uuid = '54c3bd59-33be-45ad-a4ae-83c6726aea74';
  $display->content['new-54c3bd59-33be-45ad-a4ae-83c6726aea74'] = $pane;
  $display->panels['right_'][6] = 'new-54c3bd59-33be-45ad-a4ae-83c6726aea74';
  $pane = new stdClass();
  $pane->pid = 'new-f2b8dcc5-13ec-44a6-85dc-6185f0fbeeee';
  $pane->panel = 'right_';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_pinterest_profile';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'hidden',
    'formatter' => 'link_url',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(),
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
  $pane->position = 7;
  $pane->locks = array();
  $pane->uuid = 'f2b8dcc5-13ec-44a6-85dc-6185f0fbeeee';
  $display->content['new-f2b8dcc5-13ec-44a6-85dc-6185f0fbeeee'] = $pane;
  $display->panels['right_'][7] = 'new-f2b8dcc5-13ec-44a6-85dc-6185f0fbeeee';
  $pane = new stdClass();
  $pane->pid = 'new-22050c50-2a04-49d6-b147-ee7e3f0b7183';
  $pane->panel = 'right__';
  $pane->type = 'views';
  $pane->subtype = 'partner_content';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_pager_settings' => 0,
    'use_pager' => 0,
    'nodes_per_page' => '4',
    'pager_id' => '0',
    'offset' => '0',
    'more_link' => 0,
    'feed_icons' => 0,
    'panel_args' => 0,
    'link_to_view' => 0,
    'args' => '',
    'url' => '',
    'display' => 'latest_partner_events',
    'context' => array(
      0 => '',
    ),
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
  $pane->uuid = '22050c50-2a04-49d6-b147-ee7e3f0b7183';
  $display->content['new-22050c50-2a04-49d6-b147-ee7e3f0b7183'] = $pane;
  $display->panels['right__'][0] = 'new-22050c50-2a04-49d6-b147-ee7e3f0b7183';
  $pane = new stdClass();
  $pane->pid = 'new-b97f52ee-3468-4779-acb1-5b1ece1c7c28';
  $pane->panel = 'right__';
  $pane->type = 'views';
  $pane->subtype = 'partner_content';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_pager_settings' => 0,
    'use_pager' => 1,
    'nodes_per_page' => '4',
    'pager_id' => '0',
    'offset' => '0',
    'more_link' => 0,
    'feed_icons' => 0,
    'panel_args' => 0,
    'link_to_view' => 0,
    'args' => '',
    'url' => '',
    'display' => 'past_events',
    'context' => array(
      0 => '',
    ),
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
  $pane->uuid = 'b97f52ee-3468-4779-acb1-5b1ece1c7c28';
  $display->content['new-b97f52ee-3468-4779-acb1-5b1ece1c7c28'] = $pane;
  $display->panels['right__'][1] = 'new-b97f52ee-3468-4779-acb1-5b1ece1c7c28';
  $pane = new stdClass();
  $pane->pid = 'new-77cc5bf8-5bbc-40ce-8d91-e31ff9f96577';
  $pane->panel = 'statement_';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_mission_statement';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'above',
    'formatter' => 'text_default',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(),
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
  $pane->uuid = '77cc5bf8-5bbc-40ce-8d91-e31ff9f96577';
  $display->content['new-77cc5bf8-5bbc-40ce-8d91-e31ff9f96577'] = $pane;
  $display->panels['statement_'][0] = 'new-77cc5bf8-5bbc-40ce-8d91-e31ff9f96577';
  $pane = new stdClass();
  $pane->pid = 'new-b0d55297-4c9d-4800-9bfb-6098978f972e';
  $pane->panel = 'title_';
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
      'title_style' => 'div',
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
  $pane->uuid = 'b0d55297-4c9d-4800-9bfb-6098978f972e';
  $display->content['new-b0d55297-4c9d-4800-9bfb-6098978f972e'] = $pane;
  $display->panels['title_'][0] = 'new-b0d55297-4c9d-4800-9bfb-6098978f972e';
  $pane = new stdClass();
  $pane->pid = 'new-dd26c4e2-cec8-4597-b409-fd35e4d46b08';
  $pane->panel = 'title_';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_country';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'hidden',
    'formatter' => 'i18n_taxonomy_term_reference_plain',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(),
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
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = 'dd26c4e2-cec8-4597-b409-fd35e4d46b08';
  $display->content['new-dd26c4e2-cec8-4597-b409-fd35e4d46b08'] = $pane;
  $display->panels['title_'][1] = 'new-dd26c4e2-cec8-4597-b409-fd35e4d46b08';
  $display->hide_title = PANELS_TITLE_NONE;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['node_view__fop'] = $handler;

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_view__mp-profile';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = 4;
  $handler->conf = array(
    'title' => 'MP profile',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'partner' => 'partner',
            ),
          ),
          'context' => 'argument_entity_id:node_1',
          'not' => FALSE,
        ),
        1 => array(
          'name' => 'entity_field_value:node:partner:field_partner_type',
          'settings' => array(
            'field_partner_type' => array(
              'und' => array(
                0 => array(
                  'tid' => '186',
                ),
              ),
            ),
            'field_partner_type_tid' => array(
              0 => '186',
            ),
          ),
          'context' => 'argument_entity_id:node_1',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
    'name' => 'mp-profile',
    'panels_breadcrumbs_state' => 1,
    'panels_breadcrumbs_titles' => 'Campaign partners
Media partners
%node:title-field',
    'panels_breadcrumbs_paths' => '<none>
campaign-media-partners
<none>',
    'panels_breadcrumbs_home' => 1,
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
          0 => 6,
          1 => 5,
          2 => 4,
          3 => 1,
          4 => 2,
          5 => 3,
        ),
        'parent' => 'canvas',
      ),
      1 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'left',
          1 => 'right',
        ),
        'parent' => 'main',
        'class' => 'container profile-2-cols-container-1',
        'hide_empty' => 0,
      ),
      'left' => array(
        'type' => 'region',
        'title' => 'Left',
        'width' => 50,
        'width_type' => '%',
        'parent' => '1',
        'class' => 'col-sm-3 profile-col-left-1',
        'hide_empty' => 0,
      ),
      'right' => array(
        'type' => 'region',
        'title' => 'Right',
        'width' => 50,
        'width_type' => '%',
        'parent' => '1',
        'class' => 'col-sm-9 profile-col-right-1',
        'hide_empty' => 0,
      ),
      2 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'left___',
          1 => 'right___',
        ),
        'parent' => 'main',
        'class' => 'container profile-4-cols-container-2',
        'hide_empty' => 0,
      ),
      3 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'left__',
          1 => 'right__',
        ),
        'parent' => 'main',
        'class' => 'container profile-2-cols-container-3',
        'hide_empty' => 0,
      ),
      'left__' => array(
        'type' => 'region',
        'title' => 'Left',
        'width' => '25.091027461588755',
        'width_type' => '%',
        'parent' => '3',
        'class' => 'col-sm-6 profile-col-left-3',
        'hide_empty' => 0,
      ),
      'right__' => array(
        'type' => 'region',
        'title' => 'Right',
        'width' => '24.908972538411245',
        'width_type' => '%',
        'parent' => '3',
        'class' => 'col-sm-6 profile-col-right-3',
        'hide_empty' => 0,
      ),
      4 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'center_',
        ),
        'parent' => 'main',
        'class' => 'container profile-title-type-container',
        'hide_empty' => 1,
      ),
      'center_' => array(
        'type' => 'region',
        'title' => 'Center',
        'width' => 100,
        'width_type' => '%',
        'parent' => '4',
        'class' => 'col-md-12',
        'hide_empty' => 1,
      ),
      5 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'center__',
        ),
        'parent' => 'main',
        'class' => '',
        'hide_empty' => 0,
      ),
      'center__' => array(
        'type' => 'region',
        'title' => 'Center',
        'width' => 100,
        'width_type' => '%',
        'parent' => '5',
        'class' => '',
        'hide_empty' => 0,
      ),
      'left___' => array(
        'type' => 'region',
        'title' => 'Left',
        'width' => 25,
        'width_type' => '%',
        'parent' => '2',
        'class' => 'col-sm-3 profile-col-left-2',
        'hide_empty' => 0,
      ),
      'right___' => array(
        'type' => 'region',
        'title' => 'Right',
        'width' => 75,
        'width_type' => '%',
        'parent' => '2',
        'class' => 'col-sm-4 profile-col-right-2',
        'hide_empty' => 0,
      ),
      6 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'my_title',
        ),
        'parent' => 'main',
        'class' => 'profile-edit-links-container',
        'hide_empty' => 0,
      ),
      'my_title' => array(
        'type' => 'region',
        'title' => 'Center',
        'width' => 100,
        'width_type' => '%',
        'parent' => '6',
        'class' => '',
        'hide_empty' => 0,
      ),
    ),
  );
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'center' => NULL,
      'left' => NULL,
      'right' => NULL,
      'left_' => NULL,
      'right_' => NULL,
      'left__' => NULL,
      'right__' => NULL,
      'center_' => NULL,
      'center__' => NULL,
      'left___' => NULL,
      'right___' => NULL,
      'my_title' => NULL,
      'right____' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '%node:title-field';
  $display->uuid = '536f07b4-59cc-4e7d-84b4-3635ebb5aa94';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'node_view__mp-profile';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-21193c9b-bdf0-46b9-8120-f1d3781f045d';
  $pane->panel = 'center_';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:title_field';
  $pane->shown = TRUE;
  $pane->access = array(
    'plugins' => array(),
  );
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
  $pane->uuid = '21193c9b-bdf0-46b9-8120-f1d3781f045d';
  $display->content['new-21193c9b-bdf0-46b9-8120-f1d3781f045d'] = $pane;
  $display->panels['center_'][0] = 'new-21193c9b-bdf0-46b9-8120-f1d3781f045d';
  $pane = new stdClass();
  $pane->pid = 'new-f447a5b4-3387-4b4c-bd0b-aa6861bf904f';
  $pane->panel = 'center_';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_country';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'hidden',
    'formatter' => 'taxonomy_term_reference_plain',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(),
    'context' => 'argument_entity_id:node_1',
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
    'css_class' => 'profile-inline-field',
  );
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = 'f447a5b4-3387-4b4c-bd0b-aa6861bf904f';
  $display->content['new-f447a5b4-3387-4b4c-bd0b-aa6861bf904f'] = $pane;
  $display->panels['center_'][1] = 'new-f447a5b4-3387-4b4c-bd0b-aa6861bf904f';
  $pane = new stdClass();
  $pane->pid = 'new-2c5384eb-8241-4cbf-a6b5-aeb3a1a40523';
  $pane->panel = 'center_';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_website';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'hidden',
    'formatter' => 'link_default',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(),
    'context' => 'argument_entity_id:node_1',
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
    'css_class' => 'profile-inline-field',
  );
  $pane->extras = array();
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = '2c5384eb-8241-4cbf-a6b5-aeb3a1a40523';
  $display->content['new-2c5384eb-8241-4cbf-a6b5-aeb3a1a40523'] = $pane;
  $display->panels['center_'][2] = 'new-2c5384eb-8241-4cbf-a6b5-aeb3a1a40523';
  $pane = new stdClass();
  $pane->pid = 'new-5e29b793-d024-46c0-abfd-72f6e021e824';
  $pane->panel = 'center_';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_ceo';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'title',
    'formatter' => 'text_plain',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(),
    'context' => 'argument_entity_id:node_1',
    'override_title' => 1,
    'override_title_text' => 'Editor in chief',
    'override_title_heading' => 'span',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array(
    'css_id' => '',
    'css_class' => '',
  );
  $pane->extras = array();
  $pane->position = 3;
  $pane->locks = array();
  $pane->uuid = '5e29b793-d024-46c0-abfd-72f6e021e824';
  $display->content['new-5e29b793-d024-46c0-abfd-72f6e021e824'] = $pane;
  $display->panels['center_'][3] = 'new-5e29b793-d024-46c0-abfd-72f6e021e824';
  $pane = new stdClass();
  $pane->pid = 'new-01df3ff6-7648-4eb2-a42a-6d35973b8301';
  $pane->panel = 'center__';
  $pane->type = 'block';
  $pane->subtype = 'hwc_partner-hwc_partner_profile_title';
  $pane->shown = TRUE;
  $pane->access = array(
    'plugins' => array(
      0 => array(
        'name' => 'php',
        'settings' => array(
          'description' => 'Page belongs to partner',
          'php' => '$node=menu_get_object(); return hwc_partner_match_user_partner($node);',
        ),
        'not' => FALSE,
      ),
    ),
  );
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
  $pane->uuid = '01df3ff6-7648-4eb2-a42a-6d35973b8301';
  $display->content['new-01df3ff6-7648-4eb2-a42a-6d35973b8301'] = $pane;
  $display->panels['center__'][0] = 'new-01df3ff6-7648-4eb2-a42a-6d35973b8301';
  $pane = new stdClass();
  $pane->pid = 'new-0b4279c4-f4de-431f-9738-30d53b5790f0';
  $pane->panel = 'left';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_logo';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'hidden',
    'formatter' => 'image',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(
      'image_style' => 'medium',
      'image_link' => '',
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
  $pane->uuid = '0b4279c4-f4de-431f-9738-30d53b5790f0';
  $display->content['new-0b4279c4-f4de-431f-9738-30d53b5790f0'] = $pane;
  $display->panels['left'][0] = 'new-0b4279c4-f4de-431f-9738-30d53b5790f0';
  $pane = new stdClass();
  $pane->pid = 'new-58094813-4281-4753-b1e0-5e58a26999fb';
  $pane->panel = 'left__';
  $pane->type = 'views';
  $pane->subtype = 'partner_content';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_pager_settings' => 0,
    'use_pager' => 0,
    'nodes_per_page' => '4',
    'pager_id' => '0',
    'offset' => '0',
    'more_link' => 0,
    'feed_icons' => 0,
    'panel_args' => 0,
    'link_to_view' => 0,
    'args' => '',
    'url' => '',
    'display' => 'latest_partner_news',
    'context' => array(
      0 => '',
    ),
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
  $pane->uuid = '58094813-4281-4753-b1e0-5e58a26999fb';
  $display->content['new-58094813-4281-4753-b1e0-5e58a26999fb'] = $pane;
  $display->panels['left__'][0] = 'new-58094813-4281-4753-b1e0-5e58a26999fb';
  $pane = new stdClass();
  $pane->pid = 'new-fe6ef5cb-ebb9-4d64-8782-9a5d53afed92';
  $pane->panel = 'left___';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_general_email';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'hidden',
    'formatter' => 'email_spamspan',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(),
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
  $pane->uuid = 'fe6ef5cb-ebb9-4d64-8782-9a5d53afed92';
  $display->content['new-fe6ef5cb-ebb9-4d64-8782-9a5d53afed92'] = $pane;
  $display->panels['left___'][0] = 'new-fe6ef5cb-ebb9-4d64-8782-9a5d53afed92';
  $pane = new stdClass();
  $pane->pid = 'new-55e46dc6-cbe6-47b9-9228-2dbb98c6c582';
  $pane->panel = 'left___';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_general_phone';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'inline',
    'formatter' => 'title_linked',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(
      'title_style' => '_none',
      'title_link' => '',
      'title_class' => '',
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
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '55e46dc6-cbe6-47b9-9228-2dbb98c6c582';
  $display->content['new-55e46dc6-cbe6-47b9-9228-2dbb98c6c582'] = $pane;
  $display->panels['left___'][1] = 'new-55e46dc6-cbe6-47b9-9228-2dbb98c6c582';
  $pane = new stdClass();
  $pane->pid = 'new-249112dd-020c-473e-87b5-653d3edd5346';
  $pane->panel = 'left___';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_main_contact';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'inline',
    'formatter' => 'title_linked',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(
      'title_style' => '_none',
      'title_link' => '',
      'title_class' => '',
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
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = '249112dd-020c-473e-87b5-653d3edd5346';
  $display->content['new-249112dd-020c-473e-87b5-653d3edd5346'] = $pane;
  $display->panels['left___'][2] = 'new-249112dd-020c-473e-87b5-653d3edd5346';
  $pane = new stdClass();
  $pane->pid = 'new-073236e5-2fb2-4d90-b25f-72c03c3545bc';
  $pane->panel = 'my_title';
  $pane->type = 'block';
  $pane->subtype = 'hwc_partner-hwc_partner_private_link_0';
  $pane->shown = TRUE;
  $pane->access = array(
    'plugins' => array(),
  );
  $pane->configuration = array(
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'span',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array(
    'css_id' => '',
    'css_class' => 'col-sm-3',
  );
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '073236e5-2fb2-4d90-b25f-72c03c3545bc';
  $display->content['new-073236e5-2fb2-4d90-b25f-72c03c3545bc'] = $pane;
  $display->panels['my_title'][0] = 'new-073236e5-2fb2-4d90-b25f-72c03c3545bc';
  $pane = new stdClass();
  $pane->pid = 'new-5bbbdd62-a5ac-4873-88f9-e44dca3b7ff8';
  $pane->panel = 'my_title';
  $pane->type = 'block';
  $pane->subtype = 'hwc_partner-hwc_partner_private_link_1';
  $pane->shown = TRUE;
  $pane->access = array(
    'plugins' => array(),
  );
  $pane->configuration = array(
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'span',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array(
    'css_id' => '',
    'css_class' => 'col-sm-3',
  );
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '5bbbdd62-a5ac-4873-88f9-e44dca3b7ff8';
  $display->content['new-5bbbdd62-a5ac-4873-88f9-e44dca3b7ff8'] = $pane;
  $display->panels['my_title'][1] = 'new-5bbbdd62-a5ac-4873-88f9-e44dca3b7ff8';
  $pane = new stdClass();
  $pane->pid = 'new-b441ca28-52c6-4cff-b30f-9c6d75feccf3';
  $pane->panel = 'my_title';
  $pane->type = 'block';
  $pane->subtype = 'hwc_partner-hwc_partner_private_link_2';
  $pane->shown = TRUE;
  $pane->access = array(
    'plugins' => array(),
  );
  $pane->configuration = array(
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'span',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array(
    'css_id' => '',
    'css_class' => 'col-sm-3',
  );
  $pane->extras = array();
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = 'b441ca28-52c6-4cff-b30f-9c6d75feccf3';
  $display->content['new-b441ca28-52c6-4cff-b30f-9c6d75feccf3'] = $pane;
  $display->panels['my_title'][2] = 'new-b441ca28-52c6-4cff-b30f-9c6d75feccf3';
  $pane = new stdClass();
  $pane->pid = 'new-d1910e7b-4e97-4602-b684-7bf4508801fc';
  $pane->panel = 'my_title';
  $pane->type = 'entity_field_extra';
  $pane->subtype = 'node:profile_update_link';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'view_mode' => 'full',
    'context' => 'argument_entity_id:node_1',
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
    'css_class' => 'col-sm-3',
  );
  $pane->extras = array();
  $pane->position = 3;
  $pane->locks = array();
  $pane->uuid = 'd1910e7b-4e97-4602-b684-7bf4508801fc';
  $display->content['new-d1910e7b-4e97-4602-b684-7bf4508801fc'] = $pane;
  $display->panels['my_title'][3] = 'new-d1910e7b-4e97-4602-b684-7bf4508801fc';
  $pane = new stdClass();
  $pane->pid = 'new-72daed56-c812-495c-b79a-64a72e92e5dd';
  $pane->panel = 'my_title';
  $pane->type = 'custom_title_tag';
  $pane->subtype = 'custom_title_tag';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'buttons' => NULL,
    'custom_page_title_pattern' => '%node:title',
    'form_build_id' => 'form-Idvy953kBzuCEnh5J3T3_WctDC7CjvIASgZOJdKqGS0',
    'form_token' => 'E28-HqZOY91Hovvo90xKds8wBypNCBej7fXVPqyo1qA',
    'form_id' => 'panels_custom_title_tag_edit_form',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 4;
  $pane->locks = array();
  $pane->uuid = '72daed56-c812-495c-b79a-64a72e92e5dd';
  $display->content['new-72daed56-c812-495c-b79a-64a72e92e5dd'] = $pane;
  $display->panels['my_title'][4] = 'new-72daed56-c812-495c-b79a-64a72e92e5dd';
  $pane = new stdClass();
  $pane->pid = 'new-8ff53bc4-a287-4f2f-9727-5510ead1e75a';
  $pane->panel = 'right';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_pledge';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'title',
    'formatter' => 'text_plain',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(),
    'context' => 'argument_entity_id:node_1',
    'override_title' => 1,
    'override_title_text' => 'Our contribution',
    'override_title_heading' => 'div',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array(
    'css_id' => '',
    'css_class' => '',
  );
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '8ff53bc4-a287-4f2f-9727-5510ead1e75a';
  $display->content['new-8ff53bc4-a287-4f2f-9727-5510ead1e75a'] = $pane;
  $display->panels['right'][0] = 'new-8ff53bc4-a287-4f2f-9727-5510ead1e75a';
  $pane = new stdClass();
  $pane->pid = 'new-22050c50-2a04-49d6-b147-ee7e3f0b7183';
  $pane->panel = 'right__';
  $pane->type = 'views';
  $pane->subtype = 'partner_content';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_pager_settings' => 0,
    'use_pager' => 0,
    'nodes_per_page' => '4',
    'pager_id' => '0',
    'offset' => '0',
    'more_link' => 0,
    'feed_icons' => 0,
    'panel_args' => 0,
    'link_to_view' => 0,
    'args' => '',
    'url' => '',
    'display' => 'latest_partner_events',
    'context' => array(
      0 => '',
    ),
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
  $pane->uuid = '22050c50-2a04-49d6-b147-ee7e3f0b7183';
  $display->content['new-22050c50-2a04-49d6-b147-ee7e3f0b7183'] = $pane;
  $display->panels['right__'][0] = 'new-22050c50-2a04-49d6-b147-ee7e3f0b7183';
  $pane = new stdClass();
  $pane->pid = 'new-1e999780-1139-41b0-a338-142d50993f03';
  $pane->panel = 'right__';
  $pane->type = 'views';
  $pane->subtype = 'partner_content';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_pager_settings' => 0,
    'use_pager' => 1,
    'nodes_per_page' => '4',
    'pager_id' => '0',
    'offset' => '0',
    'more_link' => 0,
    'feed_icons' => 0,
    'panel_args' => 0,
    'link_to_view' => 0,
    'args' => '',
    'url' => '',
    'display' => 'past_events',
    'context' => array(
      0 => '',
    ),
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
  $pane->uuid = '1e999780-1139-41b0-a338-142d50993f03';
  $display->content['new-1e999780-1139-41b0-a338-142d50993f03'] = $pane;
  $display->panels['right__'][1] = 'new-1e999780-1139-41b0-a338-142d50993f03';
  $pane = new stdClass();
  $pane->pid = 'new-63f4624d-dc9c-4071-8a5e-784a6a4c42f3';
  $pane->panel = 'right___';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = TRUE;
  $pane->access = array(
    'plugins' => array(
      0 => array(
        'name' => 'php',
        'settings' => array(
          'description' => 'has any profile added',
          'php' => '$data = $contexts[\'argument_entity_id:node_1\']->data;
return (!empty($data->field_facebook_profile) || !empty($data->field_linkedin_profile) ||
        !empty($data->field_slideshare_profile) || !empty($data->field_twitter_profile) ||
        !empty($data->field_youtube_profile));',
        ),
        'not' => FALSE,
      ),
    ),
  );
  $pane->configuration = array(
    'admin_title' => 'Social media profiles title',
    'title' => '',
    'body' => '<p>Social media profiles</p>',
    'format' => 'full_html',
    'substitute' => 1,
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '63f4624d-dc9c-4071-8a5e-784a6a4c42f3';
  $display->content['new-63f4624d-dc9c-4071-8a5e-784a6a4c42f3'] = $pane;
  $display->panels['right___'][0] = 'new-63f4624d-dc9c-4071-8a5e-784a6a4c42f3';
  $pane = new stdClass();
  $pane->pid = 'new-4aa2b7f8-2742-4819-8198-1451447d6d17';
  $pane->panel = 'right___';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_facebook_profile';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'hidden',
    'formatter' => 'link_url',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(),
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
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '4aa2b7f8-2742-4819-8198-1451447d6d17';
  $display->content['new-4aa2b7f8-2742-4819-8198-1451447d6d17'] = $pane;
  $display->panels['right___'][1] = 'new-4aa2b7f8-2742-4819-8198-1451447d6d17';
  $pane = new stdClass();
  $pane->pid = 'new-ec16d60a-9d23-4140-ab63-d2be45264ae1';
  $pane->panel = 'right___';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_twitter_profile';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'hidden',
    'formatter' => 'link_url',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(),
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
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = 'ec16d60a-9d23-4140-ab63-d2be45264ae1';
  $display->content['new-ec16d60a-9d23-4140-ab63-d2be45264ae1'] = $pane;
  $display->panels['right___'][2] = 'new-ec16d60a-9d23-4140-ab63-d2be45264ae1';
  $pane = new stdClass();
  $pane->pid = 'new-e2ca4501-827a-4e8d-8607-5c15b92cc80a';
  $pane->panel = 'right___';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_linkedin_profile';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'hidden',
    'formatter' => 'link_url',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(),
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
  $pane->position = 3;
  $pane->locks = array();
  $pane->uuid = 'e2ca4501-827a-4e8d-8607-5c15b92cc80a';
  $display->content['new-e2ca4501-827a-4e8d-8607-5c15b92cc80a'] = $pane;
  $display->panels['right___'][3] = 'new-e2ca4501-827a-4e8d-8607-5c15b92cc80a';
  $pane = new stdClass();
  $pane->pid = 'new-ded8085b-914b-4ea5-9480-b2180cbe3902';
  $pane->panel = 'right___';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_youtube_profile';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'hidden',
    'formatter' => 'link_url',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(),
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
  $pane->position = 4;
  $pane->locks = array();
  $pane->uuid = 'ded8085b-914b-4ea5-9480-b2180cbe3902';
  $display->content['new-ded8085b-914b-4ea5-9480-b2180cbe3902'] = $pane;
  $display->panels['right___'][4] = 'new-ded8085b-914b-4ea5-9480-b2180cbe3902';
  $pane = new stdClass();
  $pane->pid = 'new-7515db16-a606-4317-8f88-f4d324a87e4c';
  $pane->panel = 'right___';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_slideshare_profile';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'hidden',
    'formatter' => 'link_url',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(),
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
  $pane->position = 5;
  $pane->locks = array();
  $pane->uuid = '7515db16-a606-4317-8f88-f4d324a87e4c';
  $display->content['new-7515db16-a606-4317-8f88-f4d324a87e4c'] = $pane;
  $display->panels['right___'][5] = 'new-7515db16-a606-4317-8f88-f4d324a87e4c';
  $pane = new stdClass();
  $pane->pid = 'new-b9d8de34-a3ee-492b-a36c-aeda87849585';
  $pane->panel = 'right___';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_google_plus_profile';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'hidden',
    'formatter' => 'link_url',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(),
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
  $pane->position = 6;
  $pane->locks = array();
  $pane->uuid = 'b9d8de34-a3ee-492b-a36c-aeda87849585';
  $display->content['new-b9d8de34-a3ee-492b-a36c-aeda87849585'] = $pane;
  $display->panels['right___'][6] = 'new-b9d8de34-a3ee-492b-a36c-aeda87849585';
  $pane = new stdClass();
  $pane->pid = 'new-ce22f683-9782-42d4-9303-8bc44db8987b';
  $pane->panel = 'right___';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_pinterest_profile';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'hidden',
    'formatter' => 'link_url',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(),
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
  $pane->position = 7;
  $pane->locks = array();
  $pane->uuid = 'ce22f683-9782-42d4-9303-8bc44db8987b';
  $display->content['new-ce22f683-9782-42d4-9303-8bc44db8987b'] = $pane;
  $display->panels['right___'][7] = 'new-ce22f683-9782-42d4-9303-8bc44db8987b';
  $display->hide_title = PANELS_TITLE_NONE;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['node_view__mp-profile'] = $handler;

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_view__panel_context_d109f4e3-27a8-4bfa-922c-690f8fc7a2eb';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = 1;
  $handler->conf = array(
    'title' => 'OCP profile',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'partner' => 'partner',
            ),
          ),
          'context' => 'argument_entity_id:node_1',
          'not' => FALSE,
        ),
        1 => array(
          'name' => 'entity_field_value:node:partner:field_partner_type',
          'settings' => array(
            'field_partner_type' => array(
              'und' => array(
                0 => array(
                  'tid' => '185',
                ),
              ),
            ),
            'field_partner_type_tid' => array(
              0 => '185',
            ),
          ),
          'context' => 'argument_entity_id:node_1',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
    'panels_breadcrumbs_state' => 1,
    'panels_breadcrumbs_titles' => 'Campaign partners
Official campaign partners
%node:title-field
',
    'panels_breadcrumbs_paths' => '<none>
official-campaign-partners
<none>
',
    'panels_breadcrumbs_home' => 1,
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
          0 => 6,
          1 => 5,
          2 => 4,
          3 => 'main-row',
          4 => 1,
          5 => 7,
          6 => 14,
        ),
        'parent' => 'canvas',
      ),
      'main-row' => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'center',
        ),
        'parent' => 'main',
        'class' => 'profile-ceo-container',
        'hide_empty' => 1,
      ),
      'center' => array(
        'type' => 'region',
        'title' => 'Center',
        'width' => 100,
        'width_type' => '%',
        'parent' => 'main-row',
        'class' => 'container',
        'hide_empty' => 1,
      ),
      1 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'left',
          1 => 'right',
        ),
        'parent' => 'main',
        'class' => 'container profile-2-cols-container-1',
        'hide_empty' => 0,
      ),
      'left' => array(
        'type' => 'region',
        'title' => 'Left',
        'width' => 50,
        'width_type' => '%',
        'parent' => '1',
        'class' => 'col-sm-6 profile-col-left-1',
        'hide_empty' => 0,
      ),
      'right' => array(
        'type' => 'region',
        'title' => 'Right',
        'width' => 50,
        'width_type' => '%',
        'parent' => '1',
        'class' => 'col-sm-6 profile-col-right-1',
        'hide_empty' => 0,
      ),
      4 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'center_',
        ),
        'parent' => 'main',
        'class' => 'container profile-title-type-container',
        'hide_empty' => 0,
      ),
      'center_' => array(
        'type' => 'region',
        'title' => 'Center',
        'width' => 100,
        'width_type' => '%',
        'parent' => '4',
        'class' => 'col-md-12',
        'hide_empty' => 0,
      ),
      5 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'center__',
        ),
        'parent' => 'main',
        'class' => '',
        'hide_empty' => 0,
      ),
      'center__' => array(
        'type' => 'region',
        'title' => 'Center',
        'width' => 100,
        'width_type' => '%',
        'parent' => '5',
        'class' => '',
        'hide_empty' => 0,
      ),
      6 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'my_title',
        ),
        'parent' => 'main',
        'class' => 'profile-edit-links-container',
        'hide_empty' => 0,
      ),
      'my_title' => array(
        'type' => 'region',
        'title' => 'Center',
        'width' => 100,
        'width_type' => '%',
        'parent' => '6',
        'class' => '',
        'hide_empty' => 0,
      ),
      7 => array(
        'type' => 'row',
        'contains' => 'column',
        'children' => array(
          0 => 8,
          1 => 9,
          2 => 10,
        ),
        'parent' => 'main',
        'class' => 'container profile-4-cols-container-2',
        'hide_empty' => 0,
      ),
      8 => array(
        'type' => 'column',
        'width' => '33.34202927079388',
        'width_type' => '%',
        'parent' => '7',
        'children' => array(
          0 => 11,
        ),
        'class' => '',
        'hide_empty' => 0,
      ),
      9 => array(
        'type' => 'column',
        'width' => '33.331884609567126',
        'width_type' => '%',
        'parent' => '7',
        'children' => array(
          0 => 12,
        ),
        'class' => '',
        'hide_empty' => 0,
      ),
      10 => array(
        'type' => 'column',
        'width' => '33.32608611963901',
        'width_type' => '%',
        'parent' => '7',
        'children' => array(
          0 => 13,
        ),
        'class' => '',
        'hide_empty' => 0,
      ),
      11 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'region',
          1 => 'region_1_2',
        ),
        'parent' => '8',
        'class' => '',
        'hide_empty' => 0,
      ),
      'region' => array(
        'type' => 'region',
        'title' => 'Region 1.1',
        'width' => 50,
        'width_type' => '%',
        'parent' => '11',
        'class' => 'col-sm-3 profile-col-left-2',
        'hide_empty' => 0,
      ),
      12 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'region_2',
        ),
        'parent' => '9',
        'class' => '',
        'hide_empty' => 0,
      ),
      'region_2' => array(
        'type' => 'region',
        'title' => 'Region 2',
        'width' => 100,
        'width_type' => '%',
        'parent' => '12',
        'class' => 'col-sm-3 profile-col-middle-right-2',
        'hide_empty' => 0,
      ),
      13 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'region_3',
        ),
        'parent' => '10',
        'class' => '',
        'hide_empty' => 0,
      ),
      'region_3' => array(
        'type' => 'region',
        'title' => 'Region 3',
        'width' => 100,
        'width_type' => '%',
        'parent' => '13',
        'class' => 'col-sm-3 profile-col-right-2',
        'hide_empty' => 0,
      ),
      'region_1_2' => array(
        'type' => 'region',
        'title' => 'Region 1.2',
        'width' => 50,
        'width_type' => '%',
        'parent' => '11',
        'class' => 'col-sm-3 profile-col-left-middle-2',
        'hide_empty' => 0,
      ),
      14 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'left_',
          1 => 'right_',
        ),
        'parent' => 'main',
        'class' => 'container profile-2-cols-container-3',
        'hide_empty' => 0,
      ),
      'left_' => array(
        'type' => 'region',
        'title' => 'Left',
        'width' => 50,
        'width_type' => '%',
        'parent' => '14',
        'class' => 'col-sm-6 profile-col-left-3',
        'hide_empty' => 0,
      ),
      'right_' => array(
        'type' => 'region',
        'title' => 'right',
        'width' => 50,
        'width_type' => '%',
        'parent' => '14',
        'class' => 'col-sm-6 profile-col-left-3',
        'hide_empty' => 0,
      ),
    ),
  );
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'center' => NULL,
      'left' => NULL,
      'right' => NULL,
      'left_' => NULL,
      'right_' => NULL,
      'left__' => NULL,
      'right__' => NULL,
      'center_' => NULL,
      'center__' => NULL,
      'left___' => NULL,
      'right___' => NULL,
      'my_title' => NULL,
      'region' => NULL,
      'region_2' => NULL,
      'region_3' => NULL,
      'region_1_2' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '%node:title-field';
  $display->uuid = '536f07b4-59cc-4e7d-84b4-3635ebb5aa94';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'node_view__panel_context_d109f4e3-27a8-4bfa-922c-690f8fc7a2eb';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-644faa7b-274b-41e6-b1d0-f7df567e91b6';
  $pane->panel = 'center';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_ceo_photo';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'hidden',
    'formatter' => 'image',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(
      'image_style' => 'medium',
      'image_link' => '',
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
  $pane->uuid = '644faa7b-274b-41e6-b1d0-f7df567e91b6';
  $display->content['new-644faa7b-274b-41e6-b1d0-f7df567e91b6'] = $pane;
  $display->panels['center'][0] = 'new-644faa7b-274b-41e6-b1d0-f7df567e91b6';
  $pane = new stdClass();
  $pane->pid = 'new-1ffdd101-4abb-456f-a821-37d48bea82a3';
  $pane->panel = 'center';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_ceo';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'hidden',
    'formatter' => 'title_linked',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(
      'title_style' => '_none',
      'title_link' => '',
      'title_class' => '',
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
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '1ffdd101-4abb-456f-a821-37d48bea82a3';
  $display->content['new-1ffdd101-4abb-456f-a821-37d48bea82a3'] = $pane;
  $display->panels['center'][1] = 'new-1ffdd101-4abb-456f-a821-37d48bea82a3';
  $pane = new stdClass();
  $pane->pid = 'new-52ad8dcd-03db-4d20-b37e-93a434088e3d';
  $pane->panel = 'center';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_position_identifier';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'hidden',
    'formatter' => 'text_plain',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(),
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
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = '52ad8dcd-03db-4d20-b37e-93a434088e3d';
  $display->content['new-52ad8dcd-03db-4d20-b37e-93a434088e3d'] = $pane;
  $display->panels['center'][2] = 'new-52ad8dcd-03db-4d20-b37e-93a434088e3d';
  $pane = new stdClass();
  $pane->pid = 'new-9dca80f0-8993-49f6-aa29-a8c69d918778';
  $pane->panel = 'center';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_quote';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'hidden',
    'formatter' => 'text_default',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(),
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
  $pane->position = 3;
  $pane->locks = array();
  $pane->uuid = '9dca80f0-8993-49f6-aa29-a8c69d918778';
  $display->content['new-9dca80f0-8993-49f6-aa29-a8c69d918778'] = $pane;
  $display->panels['center'][3] = 'new-9dca80f0-8993-49f6-aa29-a8c69d918778';
  $pane = new stdClass();
  $pane->pid = 'new-21193c9b-bdf0-46b9-8120-f1d3781f045d';
  $pane->panel = 'center_';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:title_field';
  $pane->shown = TRUE;
  $pane->access = array(
    'plugins' => array(),
  );
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
  $pane->uuid = '21193c9b-bdf0-46b9-8120-f1d3781f045d';
  $display->content['new-21193c9b-bdf0-46b9-8120-f1d3781f045d'] = $pane;
  $display->panels['center_'][0] = 'new-21193c9b-bdf0-46b9-8120-f1d3781f045d';
  $pane = new stdClass();
  $pane->pid = 'new-2f8ed0d0-aabd-40cc-8d5f-2dcd30d81957';
  $pane->panel = 'center_';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_orgtype';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'hidden',
    'formatter' => 'i18n_taxonomy_term_reference_plain',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(
      'title_style' => '_none',
      'title_link' => '',
      'title_class' => '',
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
  $pane->css = array(
    'css_id' => '',
    'css_class' => 'profile-inline-field',
  );
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '2f8ed0d0-aabd-40cc-8d5f-2dcd30d81957';
  $display->content['new-2f8ed0d0-aabd-40cc-8d5f-2dcd30d81957'] = $pane;
  $display->panels['center_'][1] = 'new-2f8ed0d0-aabd-40cc-8d5f-2dcd30d81957';
  $pane = new stdClass();
  $pane->pid = 'new-91027b2b-a9f8-4c30-84cf-608524bd44cd';
  $pane->panel = 'center_';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_bussines_sector';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'hidden',
    'formatter' => 'i18n_taxonomy_term_reference_plain',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(
      'title_style' => '_none',
      'title_link' => '',
      'title_class' => '',
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
  $pane->css = array(
    'css_id' => '',
    'css_class' => 'profile-inline-field',
  );
  $pane->extras = array();
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = '91027b2b-a9f8-4c30-84cf-608524bd44cd';
  $display->content['new-91027b2b-a9f8-4c30-84cf-608524bd44cd'] = $pane;
  $display->panels['center_'][2] = 'new-91027b2b-a9f8-4c30-84cf-608524bd44cd';
  $pane = new stdClass();
  $pane->pid = 'new-2c5384eb-8241-4cbf-a6b5-aeb3a1a40523';
  $pane->panel = 'center_';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_website';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'hidden',
    'formatter' => 'link_default',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(),
    'context' => 'argument_entity_id:node_1',
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
    'css_class' => 'profile-inline-field',
  );
  $pane->extras = array();
  $pane->position = 3;
  $pane->locks = array();
  $pane->uuid = '2c5384eb-8241-4cbf-a6b5-aeb3a1a40523';
  $display->content['new-2c5384eb-8241-4cbf-a6b5-aeb3a1a40523'] = $pane;
  $display->panels['center_'][3] = 'new-2c5384eb-8241-4cbf-a6b5-aeb3a1a40523';
  $pane = new stdClass();
  $pane->pid = 'new-01df3ff6-7648-4eb2-a42a-6d35973b8301';
  $pane->panel = 'center__';
  $pane->type = 'block';
  $pane->subtype = 'hwc_partner-hwc_partner_profile_title';
  $pane->shown = TRUE;
  $pane->access = array(
    'plugins' => array(
      0 => array(
        'name' => 'php',
        'settings' => array(
          'description' => 'Page belongs to partner',
          'php' => '$node=menu_get_object(); return hwc_partner_match_user_partner($node);',
        ),
        'not' => FALSE,
      ),
    ),
  );
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
  $pane->uuid = '01df3ff6-7648-4eb2-a42a-6d35973b8301';
  $display->content['new-01df3ff6-7648-4eb2-a42a-6d35973b8301'] = $pane;
  $display->panels['center__'][0] = 'new-01df3ff6-7648-4eb2-a42a-6d35973b8301';
  $pane = new stdClass();
  $pane->pid = 'new-77cc5bf8-5bbc-40ce-8d91-e31ff9f96577';
  $pane->panel = 'left';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_mission_statement';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'above',
    'formatter' => 'text_default',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(),
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
  $pane->uuid = '77cc5bf8-5bbc-40ce-8d91-e31ff9f96577';
  $display->content['new-77cc5bf8-5bbc-40ce-8d91-e31ff9f96577'] = $pane;
  $display->panels['left'][0] = 'new-77cc5bf8-5bbc-40ce-8d91-e31ff9f96577';
  $pane = new stdClass();
  $pane->pid = 'new-58094813-4281-4753-b1e0-5e58a26999fb';
  $pane->panel = 'left_';
  $pane->type = 'views';
  $pane->subtype = 'partner_content';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_pager_settings' => 0,
    'use_pager' => 0,
    'nodes_per_page' => '4',
    'pager_id' => '0',
    'offset' => '0',
    'more_link' => 0,
    'feed_icons' => 0,
    'panel_args' => 0,
    'link_to_view' => 0,
    'args' => '',
    'url' => '',
    'display' => 'latest_partner_news',
    'context' => array(
      0 => '',
    ),
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
  $pane->uuid = '58094813-4281-4753-b1e0-5e58a26999fb';
  $display->content['new-58094813-4281-4753-b1e0-5e58a26999fb'] = $pane;
  $display->panels['left_'][0] = 'new-58094813-4281-4753-b1e0-5e58a26999fb';
  $pane = new stdClass();
  $pane->pid = 'new-073236e5-2fb2-4d90-b25f-72c03c3545bc';
  $pane->panel = 'my_title';
  $pane->type = 'block';
  $pane->subtype = 'hwc_partner-hwc_partner_private_link_0';
  $pane->shown = TRUE;
  $pane->access = array(
    'plugins' => array(),
  );
  $pane->configuration = array(
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'span',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array(
    'css_id' => '',
    'css_class' => 'col-sm-3',
  );
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '073236e5-2fb2-4d90-b25f-72c03c3545bc';
  $display->content['new-073236e5-2fb2-4d90-b25f-72c03c3545bc'] = $pane;
  $display->panels['my_title'][0] = 'new-073236e5-2fb2-4d90-b25f-72c03c3545bc';
  $pane = new stdClass();
  $pane->pid = 'new-5bbbdd62-a5ac-4873-88f9-e44dca3b7ff8';
  $pane->panel = 'my_title';
  $pane->type = 'block';
  $pane->subtype = 'hwc_partner-hwc_partner_private_link_1';
  $pane->shown = TRUE;
  $pane->access = array(
    'plugins' => array(),
  );
  $pane->configuration = array(
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'span',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array(
    'css_id' => '',
    'css_class' => 'col-sm-3',
  );
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '5bbbdd62-a5ac-4873-88f9-e44dca3b7ff8';
  $display->content['new-5bbbdd62-a5ac-4873-88f9-e44dca3b7ff8'] = $pane;
  $display->panels['my_title'][1] = 'new-5bbbdd62-a5ac-4873-88f9-e44dca3b7ff8';
  $pane = new stdClass();
  $pane->pid = 'new-b441ca28-52c6-4cff-b30f-9c6d75feccf3';
  $pane->panel = 'my_title';
  $pane->type = 'block';
  $pane->subtype = 'hwc_partner-hwc_partner_private_link_2';
  $pane->shown = TRUE;
  $pane->access = array(
    'plugins' => array(),
  );
  $pane->configuration = array(
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'span',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array(
    'css_id' => '',
    'css_class' => 'col-sm-3',
  );
  $pane->extras = array();
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = 'b441ca28-52c6-4cff-b30f-9c6d75feccf3';
  $display->content['new-b441ca28-52c6-4cff-b30f-9c6d75feccf3'] = $pane;
  $display->panels['my_title'][2] = 'new-b441ca28-52c6-4cff-b30f-9c6d75feccf3';
  $pane = new stdClass();
  $pane->pid = 'new-d1910e7b-4e97-4602-b684-7bf4508801fc';
  $pane->panel = 'my_title';
  $pane->type = 'entity_field_extra';
  $pane->subtype = 'node:profile_update_link';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'view_mode' => 'full',
    'context' => 'argument_entity_id:node_1',
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
    'css_class' => 'col-sm-3',
  );
  $pane->extras = array();
  $pane->position = 3;
  $pane->locks = array();
  $pane->uuid = 'd1910e7b-4e97-4602-b684-7bf4508801fc';
  $display->content['new-d1910e7b-4e97-4602-b684-7bf4508801fc'] = $pane;
  $display->panels['my_title'][3] = 'new-d1910e7b-4e97-4602-b684-7bf4508801fc';
  $pane = new stdClass();
  $pane->pid = 'new-77d49695-6b92-49b7-8363-3f6421e99dd4';
  $pane->panel = 'my_title';
  $pane->type = 'custom_title_tag';
  $pane->subtype = 'custom_title_tag';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'buttons' => NULL,
    'custom_page_title_pattern' => '%node',
    'form_build_id' => 'form-kjidFUAEFsb6m4L_r4abX3kP_3hyR8MlkUK5U8KL2QI',
    'form_token' => 'E28-HqZOY91Hovvo90xKds8wBypNCBej7fXVPqyo1qA',
    'form_id' => 'panels_custom_title_tag_edit_form',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 4;
  $pane->locks = array();
  $pane->uuid = '77d49695-6b92-49b7-8363-3f6421e99dd4';
  $display->content['new-77d49695-6b92-49b7-8363-3f6421e99dd4'] = $pane;
  $display->panels['my_title'][4] = 'new-77d49695-6b92-49b7-8363-3f6421e99dd4';
  $pane = new stdClass();
  $pane->pid = 'new-5fe8a484-311e-4b4a-bc48-1b1243b77d51';
  $pane->panel = 'my_title';
  $pane->type = 'custom_title_tag';
  $pane->subtype = 'custom_title_tag';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'buttons' => NULL,
    'custom_page_title_pattern' => '%node:title',
    'form_build_id' => 'form-2vDmc-hX2JVi4-AgWkZvPJEixqUxE50UkGoG6reW5QY',
    'form_token' => 'E28-HqZOY91Hovvo90xKds8wBypNCBej7fXVPqyo1qA',
    'form_id' => 'panels_custom_title_tag_edit_form',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 5;
  $pane->locks = array();
  $pane->uuid = '5fe8a484-311e-4b4a-bc48-1b1243b77d51';
  $display->content['new-5fe8a484-311e-4b4a-bc48-1b1243b77d51'] = $pane;
  $display->panels['my_title'][5] = 'new-5fe8a484-311e-4b4a-bc48-1b1243b77d51';
  $pane = new stdClass();
  $pane->pid = 'new-0b4279c4-f4de-431f-9738-30d53b5790f0';
  $pane->panel = 'region';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_logo';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'hidden',
    'formatter' => 'image',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(
      'image_style' => 'medium',
      'image_link' => '',
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
  $pane->uuid = '0b4279c4-f4de-431f-9738-30d53b5790f0';
  $display->content['new-0b4279c4-f4de-431f-9738-30d53b5790f0'] = $pane;
  $display->panels['region'][0] = 'new-0b4279c4-f4de-431f-9738-30d53b5790f0';
  $pane = new stdClass();
  $pane->pid = 'new-ac9c93c6-d4fe-44bb-9888-a4551b9c5af2';
  $pane->panel = 'region_1_2';
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
      'title_style' => '_none',
      'title_link' => '',
      'title_class' => '',
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
  $pane->uuid = 'ac9c93c6-d4fe-44bb-9888-a4551b9c5af2';
  $display->content['new-ac9c93c6-d4fe-44bb-9888-a4551b9c5af2'] = $pane;
  $display->panels['region_1_2'][0] = 'new-ac9c93c6-d4fe-44bb-9888-a4551b9c5af2';
  $pane = new stdClass();
  $pane->pid = 'new-d05c7360-62ae-4b57-a2fa-af756b871d17';
  $pane->panel = 'region_1_2';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_ph_address';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'hidden',
    'formatter' => 'title_linked',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(
      'title_style' => '_none',
      'title_link' => '',
      'title_class' => '',
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
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = 'd05c7360-62ae-4b57-a2fa-af756b871d17';
  $display->content['new-d05c7360-62ae-4b57-a2fa-af756b871d17'] = $pane;
  $display->panels['region_1_2'][1] = 'new-d05c7360-62ae-4b57-a2fa-af756b871d17';
  $pane = new stdClass();
  $pane->pid = 'new-e36dcb73-9189-40e8-acaa-bdd2574c9377';
  $pane->panel = 'region_1_2';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_ph_cp';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'hidden',
    'formatter' => 'title_linked',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(
      'title_style' => '_none',
      'title_link' => '',
      'title_class' => '',
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
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = 'e36dcb73-9189-40e8-acaa-bdd2574c9377';
  $display->content['new-e36dcb73-9189-40e8-acaa-bdd2574c9377'] = $pane;
  $display->panels['region_1_2'][2] = 'new-e36dcb73-9189-40e8-acaa-bdd2574c9377';
  $pane = new stdClass();
  $pane->pid = 'new-f6e8ddd1-fd7c-49ef-ab9f-f75e3ed8adbf';
  $pane->panel = 'region_1_2';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_ph_town';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'hidden',
    'formatter' => 'text_plain',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(),
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
  $pane->position = 3;
  $pane->locks = array();
  $pane->uuid = 'f6e8ddd1-fd7c-49ef-ab9f-f75e3ed8adbf';
  $display->content['new-f6e8ddd1-fd7c-49ef-ab9f-f75e3ed8adbf'] = $pane;
  $display->panels['region_1_2'][3] = 'new-f6e8ddd1-fd7c-49ef-ab9f-f75e3ed8adbf';
  $pane = new stdClass();
  $pane->pid = 'new-ad3a6d34-f4fa-4fe0-bfc8-5fa8c9c397ec';
  $pane->panel = 'region_1_2';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_country';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'hidden',
    'formatter' => 'i18n_taxonomy_term_reference_plain',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(),
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
  $pane->position = 4;
  $pane->locks = array();
  $pane->uuid = 'ad3a6d34-f4fa-4fe0-bfc8-5fa8c9c397ec';
  $display->content['new-ad3a6d34-f4fa-4fe0-bfc8-5fa8c9c397ec'] = $pane;
  $display->panels['region_1_2'][4] = 'new-ad3a6d34-f4fa-4fe0-bfc8-5fa8c9c397ec';
  $pane = new stdClass();
  $pane->pid = 'new-b4c58a13-6a77-4758-a4e7-522b788832e0';
  $pane->panel = 'region_2';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_general_email';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'hidden',
    'formatter' => 'email_spamspan',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(),
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
  $pane->uuid = 'b4c58a13-6a77-4758-a4e7-522b788832e0';
  $display->content['new-b4c58a13-6a77-4758-a4e7-522b788832e0'] = $pane;
  $display->panels['region_2'][0] = 'new-b4c58a13-6a77-4758-a4e7-522b788832e0';
  $pane = new stdClass();
  $pane->pid = 'new-eb585847-4795-4b6d-9822-25da45177327';
  $pane->panel = 'region_2';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_website';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'hidden',
    'formatter' => 'link_default',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(),
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
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = 'eb585847-4795-4b6d-9822-25da45177327';
  $display->content['new-eb585847-4795-4b6d-9822-25da45177327'] = $pane;
  $display->panels['region_2'][1] = 'new-eb585847-4795-4b6d-9822-25da45177327';
  $pane = new stdClass();
  $pane->pid = 'new-55e46dc6-cbe6-47b9-9228-2dbb98c6c582';
  $pane->panel = 'region_2';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_general_phone';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'inline',
    'formatter' => 'title_linked',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(
      'title_style' => '_none',
      'title_link' => '',
      'title_class' => '',
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
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = '55e46dc6-cbe6-47b9-9228-2dbb98c6c582';
  $display->content['new-55e46dc6-cbe6-47b9-9228-2dbb98c6c582'] = $pane;
  $display->panels['region_2'][2] = 'new-55e46dc6-cbe6-47b9-9228-2dbb98c6c582';
  $pane = new stdClass();
  $pane->pid = 'new-249112dd-020c-473e-87b5-653d3edd5346';
  $pane->panel = 'region_2';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_main_contact';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'inline',
    'formatter' => 'title_linked',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(
      'title_style' => '_none',
      'title_link' => '',
      'title_class' => '',
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
  $pane->position = 3;
  $pane->locks = array();
  $pane->uuid = '249112dd-020c-473e-87b5-653d3edd5346';
  $display->content['new-249112dd-020c-473e-87b5-653d3edd5346'] = $pane;
  $display->panels['region_2'][3] = 'new-249112dd-020c-473e-87b5-653d3edd5346';
  $pane = new stdClass();
  $pane->pid = 'new-5e358fee-9379-47e5-9dc7-898a5572db4c';
  $pane->panel = 'region_2';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_organisation_rep';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'above',
    'formatter' => 'text_plain',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(),
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
  $pane->position = 4;
  $pane->locks = array();
  $pane->uuid = '5e358fee-9379-47e5-9dc7-898a5572db4c';
  $display->content['new-5e358fee-9379-47e5-9dc7-898a5572db4c'] = $pane;
  $display->panels['region_2'][4] = 'new-5e358fee-9379-47e5-9dc7-898a5572db4c';
  $pane = new stdClass();
  $pane->pid = 'new-63f4624d-dc9c-4071-8a5e-784a6a4c42f3';
  $pane->panel = 'region_3';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = TRUE;
  $pane->access = array(
    'plugins' => array(
      0 => array(
        'name' => 'php',
        'settings' => array(
          'description' => 'has any profile added',
          'php' => '$data = $contexts[\'argument_entity_id:node_1\']->data;
return (!empty($data->field_facebook_profile) || !empty($data->field_linkedin_profile) ||
        !empty($data->field_slideshare_profile) || !empty($data->field_twitter_profile) ||
        !empty($data->field_youtube_profile));',
        ),
        'not' => FALSE,
      ),
    ),
  );
  $pane->configuration = array(
    'admin_title' => 'Social media profiles title',
    'title' => '',
    'body' => '<p>Social media profiles</p>',
    'format' => 'full_html',
    'substitute' => 1,
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '63f4624d-dc9c-4071-8a5e-784a6a4c42f3';
  $display->content['new-63f4624d-dc9c-4071-8a5e-784a6a4c42f3'] = $pane;
  $display->panels['region_3'][0] = 'new-63f4624d-dc9c-4071-8a5e-784a6a4c42f3';
  $pane = new stdClass();
  $pane->pid = 'new-4aa2b7f8-2742-4819-8198-1451447d6d17';
  $pane->panel = 'region_3';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_facebook_profile';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'hidden',
    'formatter' => 'link_url',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(),
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
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '4aa2b7f8-2742-4819-8198-1451447d6d17';
  $display->content['new-4aa2b7f8-2742-4819-8198-1451447d6d17'] = $pane;
  $display->panels['region_3'][1] = 'new-4aa2b7f8-2742-4819-8198-1451447d6d17';
  $pane = new stdClass();
  $pane->pid = 'new-ec16d60a-9d23-4140-ab63-d2be45264ae1';
  $pane->panel = 'region_3';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_twitter_profile';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'hidden',
    'formatter' => 'link_url',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(),
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
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = 'ec16d60a-9d23-4140-ab63-d2be45264ae1';
  $display->content['new-ec16d60a-9d23-4140-ab63-d2be45264ae1'] = $pane;
  $display->panels['region_3'][2] = 'new-ec16d60a-9d23-4140-ab63-d2be45264ae1';
  $pane = new stdClass();
  $pane->pid = 'new-e2ca4501-827a-4e8d-8607-5c15b92cc80a';
  $pane->panel = 'region_3';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_linkedin_profile';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'hidden',
    'formatter' => 'link_url',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(),
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
  $pane->position = 3;
  $pane->locks = array();
  $pane->uuid = 'e2ca4501-827a-4e8d-8607-5c15b92cc80a';
  $display->content['new-e2ca4501-827a-4e8d-8607-5c15b92cc80a'] = $pane;
  $display->panels['region_3'][3] = 'new-e2ca4501-827a-4e8d-8607-5c15b92cc80a';
  $pane = new stdClass();
  $pane->pid = 'new-ded8085b-914b-4ea5-9480-b2180cbe3902';
  $pane->panel = 'region_3';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_youtube_profile';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'hidden',
    'formatter' => 'link_url',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(),
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
  $pane->position = 4;
  $pane->locks = array();
  $pane->uuid = 'ded8085b-914b-4ea5-9480-b2180cbe3902';
  $display->content['new-ded8085b-914b-4ea5-9480-b2180cbe3902'] = $pane;
  $display->panels['region_3'][4] = 'new-ded8085b-914b-4ea5-9480-b2180cbe3902';
  $pane = new stdClass();
  $pane->pid = 'new-7515db16-a606-4317-8f88-f4d324a87e4c';
  $pane->panel = 'region_3';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_slideshare_profile';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'hidden',
    'formatter' => 'link_url',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(),
    'context' => 'argument_entity_id:node_1',
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
    'css_class' => '',
  );
  $pane->extras = array();
  $pane->position = 5;
  $pane->locks = array();
  $pane->uuid = '7515db16-a606-4317-8f88-f4d324a87e4c';
  $display->content['new-7515db16-a606-4317-8f88-f4d324a87e4c'] = $pane;
  $display->panels['region_3'][5] = 'new-7515db16-a606-4317-8f88-f4d324a87e4c';
  $pane = new stdClass();
  $pane->pid = 'new-87db9652-50d0-4628-a310-d794ddcdac68';
  $pane->panel = 'region_3';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_google_plus_profile';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'hidden',
    'formatter' => 'link_url',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(),
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
  $pane->position = 6;
  $pane->locks = array();
  $pane->uuid = '87db9652-50d0-4628-a310-d794ddcdac68';
  $display->content['new-87db9652-50d0-4628-a310-d794ddcdac68'] = $pane;
  $display->panels['region_3'][6] = 'new-87db9652-50d0-4628-a310-d794ddcdac68';
  $pane = new stdClass();
  $pane->pid = 'new-f3313101-db0d-4f66-97fe-0b81beefbd61';
  $pane->panel = 'region_3';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_pinterest_profile';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'hidden',
    'formatter' => 'link_url',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(),
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
  $pane->position = 7;
  $pane->locks = array();
  $pane->uuid = 'f3313101-db0d-4f66-97fe-0b81beefbd61';
  $display->content['new-f3313101-db0d-4f66-97fe-0b81beefbd61'] = $pane;
  $display->panels['region_3'][7] = 'new-f3313101-db0d-4f66-97fe-0b81beefbd61';
  $pane = new stdClass();
  $pane->pid = 'new-a41e4732-07fd-4b8a-badc-4362afc1bdf1';
  $pane->panel = 'right';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_pledge';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'above',
    'formatter' => 'text_default',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(),
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
  $pane->uuid = 'a41e4732-07fd-4b8a-badc-4362afc1bdf1';
  $display->content['new-a41e4732-07fd-4b8a-badc-4362afc1bdf1'] = $pane;
  $display->panels['right'][0] = 'new-a41e4732-07fd-4b8a-badc-4362afc1bdf1';
  $pane = new stdClass();
  $pane->pid = 'new-22050c50-2a04-49d6-b147-ee7e3f0b7183';
  $pane->panel = 'right_';
  $pane->type = 'views';
  $pane->subtype = 'partner_content';
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
    'display' => 'latest_partner_events',
    'context' => array(
      0 => '',
    ),
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
  $pane->uuid = '22050c50-2a04-49d6-b147-ee7e3f0b7183';
  $display->content['new-22050c50-2a04-49d6-b147-ee7e3f0b7183'] = $pane;
  $display->panels['right_'][0] = 'new-22050c50-2a04-49d6-b147-ee7e3f0b7183';
  $pane = new stdClass();
  $pane->pid = 'new-152fad72-a7ac-4e0a-ad19-5c1c02d86057';
  $pane->panel = 'right_';
  $pane->type = 'views';
  $pane->subtype = 'partner_content';
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
    'display' => 'past_events',
    'context' => array(
      0 => '',
    ),
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
  $pane->uuid = '152fad72-a7ac-4e0a-ad19-5c1c02d86057';
  $display->content['new-152fad72-a7ac-4e0a-ad19-5c1c02d86057'] = $pane;
  $display->panels['right_'][1] = 'new-152fad72-a7ac-4e0a-ad19-5c1c02d86057';
  $display->hide_title = PANELS_TITLE_NONE;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['node_view__panel_context_d109f4e3-27a8-4bfa-922c-690f8fc7a2eb'] = $handler;

  return $export;
}

/**
 * Implements hook_default_page_manager_pages().
 */
function hwc_partner_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'focal_points';
  $page->task = 'page';
  $page->admin_title = 'Focal points';
  $page->admin_description = '';
  $page->path = 'national-focal-points';
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
  $handler->name = 'page_focal_points__panel_context_d5bef590-8713-4420-adfd-59a80c7e01ff';
  $handler->task = 'page';
  $handler->subtask = 'focal_points';
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
        'identifier' => 'Node',
        'keyword' => 'node',
        'name' => 'entity:node',
        'entity_id' => '144',
        'id' => 1,
      ),
    ),
    'relationships' => array(),
    'panels_breadcrumbs_state' => 1,
    'panels_breadcrumbs_titles' => 'Campaign partners
%node:title',
    'panels_breadcrumbs_paths' => '<none>
<none>',
    'panels_breadcrumbs_home' => 1,
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
  $display->uuid = '309b0809-de1a-4b4b-a6a2-c7348a10473e';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_focal_points__panel_context_d5bef590-8713-4420-adfd-59a80c7e01ff';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-0c8d58fe-68d1-436a-b7f7-b75c6552e08a';
  $pane->panel = 'center';
  $pane->type = 'node';
  $pane->subtype = 'node';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'nid' => '144',
    'links' => 1,
    'leave_node_title' => 0,
    'identifier' => '',
    'build_mode' => 'full',
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
    'css_class' => 'section-introduction',
  );
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '0c8d58fe-68d1-436a-b7f7-b75c6552e08a';
  $display->content['new-0c8d58fe-68d1-436a-b7f7-b75c6552e08a'] = $pane;
  $display->panels['center'][0] = 'new-0c8d58fe-68d1-436a-b7f7-b75c6552e08a';
  $pane = new stdClass();
  $pane->pid = 'new-407b7c05-bbc4-4dde-bd2c-c3e85b46bbeb';
  $pane->panel = 'center';
  $pane->type = 'views';
  $pane->subtype = 'partners_list';
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
    'display' => 'fop',
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
  $pane->uuid = '407b7c05-bbc4-4dde-bd2c-c3e85b46bbeb';
  $display->content['new-407b7c05-bbc4-4dde-bd2c-c3e85b46bbeb'] = $pane;
  $display->panels['center'][1] = 'new-407b7c05-bbc4-4dde-bd2c-c3e85b46bbeb';
  $pane = new stdClass();
  $pane->pid = 'new-9a79a03d-1572-4ef5-82a1-aea455e0972c';
  $pane->panel = 'center';
  $pane->type = 'custom_title_tag';
  $pane->subtype = 'custom_title_tag';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'buttons' => NULL,
    'custom_page_title_pattern' => '%node:title',
    'form_build_id' => 'form-slidqZo2NxmB4JitHzto3MND_sp6boRYCc8D40Ywv4c',
    'form_token' => 'ZbBYL1j24ApA7wrPsMGYHWVGppvtWwlf0afDvG03t0c',
    'form_id' => 'panels_custom_title_tag_edit_form',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = '9a79a03d-1572-4ef5-82a1-aea455e0972c';
  $display->content['new-9a79a03d-1572-4ef5-82a1-aea455e0972c'] = $pane;
  $display->panels['center'][2] = 'new-9a79a03d-1572-4ef5-82a1-aea455e0972c';
  $display->hide_title = PANELS_TITLE_NONE;
  $display->title_pane = 'new-0c8d58fe-68d1-436a-b7f7-b75c6552e08a';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['focal_points'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'mop_listing';
  $page->task = 'page';
  $page->admin_title = 'Mop listing';
  $page->admin_description = '';
  $page->path = 'campaign-media-partners';
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
  $handler->name = 'page_mop_listing__panel_context_b88e3b2b-6000-453d-aa0f-4692c573b1b8';
  $handler->task = 'page';
  $handler->subtask = 'mop_listing';
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
        'identifier' => 'Node',
        'keyword' => 'node',
        'name' => 'entity:node',
        'entity_id' => '146',
        'id' => 1,
      ),
    ),
    'relationships' => array(),
    'panels_breadcrumbs_state' => 1,
    'panels_breadcrumbs_titles' => 'Campaign partners
%node:title',
    'panels_breadcrumbs_paths' => '<none>
<none>',
    'panels_breadcrumbs_home' => 1,
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
  $display->uuid = 'da34706d-0794-448b-91af-d2a5aa21fbc9';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_mop_listing__panel_context_b88e3b2b-6000-453d-aa0f-4692c573b1b8';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-298c132d-2b95-4097-9630-de0ec0f29a56';
  $pane->panel = 'center';
  $pane->type = 'node';
  $pane->subtype = 'node';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'nid' => '146',
    'links' => 0,
    'leave_node_title' => 0,
    'identifier' => '',
    'build_mode' => 'full',
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
    'css_class' => 'section-introduction',
  );
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '298c132d-2b95-4097-9630-de0ec0f29a56';
  $display->content['new-298c132d-2b95-4097-9630-de0ec0f29a56'] = $pane;
  $display->panels['center'][0] = 'new-298c132d-2b95-4097-9630-de0ec0f29a56';
  $pane = new stdClass();
  $pane->pid = 'new-016804e1-e5d1-47a6-b457-29c018a96f26';
  $pane->panel = 'center';
  $pane->type = 'views';
  $pane->subtype = 'partners_list';
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
  $pane->uuid = '016804e1-e5d1-47a6-b457-29c018a96f26';
  $display->content['new-016804e1-e5d1-47a6-b457-29c018a96f26'] = $pane;
  $display->panels['center'][1] = 'new-016804e1-e5d1-47a6-b457-29c018a96f26';
  $pane = new stdClass();
  $pane->pid = 'new-701d310f-6b59-436e-a493-cd634012523e';
  $pane->panel = 'center';
  $pane->type = 'custom_title_tag';
  $pane->subtype = 'custom_title_tag';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'buttons' => NULL,
    'custom_page_title_pattern' => '%node:title',
    'form_build_id' => 'form-PnhuJgzAquw1WhKIAR-1bmiORls4fGlPgMT2-BKRr-Y',
    'form_token' => 'ZbBYL1j24ApA7wrPsMGYHWVGppvtWwlf0afDvG03t0c',
    'form_id' => 'panels_custom_title_tag_edit_form',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = '701d310f-6b59-436e-a493-cd634012523e';
  $display->content['new-701d310f-6b59-436e-a493-cd634012523e'] = $pane;
  $display->panels['center'][2] = 'new-701d310f-6b59-436e-a493-cd634012523e';
  $display->hide_title = PANELS_TITLE_NONE;
  $display->title_pane = 'new-298c132d-2b95-4097-9630-de0ec0f29a56';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['mop_listing'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'not_published_events';
  $page->task = 'page';
  $page->admin_title = 'Not published events';
  $page->admin_description = 'List of draft events per partner';
  $page->path = 'node/%node/events';
  $page->access = array(
    'plugins' => array(
      0 => array(
        'name' => 'role',
        'settings' => array(
          'rids' => array(
            0 => 12,
          ),
        ),
        'context' => 'logged-in-user',
        'not' => FALSE,
      ),
      1 => array(
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
    'logic' => 'or',
    'type' => 'none',
    'settings' => NULL,
  );
  $page->menu = array();
  $page->arguments = array(
    'node' => array(
      'id' => 1,
      'identifier' => 'Node: ID',
      'name' => 'entity_id:node',
      'settings' => array(),
    ),
  );
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_not_published_events__panel';
  $handler->task = 'page';
  $handler->subtask = 'not_published_events';
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
    'name' => 'panel',
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
  $display->uuid = 'e689fe20-80e7-4066-b9bf-07e64257e54c';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_not_published_events__panel';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-82de0d01-543a-4f9f-aef5-7fc99c76fb68';
  $pane->panel = 'center';
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
      'title_link' => 'content',
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
  $pane->uuid = '82de0d01-543a-4f9f-aef5-7fc99c76fb68';
  $display->content['new-82de0d01-543a-4f9f-aef5-7fc99c76fb68'] = $pane;
  $display->panels['center'][0] = 'new-82de0d01-543a-4f9f-aef5-7fc99c76fb68';
  $pane = new stdClass();
  $pane->pid = 'new-ee11c62b-e8db-4c1d-a6a0-491156657f9e';
  $pane->panel = 'center';
  $pane->type = 'views';
  $pane->subtype = 'partner_draft_content';
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
    'args' => '%1',
    'url' => '',
    'display' => 'block_partner_draft_events',
    'context' => array(
      0 => '',
    ),
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
  $pane->uuid = 'ee11c62b-e8db-4c1d-a6a0-491156657f9e';
  $display->content['new-ee11c62b-e8db-4c1d-a6a0-491156657f9e'] = $pane;
  $display->panels['center'][1] = 'new-ee11c62b-e8db-4c1d-a6a0-491156657f9e';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-82de0d01-543a-4f9f-aef5-7fc99c76fb68';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['not_published_events'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'not_published_news';
  $page->task = 'page';
  $page->admin_title = 'Not published news';
  $page->admin_description = 'List of draft news per partner';
  $page->path = 'node/%node/news';
  $page->access = array(
    'plugins' => array(
      0 => array(
        'name' => 'role',
        'settings' => array(
          'rids' => array(
            0 => 12,
          ),
        ),
        'context' => 'logged-in-user',
        'not' => FALSE,
      ),
      1 => array(
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
    'logic' => 'or',
    'type' => 'none',
    'settings' => NULL,
  );
  $page->menu = array();
  $page->arguments = array(
    'node' => array(
      'id' => 1,
      'identifier' => 'Node: ID',
      'name' => 'entity_id:node',
      'settings' => array(),
    ),
  );
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_not_published_news__panel';
  $handler->task = 'page';
  $handler->subtask = 'not_published_news';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Not published news panel page',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'name' => 'panel',
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
  $display->uuid = '25db9deb-a748-40fb-8efd-2aa2807aa2c6';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_not_published_news__panel';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-43dc0335-e792-4884-9be8-0fe5bc86180d';
  $pane->panel = 'center';
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
      'title_link' => 'content',
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
  $pane->uuid = '43dc0335-e792-4884-9be8-0fe5bc86180d';
  $display->content['new-43dc0335-e792-4884-9be8-0fe5bc86180d'] = $pane;
  $display->panels['center'][0] = 'new-43dc0335-e792-4884-9be8-0fe5bc86180d';
  $pane = new stdClass();
  $pane->pid = 'new-70d232a3-c541-48ba-a043-2b591b8bfb71';
  $pane->panel = 'center';
  $pane->type = 'views';
  $pane->subtype = 'partner_draft_content';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_pager_settings' => 0,
    'use_pager' => 1,
    'nodes_per_page' => '25',
    'pager_id' => '0',
    'offset' => '0',
    'more_link' => 0,
    'feed_icons' => 0,
    'panel_args' => 0,
    'link_to_view' => 0,
    'args' => '%1',
    'url' => '',
    'display' => 'page_1',
    'context' => array(
      0 => '',
    ),
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
  $pane->uuid = '70d232a3-c541-48ba-a043-2b591b8bfb71';
  $display->content['new-70d232a3-c541-48ba-a043-2b591b8bfb71'] = $pane;
  $display->panels['center'][1] = 'new-70d232a3-c541-48ba-a043-2b591b8bfb71';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['not_published_news'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'official_campaign_partners';
  $page->task = 'page';
  $page->admin_title = 'Official campaign partners';
  $page->admin_description = '';
  $page->path = 'official-campaign-partners';
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
  $handler->name = 'page_official_campaign_partners__panel_context_63e3852f-e4af-4bad-b681-7f57793dc362';
  $handler->task = 'page';
  $handler->subtask = 'official_campaign_partners';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Official campaign partners',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(
      0 => array(
        'identifier' => 'Node',
        'keyword' => 'node',
        'name' => 'entity:node',
        'entity_id' => '145',
        'id' => 1,
      ),
    ),
    'relationships' => array(),
    'panels_breadcrumbs_state' => 1,
    'panels_breadcrumbs_titles' => 'Campaign partners
%node:title',
    'panels_breadcrumbs_paths' => '<none>
<none>',
    'panels_breadcrumbs_home' => 1,
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
  $display->uuid = '95b72608-23a5-4cbb-9515-c9630ab46b6d';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_official_campaign_partners__panel_context_63e3852f-e4af-4bad-b681-7f57793dc362';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-de95302f-4ecf-4b9a-a105-e3a74864b930';
  $pane->panel = 'center';
  $pane->type = 'node';
  $pane->subtype = 'node';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'nid' => '145',
    'links' => 0,
    'leave_node_title' => 0,
    'identifier' => '',
    'build_mode' => 'full',
    'link_node_title' => 0,
    'override_title' => 1,
    'override_title_text' => '',
    'override_title_heading' => 'h1',
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
  $pane->uuid = 'de95302f-4ecf-4b9a-a105-e3a74864b930';
  $display->content['new-de95302f-4ecf-4b9a-a105-e3a74864b930'] = $pane;
  $display->panels['center'][0] = 'new-de95302f-4ecf-4b9a-a105-e3a74864b930';
  $pane = new stdClass();
  $pane->pid = 'new-e74c6e69-67c7-41d8-8206-046d8e5dda78';
  $pane->panel = 'center';
  $pane->type = 'views';
  $pane->subtype = 'partners_list';
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
    'display' => 'block',
    'override_title' => 1,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array(
    'css_id' => 'block-views-partners-list-block',
    'css_class' => '',
  );
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = 'e74c6e69-67c7-41d8-8206-046d8e5dda78';
  $display->content['new-e74c6e69-67c7-41d8-8206-046d8e5dda78'] = $pane;
  $display->panels['center'][1] = 'new-e74c6e69-67c7-41d8-8206-046d8e5dda78';
  $pane = new stdClass();
  $pane->pid = 'new-ba8c52bc-97cd-4947-9e85-ef22a7b6ad2a';
  $pane->panel = 'center';
  $pane->type = 'custom_title_tag';
  $pane->subtype = 'custom_title_tag';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'buttons' => NULL,
    'custom_page_title_pattern' => '%node:title',
    'form_build_id' => 'form-QNyjzXzeG_bGO83zyYa_-SA5u797GuA5M2t9ARQkwD4',
    'form_token' => 'ZbBYL1j24ApA7wrPsMGYHWVGppvtWwlf0afDvG03t0c',
    'form_id' => 'panels_custom_title_tag_edit_form',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = 'ba8c52bc-97cd-4947-9e85-ef22a7b6ad2a';
  $display->content['new-ba8c52bc-97cd-4947-9e85-ef22a7b6ad2a'] = $pane;
  $display->panels['center'][2] = 'new-ba8c52bc-97cd-4947-9e85-ef22a7b6ad2a';
  $display->hide_title = PANELS_TITLE_NONE;
  $display->title_pane = 'new-de95302f-4ecf-4b9a-a105-e3a74864b930';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['official_campaign_partners'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'partner_private_area';
  $page->task = 'page';
  $page->admin_title = 'Partner private area';
  $page->admin_description = '';
  $page->path = 'partner-private-area';
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
  $handler->name = 'page_partner_private_area__panel_context_912ffcf8-bbee-4af1-ac2a-13bd4c8b9a39';
  $handler->task = 'page';
  $handler->subtask = 'partner_private_area';
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
  $display->title = 'Partner Resources';
  $display->uuid = '4b43886a-a2f0-48cd-be03-5def9eac6bc0';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_partner_private_area__panel_context_912ffcf8-bbee-4af1-ac2a-13bd4c8b9a39';
  $display->content = array();
  $display->panels = array();
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['partner_private_area'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'partner_public_profile';
  $page->task = 'page';
  $page->admin_title = 'Partner profile';
  $page->admin_description = '';
  $page->path = 'partner-profile/%node';
  $page->access = array(
    'type' => 'none',
    'settings' => NULL,
  );
  $page->menu = array();
  $page->arguments = array(
    'node' => array(
      'id' => 1,
      'identifier' => 'Node: ID',
      'name' => 'entity_id:node',
      'settings' => array(),
    ),
  );
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_partner_public_profile__panel_context_9784121b-bc57-4d0b-915c-c11d738c0639';
  $handler->task = 'page';
  $handler->subtask = 'partner_public_profile';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Profile',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'partner' => 'partner',
            ),
          ),
          'context' => 'argument_entity_id:node_1',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
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
  $display->uuid = '536f07b4-59cc-4e7d-84b4-3635ebb5aa94';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_partner_public_profile__panel_context_9784121b-bc57-4d0b-915c-c11d738c0639';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-7cd8edd0-19f2-4250-84a6-6e113567d2d8';
  $pane->panel = 'center';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = TRUE;
  $pane->access = array(
    'plugins' => array(
      0 => array(
        'name' => 'role',
        'settings' => array(
          'rids' => array(
            0 => 2,
          ),
        ),
        'context' => 'logged-in-user',
        'not' => FALSE,
      ),
      1 => array(
        'name' => 'php',
        'settings' => array(
          'description' => 'Logged user in Partner users (not finished)',
          'php' => 'return TRUE;
foreach( $contexts[\'argument_entity_id:node_1\']->data->field_users[\'und\'] as $key => $value) { $array []= $value[\'target_id\']; } return in_array($contexts[\'logged-in-user\']->data->uid ,$array);
',
        ),
        'not' => FALSE,
      ),
    ),
  );
  $pane->configuration = array(
    'admin_title' => 'Private links',
    'title' => '',
    'body' => '<div class="row"><div class="col-xs-4 text-center"><a href="#">Create an event</a> <br /> <span>Do you want to propose an event in the context of our current Healthy Workplaces Campaign? <a href="#">Click here</a></span><p><a href="events">Not published events</a></p></div><div class="col-xs-4 text-center"><a href="#">Create news</a> <br /> <span>Do you want to share with us the latest news about our organisation in the context of our current Healthy Workplaces Campaign? <a href="#">Click here</a></span><p><a href="news">Not published news</a></p></div><div class="col-xs-4 text-center"><a href="partner-private-area">Private area</a> <br /> <span>Find the latest files to help you engage in the Campaign.</span></div></div><div class="row"><div class="col-xs-12"><h2>Your public profile</h2><span class="pull-right"><a href="#">Update</a></span></div></div>',
    'format' => 'full_html',
    'substitute' => 0,
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '7cd8edd0-19f2-4250-84a6-6e113567d2d8';
  $display->content['new-7cd8edd0-19f2-4250-84a6-6e113567d2d8'] = $pane;
  $display->panels['center'][0] = 'new-7cd8edd0-19f2-4250-84a6-6e113567d2d8';
  $pane = new stdClass();
  $pane->pid = 'new-21193c9b-bdf0-46b9-8120-f1d3781f045d';
  $pane->panel = 'center';
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
      'title_style' => '_none',
      'title_link' => '',
      'title_class' => '',
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
  $pane->uuid = '21193c9b-bdf0-46b9-8120-f1d3781f045d';
  $display->content['new-21193c9b-bdf0-46b9-8120-f1d3781f045d'] = $pane;
  $display->panels['center'][1] = 'new-21193c9b-bdf0-46b9-8120-f1d3781f045d';
  $pane = new stdClass();
  $pane->pid = 'new-2f8ed0d0-aabd-40cc-8d5f-2dcd30d81957';
  $pane->panel = 'center';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_orgtype';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'hidden',
    'formatter' => 'title_linked',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(
      'title_style' => '_none',
      'title_link' => '',
      'title_class' => '',
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
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = '2f8ed0d0-aabd-40cc-8d5f-2dcd30d81957';
  $display->content['new-2f8ed0d0-aabd-40cc-8d5f-2dcd30d81957'] = $pane;
  $display->panels['center'][2] = 'new-2f8ed0d0-aabd-40cc-8d5f-2dcd30d81957';
  $pane = new stdClass();
  $pane->pid = 'new-91027b2b-a9f8-4c30-84cf-608524bd44cd';
  $pane->panel = 'center';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_bussines_sector';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'hidden',
    'formatter' => 'title_linked',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(
      'title_style' => '_none',
      'title_link' => '',
      'title_class' => '',
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
  $pane->position = 3;
  $pane->locks = array();
  $pane->uuid = '91027b2b-a9f8-4c30-84cf-608524bd44cd';
  $display->content['new-91027b2b-a9f8-4c30-84cf-608524bd44cd'] = $pane;
  $display->panels['center'][3] = 'new-91027b2b-a9f8-4c30-84cf-608524bd44cd';
  $pane = new stdClass();
  $pane->pid = 'new-2c5384eb-8241-4cbf-a6b5-aeb3a1a40523';
  $pane->panel = 'center';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_website';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'hidden',
    'formatter' => 'link_default',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(),
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
  $pane->position = 4;
  $pane->locks = array();
  $pane->uuid = '2c5384eb-8241-4cbf-a6b5-aeb3a1a40523';
  $display->content['new-2c5384eb-8241-4cbf-a6b5-aeb3a1a40523'] = $pane;
  $display->panels['center'][4] = 'new-2c5384eb-8241-4cbf-a6b5-aeb3a1a40523';
  $pane = new stdClass();
  $pane->pid = 'new-644faa7b-274b-41e6-b1d0-f7df567e91b6';
  $pane->panel = 'center';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_ceo_photo';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'hidden',
    'formatter' => 'image',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(
      'image_style' => 'medium',
      'image_link' => '',
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
  $pane->position = 5;
  $pane->locks = array();
  $pane->uuid = '644faa7b-274b-41e6-b1d0-f7df567e91b6';
  $display->content['new-644faa7b-274b-41e6-b1d0-f7df567e91b6'] = $pane;
  $display->panels['center'][5] = 'new-644faa7b-274b-41e6-b1d0-f7df567e91b6';
  $pane = new stdClass();
  $pane->pid = 'new-1ffdd101-4abb-456f-a821-37d48bea82a3';
  $pane->panel = 'center';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_ceo';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'hidden',
    'formatter' => 'title_linked',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(
      'title_style' => '_none',
      'title_link' => '',
      'title_class' => '',
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
  $pane->position = 6;
  $pane->locks = array();
  $pane->uuid = '1ffdd101-4abb-456f-a821-37d48bea82a3';
  $display->content['new-1ffdd101-4abb-456f-a821-37d48bea82a3'] = $pane;
  $display->panels['center'][6] = 'new-1ffdd101-4abb-456f-a821-37d48bea82a3';
  $pane = new stdClass();
  $pane->pid = 'new-77cc5bf8-5bbc-40ce-8d91-e31ff9f96577';
  $pane->panel = 'center';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_mission_statement';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'above',
    'formatter' => 'text_default',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(),
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
  $pane->position = 7;
  $pane->locks = array();
  $pane->uuid = '77cc5bf8-5bbc-40ce-8d91-e31ff9f96577';
  $display->content['new-77cc5bf8-5bbc-40ce-8d91-e31ff9f96577'] = $pane;
  $display->panels['center'][7] = 'new-77cc5bf8-5bbc-40ce-8d91-e31ff9f96577';
  $pane = new stdClass();
  $pane->pid = 'new-cb32a0f3-6862-4976-bc53-e63d63d63c4d';
  $pane->panel = 'center';
  $pane->type = 'views';
  $pane->subtype = 'news';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_pager_settings' => 0,
    'use_pager' => 0,
    'nodes_per_page' => '4',
    'pager_id' => '0',
    'offset' => '0',
    'more_link' => 0,
    'feed_icons' => 0,
    'panel_args' => 0,
    'link_to_view' => 0,
    'args' => '',
    'url' => '',
    'display' => 'oshnews_latest',
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
  $pane->position = 8;
  $pane->locks = array();
  $pane->uuid = 'cb32a0f3-6862-4976-bc53-e63d63d63c4d';
  $display->content['new-cb32a0f3-6862-4976-bc53-e63d63d63c4d'] = $pane;
  $display->panels['center'][8] = 'new-cb32a0f3-6862-4976-bc53-e63d63d63c4d';
  $pane = new stdClass();
  $pane->pid = 'new-0b4279c4-f4de-431f-9738-30d53b5790f0';
  $pane->panel = 'center';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_logo';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'hidden',
    'formatter' => 'image',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(
      'image_style' => 'medium',
      'image_link' => '',
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
  $pane->position = 9;
  $pane->locks = array();
  $pane->uuid = '0b4279c4-f4de-431f-9738-30d53b5790f0';
  $display->content['new-0b4279c4-f4de-431f-9738-30d53b5790f0'] = $pane;
  $display->panels['center'][9] = 'new-0b4279c4-f4de-431f-9738-30d53b5790f0';
  $pane = new stdClass();
  $pane->pid = 'new-38975c5b-29c7-472e-b1eb-49c0ed4b9309';
  $pane->panel = 'center';
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
      'title_style' => '_none',
      'title_link' => '',
      'title_class' => '',
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
  $pane->position = 10;
  $pane->locks = array();
  $pane->uuid = '38975c5b-29c7-472e-b1eb-49c0ed4b9309';
  $display->content['new-38975c5b-29c7-472e-b1eb-49c0ed4b9309'] = $pane;
  $display->panels['center'][10] = 'new-38975c5b-29c7-472e-b1eb-49c0ed4b9309';
  $pane = new stdClass();
  $pane->pid = 'new-d05c7360-62ae-4b57-a2fa-af756b871d17';
  $pane->panel = 'center';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_ph_address';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'hidden',
    'formatter' => 'title_linked',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(
      'title_style' => '_none',
      'title_link' => '',
      'title_class' => '',
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
  $pane->position = 11;
  $pane->locks = array();
  $pane->uuid = 'd05c7360-62ae-4b57-a2fa-af756b871d17';
  $display->content['new-d05c7360-62ae-4b57-a2fa-af756b871d17'] = $pane;
  $display->panels['center'][11] = 'new-d05c7360-62ae-4b57-a2fa-af756b871d17';
  $pane = new stdClass();
  $pane->pid = 'new-e36dcb73-9189-40e8-acaa-bdd2574c9377';
  $pane->panel = 'center';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_ph_cp';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'hidden',
    'formatter' => 'title_linked',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(
      'title_style' => '_none',
      'title_link' => '',
      'title_class' => '',
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
  $pane->position = 12;
  $pane->locks = array();
  $pane->uuid = 'e36dcb73-9189-40e8-acaa-bdd2574c9377';
  $display->content['new-e36dcb73-9189-40e8-acaa-bdd2574c9377'] = $pane;
  $display->panels['center'][12] = 'new-e36dcb73-9189-40e8-acaa-bdd2574c9377';
  $pane = new stdClass();
  $pane->pid = 'new-0c8ecff9-b7cd-4097-9147-ed11f1bf5f19';
  $pane->panel = 'center';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_country_code';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'hidden',
    'formatter' => 'i18n_list_default',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(),
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
  $pane->position = 13;
  $pane->locks = array();
  $pane->uuid = '0c8ecff9-b7cd-4097-9147-ed11f1bf5f19';
  $display->content['new-0c8ecff9-b7cd-4097-9147-ed11f1bf5f19'] = $pane;
  $display->panels['center'][13] = 'new-0c8ecff9-b7cd-4097-9147-ed11f1bf5f19';
  $pane = new stdClass();
  $pane->pid = 'new-b4c58a13-6a77-4758-a4e7-522b788832e0';
  $pane->panel = 'center';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_general_email';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'hidden',
    'formatter' => 'email_default',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(),
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
  $pane->position = 14;
  $pane->locks = array();
  $pane->uuid = 'b4c58a13-6a77-4758-a4e7-522b788832e0';
  $display->content['new-b4c58a13-6a77-4758-a4e7-522b788832e0'] = $pane;
  $display->panels['center'][14] = 'new-b4c58a13-6a77-4758-a4e7-522b788832e0';
  $pane = new stdClass();
  $pane->pid = 'new-eb585847-4795-4b6d-9822-25da45177327';
  $pane->panel = 'center';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_website';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'hidden',
    'formatter' => 'link_default',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(),
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
  $pane->position = 15;
  $pane->locks = array();
  $pane->uuid = 'eb585847-4795-4b6d-9822-25da45177327';
  $display->content['new-eb585847-4795-4b6d-9822-25da45177327'] = $pane;
  $display->panels['center'][15] = 'new-eb585847-4795-4b6d-9822-25da45177327';
  $pane = new stdClass();
  $pane->pid = 'new-55e46dc6-cbe6-47b9-9228-2dbb98c6c582';
  $pane->panel = 'center';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_general_phone';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'hidden',
    'formatter' => 'title_linked',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(
      'title_style' => '_none',
      'title_link' => '',
      'title_class' => '',
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
  $pane->position = 16;
  $pane->locks = array();
  $pane->uuid = '55e46dc6-cbe6-47b9-9228-2dbb98c6c582';
  $display->content['new-55e46dc6-cbe6-47b9-9228-2dbb98c6c582'] = $pane;
  $display->panels['center'][16] = 'new-55e46dc6-cbe6-47b9-9228-2dbb98c6c582';
  $pane = new stdClass();
  $pane->pid = 'new-249112dd-020c-473e-87b5-653d3edd5346';
  $pane->panel = 'center';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_main_contact';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'above',
    'formatter' => 'title_linked',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(
      'title_style' => '_none',
      'title_link' => '',
      'title_class' => '',
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
  $pane->position = 17;
  $pane->locks = array();
  $pane->uuid = '249112dd-020c-473e-87b5-653d3edd5346';
  $display->content['new-249112dd-020c-473e-87b5-653d3edd5346'] = $pane;
  $display->panels['center'][17] = 'new-249112dd-020c-473e-87b5-653d3edd5346';
  $display->hide_title = PANELS_TITLE_NONE;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_partner_public_profile__test';
  $handler->task = 'page';
  $handler->subtask = 'partner_public_profile';
  $handler->handler = 'panel_context';
  $handler->weight = 1;
  $handler->conf = array(
    'title' => 'test',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'name' => 'test',
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'partner' => 'partner',
            ),
          ),
          'context' => 'argument_entity_id:node_1',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
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
  $display->uuid = '93d8cead-c2ca-480c-bca7-777938c2c731';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_partner_public_profile__test';
  $display->content = array();
  $display->panels = array();
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['partner_public_profile'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'private_area_for_partners';
  $page->task = 'page';
  $page->admin_title = 'Partner Resources';
  $page->admin_description = 'Private area landing page for partners';
  $page->path = 'private';
  $page->access = array(
    'plugins' => array(
      1 => array(
        'name' => 'role',
        'settings' => array(
          'rids' => array(
            0 => 12,
          ),
        ),
        'context' => 'logged-in-user',
        'not' => FALSE,
      ),
      2 => array(
        'name' => 'role',
        'settings' => array(
          'rids' => array(
            0 => 13,
          ),
        ),
        'context' => 'logged-in-user',
        'not' => FALSE,
      ),
      3 => array(
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
    'logic' => 'or',
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
  $handler->name = 'page_private_area_for_partners__panel_context_b00e43ca-0583-41d3-8091-8c71bb42ee77';
  $handler->task = 'page';
  $handler->subtask = 'private_area_for_partners';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Partner Resources',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => 'private-area',
    'css_id' => 'private',
    'css' => '',
    'contexts' => array(
      0 => array(
        'identifier' => 'User',
        'keyword' => 'user',
        'name' => 'user',
        'type' => 'current',
        'uid' => '',
        'id' => 1,
      ),
    ),
    'relationships' => array(),
    'access' => array(
      'plugins' => array(
        1 => array(
          'name' => 'role',
          'settings' => array(
            'rids' => array(
              0 => 3,
              1 => 11,
              2 => 12,
              3 => 13,
            ),
          ),
          'context' => 'context_user_1',
          'not' => FALSE,
        ),
      ),
      'logic' => 'or',
    ),
    'panels_breadcrumbs_state' => 1,
    'panels_breadcrumbs_titles' => 'Partner Resources',
    'panels_breadcrumbs_paths' => '<none>',
    'panels_breadcrumbs_home' => 1,
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
        ),
        'parent' => 'main',
        'class' => '',
        'hide_empty' => 0,
      ),
      'center' => array(
        'type' => 'region',
        'title' => 'Center',
        'width' => 100,
        'width_type' => '%',
        'parent' => 'main-row',
        'class' => 'container',
        'hide_empty' => 0,
      ),
      1 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'center_',
        ),
        'parent' => 'main',
        'class' => '',
        'hide_empty' => 0,
      ),
      'center_' => array(
        'type' => 'region',
        'title' => 'Center',
        'width' => 100,
        'width_type' => '%',
        'parent' => '1',
        'class' => '',
        'hide_empty' => 0,
      ),
    ),
  );
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'middle' => NULL,
      'center' => NULL,
      'center_' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = 'Partner Resources';
  $display->uuid = 'cbebf880-65eb-4460-bd57-29469e70c90f';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_private_area_for_partners__panel_context_b00e43ca-0583-41d3-8091-8c71bb42ee77';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-3132a8e3-ab51-4bea-9f03-6650d3556a2d';
  $pane->panel = 'center';
  $pane->type = 'node';
  $pane->subtype = 'node';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'nid' => '966',
    'links' => 1,
    'leave_node_title' => 0,
    'identifier' => '',
    'build_mode' => 'body',
    'link_node_title' => 0,
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
  $pane->uuid = '3132a8e3-ab51-4bea-9f03-6650d3556a2d';
  $display->content['new-3132a8e3-ab51-4bea-9f03-6650d3556a2d'] = $pane;
  $display->panels['center'][0] = 'new-3132a8e3-ab51-4bea-9f03-6650d3556a2d';
  $pane = new stdClass();
  $pane->pid = 'new-98473ead-de9d-42ac-87dc-b9a40f535996';
  $pane->panel = 'center';
  $pane->type = 'node';
  $pane->subtype = 'node';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'nid' => '969',
    'links' => 1,
    'leave_node_title' => 0,
    'identifier' => '',
    'build_mode' => 'body',
    'link_node_title' => 0,
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
  $pane->uuid = '98473ead-de9d-42ac-87dc-b9a40f535996';
  $display->content['new-98473ead-de9d-42ac-87dc-b9a40f535996'] = $pane;
  $display->panels['center'][1] = 'new-98473ead-de9d-42ac-87dc-b9a40f535996';
  $pane = new stdClass();
  $pane->pid = 'new-a8994f51-ad8f-4bea-a56a-fbf42cb57cd4';
  $pane->panel = 'center';
  $pane->type = 'node';
  $pane->subtype = 'node';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'nid' => '972',
    'links' => 1,
    'leave_node_title' => 0,
    'identifier' => '',
    'build_mode' => 'body',
    'link_node_title' => 0,
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
  $pane->uuid = 'a8994f51-ad8f-4bea-a56a-fbf42cb57cd4';
  $display->content['new-a8994f51-ad8f-4bea-a56a-fbf42cb57cd4'] = $pane;
  $display->panels['center'][2] = 'new-a8994f51-ad8f-4bea-a56a-fbf42cb57cd4';
  $pane = new stdClass();
  $pane->pid = 'new-62559f54-3197-4daf-99a9-b6e3e0c4e3fa';
  $pane->panel = 'center';
  $pane->type = 'node';
  $pane->subtype = 'node';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'nid' => '975',
    'links' => 0,
    'leave_node_title' => 0,
    'identifier' => '',
    'build_mode' => 'body',
    'link_node_title' => 0,
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
  $pane->position = 3;
  $pane->locks = array();
  $pane->uuid = '62559f54-3197-4daf-99a9-b6e3e0c4e3fa';
  $display->content['new-62559f54-3197-4daf-99a9-b6e3e0c4e3fa'] = $pane;
  $display->panels['center'][3] = 'new-62559f54-3197-4daf-99a9-b6e3e0c4e3fa';
  $pane = new stdClass();
  $pane->pid = 'new-80345943-0413-4937-b106-1bac9dc116c4';
  $pane->panel = 'center';
  $pane->type = 'node';
  $pane->subtype = 'node';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'nid' => '978',
    'links' => 0,
    'leave_node_title' => 0,
    'identifier' => '',
    'build_mode' => 'body',
    'link_node_title' => 0,
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
  $pane->position = 4;
  $pane->locks = array();
  $pane->uuid = '80345943-0413-4937-b106-1bac9dc116c4';
  $display->content['new-80345943-0413-4937-b106-1bac9dc116c4'] = $pane;
  $display->panels['center'][4] = 'new-80345943-0413-4937-b106-1bac9dc116c4';
  $pane = new stdClass();
  $pane->pid = 'new-0c01ea71-c9ec-4cc9-94a4-4f0e83db6534';
  $pane->panel = 'center';
  $pane->type = 'node';
  $pane->subtype = 'node';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'nid' => '981',
    'links' => 0,
    'leave_node_title' => 0,
    'identifier' => '',
    'build_mode' => 'body',
    'link_node_title' => 0,
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
  $pane->position = 5;
  $pane->locks = array();
  $pane->uuid = '0c01ea71-c9ec-4cc9-94a4-4f0e83db6534';
  $display->content['new-0c01ea71-c9ec-4cc9-94a4-4f0e83db6534'] = $pane;
  $display->panels['center'][5] = 'new-0c01ea71-c9ec-4cc9-94a4-4f0e83db6534';
  $pane = new stdClass();
  $pane->pid = 'new-31c17ce7-d216-4a2c-b2a1-ebbad01f8f76';
  $pane->panel = 'center';
  $pane->type = 'node';
  $pane->subtype = 'node';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'nid' => '1011',
    'links' => 0,
    'leave_node_title' => 0,
    'identifier' => '',
    'build_mode' => 'body',
    'link_node_title' => 0,
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
  $pane->position = 6;
  $pane->locks = array();
  $pane->uuid = '31c17ce7-d216-4a2c-b2a1-ebbad01f8f76';
  $display->content['new-31c17ce7-d216-4a2c-b2a1-ebbad01f8f76'] = $pane;
  $display->panels['center'][6] = 'new-31c17ce7-d216-4a2c-b2a1-ebbad01f8f76';
  $pane = new stdClass();
  $pane->pid = 'new-b2bf0384-b3ad-43d2-9d62-259e6af13efc';
  $pane->panel = 'center';
  $pane->type = 'node';
  $pane->subtype = 'node';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'nid' => '1012',
    'links' => 0,
    'leave_node_title' => 0,
    'identifier' => '',
    'build_mode' => 'body',
    'link_node_title' => 0,
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
  $pane->position = 7;
  $pane->locks = array();
  $pane->uuid = 'b2bf0384-b3ad-43d2-9d62-259e6af13efc';
  $display->content['new-b2bf0384-b3ad-43d2-9d62-259e6af13efc'] = $pane;
  $display->panels['center'][7] = 'new-b2bf0384-b3ad-43d2-9d62-259e6af13efc';
  $pane = new stdClass();
  $pane->pid = 'new-15064475-1885-47e1-89dd-3cab3b7305a4';
  $pane->panel = 'center';
  $pane->type = 'node';
  $pane->subtype = 'node';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'nid' => '137',
    'links' => 0,
    'leave_node_title' => 0,
    'identifier' => '',
    'build_mode' => 'body',
    'link_node_title' => 0,
    'override_title' => 1,
    'override_title_text' => '%title',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array(
    'css_id' => 'contact-us',
    'css_class' => '',
  );
  $pane->extras = array();
  $pane->position = 8;
  $pane->locks = array();
  $pane->uuid = '15064475-1885-47e1-89dd-3cab3b7305a4';
  $display->content['new-15064475-1885-47e1-89dd-3cab3b7305a4'] = $pane;
  $display->panels['center'][8] = 'new-15064475-1885-47e1-89dd-3cab3b7305a4';
  $pane = new stdClass();
  $pane->pid = 'new-0138946a-50ca-4699-a497-d7559f36c514';
  $pane->panel = 'center';
  $pane->type = 'block';
  $pane->subtype = 'hwc_partner-hwc_partner_user_account_edit';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 1,
    'override_title_text' => 'Your account',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 9;
  $pane->locks = array();
  $pane->uuid = '0138946a-50ca-4699-a497-d7559f36c514';
  $display->content['new-0138946a-50ca-4699-a497-d7559f36c514'] = $pane;
  $display->panels['center'][9] = 'new-0138946a-50ca-4699-a497-d7559f36c514';
  $pane = new stdClass();
  $pane->pid = 'new-9bf21a4c-e961-4544-acb9-e6cfcac8fec6';
  $pane->panel = 'center_';
  $pane->type = 'node';
  $pane->subtype = 'node';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'nid' => '963',
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
    'css_class' => 'section-introduction',
  );
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '9bf21a4c-e961-4544-acb9-e6cfcac8fec6';
  $display->content['new-9bf21a4c-e961-4544-acb9-e6cfcac8fec6'] = $pane;
  $display->panels['center_'][0] = 'new-9bf21a4c-e961-4544-acb9-e6cfcac8fec6';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-9bf21a4c-e961-4544-acb9-e6cfcac8fec6';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['private_area_for_partners'] = $page;

  return $pages;

}
