<?php
/**
 * @file
 * hwc.panels_default.inc
 */

/**
 * Implements hook_default_panels_mini().
 */
function hwc_default_panels_mini() {
  $export = array();

  $mini = new stdClass();
  $mini->disabled = FALSE; /* Edit this to true to make a default mini disabled initially */
  $mini->api_version = 1;
  $mini->name = 'additional_resources';
  $mini->category = '';
  $mini->admin_title = 'Additional resources';
  $mini->admin_description = '';
  $mini->requiredcontexts = array();
  $mini->contexts = array();
  $mini->relationships = array();
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
  $display->uuid = 'c494b9a0-a840-455b-86f4-ac9aec9dfe8e';
  $display->storage_type = 'panels_mini';
  $display->storage_id = 'additional_resources';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-ca0d6683-5c55-422c-b54c-6cdab50a2fcb';
    $pane->panel = 'center';
    $pane->type = 'views';
    $pane->subtype = 'additional_resources';
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
      'args' => '%1/youtube',
      'url' => '',
      'display' => 'block',
      'override_title' => 1,
      'override_title_text' => 'Youtube',
      'override_title_heading' => 'h4',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => 'additional-resources-youtube-pane',
      'css_class' => 'additional-resources-pane row',
    );
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'ca0d6683-5c55-422c-b54c-6cdab50a2fcb';
    $display->content['new-ca0d6683-5c55-422c-b54c-6cdab50a2fcb'] = $pane;
    $display->panels['center'][0] = 'new-ca0d6683-5c55-422c-b54c-6cdab50a2fcb';
    $pane = new stdClass();
    $pane->pid = 'new-e86f23ea-4a43-4fc4-b62f-b297b97613c3';
    $pane->panel = 'center';
    $pane->type = 'views';
    $pane->subtype = 'additional_resources';
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
      'args' => '%1/slideshare',
      'url' => '',
      'display' => 'block',
      'override_title' => 1,
      'override_title_text' => 'Slideshare',
      'override_title_heading' => 'h4',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => 'additional-resources-slideshare-pane',
      'css_class' => 'additional-resources-pane row',
    );
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = 'e86f23ea-4a43-4fc4-b62f-b297b97613c3';
    $display->content['new-e86f23ea-4a43-4fc4-b62f-b297b97613c3'] = $pane;
    $display->panels['center'][1] = 'new-e86f23ea-4a43-4fc4-b62f-b297b97613c3';
    $pane = new stdClass();
    $pane->pid = 'new-ded1f940-4a4d-47db-9f71-f449f012380c';
    $pane->panel = 'center';
    $pane->type = 'views';
    $pane->subtype = 'additional_resources';
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
      'args' => '%1/flickr',
      'url' => '',
      'display' => 'block',
      'override_title' => 1,
      'override_title_text' => 'Flickr',
      'override_title_heading' => 'h4',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => 'additional-resources-flickr-pane',
      'css_class' => 'additional-resources-pane row',
    );
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = 'ded1f940-4a4d-47db-9f71-f449f012380c';
    $display->content['new-ded1f940-4a4d-47db-9f71-f449f012380c'] = $pane;
    $display->panels['center'][2] = 'new-ded1f940-4a4d-47db-9f71-f449f012380c';
    $pane = new stdClass();
    $pane->pid = 'new-d9a8f9c9-5d6b-4b8f-b4f5-06c82326512d';
    $pane->panel = 'center';
    $pane->type = 'views';
    $pane->subtype = 'additional_resources';
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
      'args' => '%1/publication',
      'url' => '',
      'display' => 'block',
      'override_title' => 1,
      'override_title_text' => 'Publications',
      'override_title_heading' => 'h4',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => 'additional-resources-publications-pane',
      'css_class' => 'additional-resources-pane row',
    );
    $pane->extras = array();
    $pane->position = 3;
    $pane->locks = array();
    $pane->uuid = 'd9a8f9c9-5d6b-4b8f-b4f5-06c82326512d';
    $display->content['new-d9a8f9c9-5d6b-4b8f-b4f5-06c82326512d'] = $pane;
    $display->panels['center'][3] = 'new-d9a8f9c9-5d6b-4b8f-b4f5-06c82326512d';
    $pane = new stdClass();
    $pane->pid = 'new-59fcd2ca-4083-44b0-9653-b6819a6c8239';
    $pane->panel = 'center';
    $pane->type = 'views';
    $pane->subtype = 'additional_resources';
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
      'args' => '%1/news',
      'url' => '',
      'display' => 'block',
      'override_title' => 1,
      'override_title_text' => 'News',
      'override_title_heading' => 'h4',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => 'additional-resources-news-pane',
      'css_class' => 'additional-resources-pane row',
    );
    $pane->extras = array();
    $pane->position = 4;
    $pane->locks = array();
    $pane->uuid = '59fcd2ca-4083-44b0-9653-b6819a6c8239';
    $display->content['new-59fcd2ca-4083-44b0-9653-b6819a6c8239'] = $pane;
    $display->panels['center'][4] = 'new-59fcd2ca-4083-44b0-9653-b6819a6c8239';
    $pane = new stdClass();
    $pane->pid = 'new-786bc6c3-b0e7-4508-8f68-37d9b892b4ed';
    $pane->panel = 'center';
    $pane->type = 'views';
    $pane->subtype = 'additional_resources';
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
      'args' => '%1/events',
      'url' => '',
      'display' => 'block_1',
      'override_title' => 1,
      'override_title_text' => 'Events',
      'override_title_heading' => 'h4',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => 'additional-resources-events-pane',
      'css_class' => 'additional-resources-pane row',
    );
    $pane->extras = array();
    $pane->position = 5;
    $pane->locks = array();
    $pane->uuid = '786bc6c3-b0e7-4508-8f68-37d9b892b4ed';
    $display->content['new-786bc6c3-b0e7-4508-8f68-37d9b892b4ed'] = $pane;
    $display->panels['center'][5] = 'new-786bc6c3-b0e7-4508-8f68-37d9b892b4ed';
    $pane = new stdClass();
    $pane->pid = 'new-d4387249-e424-4512-814b-fd26621d9acf';
    $pane->panel = 'center';
    $pane->type = 'views';
    $pane->subtype = 'additional_resources';
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
      'args' => '%1/external_url',
      'url' => '',
      'display' => 'block',
      'override_title' => 1,
      'override_title_text' => 'External resources',
      'override_title_heading' => 'h4',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => 'additional-resources-external_url-pane',
      'css_class' => 'additional-resources-pane row',
    );
    $pane->extras = array();
    $pane->position = 6;
    $pane->locks = array();
    $pane->uuid = 'd4387249-e424-4512-814b-fd26621d9acf';
    $display->content['new-d4387249-e424-4512-814b-fd26621d9acf'] = $pane;
    $display->panels['center'][6] = 'new-d4387249-e424-4512-814b-fd26621d9acf';
    $pane = new stdClass();
    $pane->pid = 'new-7f84e0b0-0e99-4073-95cb-4c425534cf32';
    $pane->panel = 'center';
    $pane->type = 'views';
    $pane->subtype = 'additional_resources';
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
      'args' => '%1/internal_url',
      'url' => '',
      'display' => 'block',
      'override_title' => 1,
      'override_title_text' => 'Internal resources',
      'override_title_heading' => 'h4',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => 'additional-resources-internal_url-pane',
      'css_class' => 'additional-resources-internal_url-pane',
    );
    $pane->extras = array();
    $pane->position = 7;
    $pane->locks = array();
    $pane->uuid = '7f84e0b0-0e99-4073-95cb-4c425534cf32';
    $display->content['new-7f84e0b0-0e99-4073-95cb-4c425534cf32'] = $pane;
    $display->panels['center'][7] = 'new-7f84e0b0-0e99-4073-95cb-4c425534cf32';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $mini->display = $display;
  $export['additional_resources'] = $mini;

  $mini = new stdClass();
  $mini->disabled = FALSE; /* Edit this to true to make a default mini disabled initially */
  $mini->api_version = 1;
  $mini->name = 'news_and_events';
  $mini->category = '';
  $mini->admin_title = 'News and events';
  $mini->admin_description = '';
  $mini->requiredcontexts = array();
  $mini->contexts = array();
  $mini->relationships = array();
  $display = new panels_display();
  $display->layout = 'flexible';
  $display->layout_settings = array(
    'items' => array(
      'canvas' => array(
        'type' => 'row',
        'contains' => 'column',
        'children' => array(
          0 => 1,
          1 => 'main',
        ),
        'parent' => NULL,
        'class' => 'container',
        'column_class' => '',
        'row_class' => '',
        'region_class' => '',
        'no_scale' => FALSE,
        'fixed_width' => '',
        'column_separation' => '0.5em',
        'region_separation' => '0.5em',
        'row_separation' => '0.5em',
        'hide_empty' => 0,
      ),
      'main' => array(
        'type' => 'column',
        'width' => 50,
        'width_type' => '%',
        'children' => array(
          0 => 'main-row',
        ),
        'parent' => 'canvas',
        'class' => 'col-xs-12 col-sm-6',
        'hide_empty' => 0,
      ),
      'main-row' => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'center',
        ),
        'parent' => 'main',
      ),
      'center' => array(
        'type' => 'region',
        'title' => 'Center',
        'width' => 100,
        'width_type' => '%',
        'parent' => 'main-row',
      ),
      1 => array(
        'type' => 'column',
        'width' => 50,
        'width_type' => '%',
        'parent' => 'canvas',
        'children' => array(
          0 => 2,
        ),
        'class' => 'col-xs-12 col-sm-6',
        'hide_empty' => 0,
      ),
      2 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'content',
        ),
        'parent' => '1',
        'class' => '',
        'hide_empty' => 0,
      ),
      'content' => array(
        'type' => 'region',
        'title' => 'Content',
        'width' => 100,
        'width_type' => '%',
        'parent' => '2',
        'class' => '',
        'hide_empty' => 0,
      ),
    ),
  );
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'center' => NULL,
      'content' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = 'ae6050ef-5127-4bae-8469-6f6cbbeea21f';
  $display->storage_type = 'panels_mini';
  $display->storage_id = 'news_and_events';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-3c99908b-6432-4a3b-8b59-d78bcb842f81';
    $pane->panel = 'center';
    $pane->type = 'views';
    $pane->subtype = 'frontpage_events';
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
    $pane->uuid = '3c99908b-6432-4a3b-8b59-d78bcb842f81';
    $display->content['new-3c99908b-6432-4a3b-8b59-d78bcb842f81'] = $pane;
    $display->panels['center'][0] = 'new-3c99908b-6432-4a3b-8b59-d78bcb842f81';
    $pane = new stdClass();
    $pane->pid = 'new-96773291-4162-4f6e-95b7-d86fef28b815';
    $pane->panel = 'content';
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
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '96773291-4162-4f6e-95b7-d86fef28b815';
    $display->content['new-96773291-4162-4f6e-95b7-d86fef28b815'] = $pane;
    $display->panels['content'][0] = 'new-96773291-4162-4f6e-95b7-d86fef28b815';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-96773291-4162-4f6e-95b7-d86fef28b815';
  $mini->display = $display;
  $export['news_and_events'] = $mini;

  return $export;
}
