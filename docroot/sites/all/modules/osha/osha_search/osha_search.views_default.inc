<?php
/**
 * @file
 * osha_search.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function osha_search_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'search';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'search_api_index_default_multilingual_node_index';
  $view->human_name = 'Search';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Search';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['search_api_bypass_access'] = 0;
  $handler->display->display_options['query']['options']['parse_mode'] = 'direct';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Search';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['pager']['options']['tags']['first'] = '«';
  $handler->display->display_options['pager']['options']['tags']['previous'] = '‹';
  $handler->display->display_options['pager']['options']['tags']['next'] = '›';
  $handler->display->display_options['pager']['options']['tags']['last'] = '»';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['grouping'] = array(
    0 => array(
      'field' => 'type',
      'rendered' => 1,
      'rendered_strip' => 0,
    ),
  );
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Footer: Global: Result summary */
  $handler->display->display_options['footer']['result']['id'] = 'result';
  $handler->display->display_options['footer']['result']['table'] = 'views';
  $handler->display->display_options['footer']['result']['field'] = 'result';
  $handler->display->display_options['footer']['result']['content'] = 'Displaying @start - @end of @total';
  /* No results behavior: Global: Unfiltered text */
  $handler->display->display_options['empty']['area_text_custom']['id'] = 'area_text_custom';
  $handler->display->display_options['empty']['area_text_custom']['table'] = 'views';
  $handler->display->display_options['empty']['area_text_custom']['field'] = 'area_text_custom';
  $handler->display->display_options['empty']['area_text_custom']['empty'] = TRUE;
  $handler->display->display_options['empty']['area_text_custom']['content'] = 'No results';
  /* Field: Indexed Multilingual Node: Title */
  $handler->display->display_options['fields']['title_field']['id'] = 'title_field';
  $handler->display->display_options['fields']['title_field']['table'] = 'search_api_index_default_multilingual_node_index';
  $handler->display->display_options['fields']['title_field']['field'] = 'title_field';
  $handler->display->display_options['fields']['title_field']['label'] = '';
  $handler->display->display_options['fields']['title_field']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title_field']['type'] = 'title_linked';
  $handler->display->display_options['fields']['title_field']['settings'] = array(
    'title_style' => 'div',
    'title_link' => 'content',
    'title_class' => '',
  );
  /* Field: Indexed Multilingual Node: URL */
  $handler->display->display_options['fields']['url']['id'] = 'url';
  $handler->display->display_options['fields']['url']['table'] = 'search_api_index_default_multilingual_node_index';
  $handler->display->display_options['fields']['url']['field'] = 'url';
  $handler->display->display_options['fields']['url']['label'] = '';
  $handler->display->display_options['fields']['url']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['url']['link_to_entity'] = 0;
  /* Field: Indexed Multilingual Node: Image */
  $handler->display->display_options['fields']['field_image']['id'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['table'] = 'search_api_index_default_multilingual_node_index';
  $handler->display->display_options['fields']['field_image']['field'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['label'] = '';
  $handler->display->display_options['fields']['field_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image']['settings'] = array(
    'image_style' => 'thumbnail',
    'image_link' => 'content',
  );
  /* Field: Indexed Multilingual Node: Cover image */
  $handler->display->display_options['fields']['field_cover_image']['id'] = 'field_cover_image';
  $handler->display->display_options['fields']['field_cover_image']['table'] = 'search_api_index_default_multilingual_node_index';
  $handler->display->display_options['fields']['field_cover_image']['field'] = 'field_cover_image';
  $handler->display->display_options['fields']['field_cover_image']['label'] = '';
  $handler->display->display_options['fields']['field_cover_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_cover_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_cover_image']['settings'] = array(
    'image_style' => 'thumbnail',
    'image_link' => 'content',
  );
  /* Field: Search: Excerpt */
  $handler->display->display_options['fields']['search_api_excerpt']['id'] = 'search_api_excerpt';
  $handler->display->display_options['fields']['search_api_excerpt']['table'] = 'search_api_index_default_multilingual_node_index';
  $handler->display->display_options['fields']['search_api_excerpt']['field'] = 'search_api_excerpt';
  $handler->display->display_options['fields']['search_api_excerpt']['label'] = '';
  $handler->display->display_options['fields']['search_api_excerpt']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['search_api_excerpt']['link_to_entity'] = 0;
  /* Sort criterion: Search: Relevance */
  $handler->display->display_options['sorts']['search_api_relevance']['id'] = 'search_api_relevance';
  $handler->display->display_options['sorts']['search_api_relevance']['table'] = 'search_api_index_default_multilingual_node_index';
  $handler->display->display_options['sorts']['search_api_relevance']['field'] = 'search_api_relevance';
  $handler->display->display_options['sorts']['search_api_relevance']['order'] = 'DESC';
  $handler->display->display_options['sorts']['search_api_relevance']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['search_api_relevance']['expose']['label'] = 'Relevance';
  /* Filter criterion: Search: Fulltext search */
  $handler->display->display_options['filters']['search_api_views_fulltext']['id'] = 'search_api_views_fulltext';
  $handler->display->display_options['filters']['search_api_views_fulltext']['table'] = 'search_api_index_default_multilingual_node_index';
  $handler->display->display_options['filters']['search_api_views_fulltext']['field'] = 'search_api_views_fulltext';
  $handler->display->display_options['filters']['search_api_views_fulltext']['exposed'] = TRUE;
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['operator_id'] = 'search_api_views_fulltext_op';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['label'] = 'Search';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['operator'] = 'search_api_views_fulltext_op';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['identifier'] = 'search_api_views_fulltext';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
  );
  $handler->display->display_options['filters']['search_api_views_fulltext']['fields'] = array(
    'body:summary' => 'body:summary',
    'body:value' => 'body:value',
    'field_summary' => 'field_summary',
    'title_field' => 'title_field',
  );
  /* Filter criterion: Indexed Multilingual Node: Item language */
  $handler->display->display_options['filters']['search_api_language']['id'] = 'search_api_language';
  $handler->display->display_options['filters']['search_api_language']['table'] = 'search_api_index_default_multilingual_node_index';
  $handler->display->display_options['filters']['search_api_language']['field'] = 'search_api_language';
  $handler->display->display_options['filters']['search_api_language']['value'] = array(
    'current' => 'current',
  );

  /* Display: Site search */
  $handler = $view->new_display('page', 'Site search', 'site');
  $handler->display->display_options['exposed_block'] = TRUE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Indexed Multilingual Node: Publication date */
  $handler->display->display_options['fields']['field_publication_date']['id'] = 'field_publication_date';
  $handler->display->display_options['fields']['field_publication_date']['table'] = 'search_api_index_default_multilingual_node_index';
  $handler->display->display_options['fields']['field_publication_date']['field'] = 'field_publication_date';
  $handler->display->display_options['fields']['field_publication_date']['label'] = '';
  $handler->display->display_options['fields']['field_publication_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_publication_date']['settings'] = array(
    'format_type' => 'osha_day_only',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'osha_date_theme' => '',
  );
  /* Field: Indexed Multilingual Node: Title */
  $handler->display->display_options['fields']['title_field']['id'] = 'title_field';
  $handler->display->display_options['fields']['title_field']['table'] = 'search_api_index_default_multilingual_node_index';
  $handler->display->display_options['fields']['title_field']['field'] = 'title_field';
  $handler->display->display_options['fields']['title_field']['label'] = '';
  $handler->display->display_options['fields']['title_field']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title_field']['type'] = 'publication_title_linked';
  $handler->display->display_options['fields']['title_field']['settings'] = array(
    'title_style' => 'div',
    'title_link' => 'content',
    'title_class' => '',
  );
  /* Field: Indexed Multilingual Node: Content type */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'search_api_index_default_multilingual_node_index';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  $handler->display->display_options['fields']['type']['label'] = '';
  $handler->display->display_options['fields']['type']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['type']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['type']['format_name'] = 1;
  /* Field: Indexed Multilingual Node: Archived */
  $handler->display->display_options['fields']['field_archived']['id'] = 'field_archived';
  $handler->display->display_options['fields']['field_archived']['table'] = 'search_api_index_default_multilingual_node_index';
  $handler->display->display_options['fields']['field_archived']['field'] = 'field_archived';
  $handler->display->display_options['fields']['field_archived']['label'] = '';
  $handler->display->display_options['fields']['field_archived']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_archived']['type'] = 'i18n_list_default';
  /* Field: Indexed Multilingual Node: URL */
  $handler->display->display_options['fields']['url']['id'] = 'url';
  $handler->display->display_options['fields']['url']['table'] = 'search_api_index_default_multilingual_node_index';
  $handler->display->display_options['fields']['url']['field'] = 'url';
  $handler->display->display_options['fields']['url']['label'] = '';
  $handler->display->display_options['fields']['url']['exclude'] = TRUE;
  $handler->display->display_options['fields']['url']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['url']['display_as_link'] = FALSE;
  $handler->display->display_options['fields']['url']['link_to_entity'] = 0;
  /* Field: Indexed Multilingual Node: Image */
  $handler->display->display_options['fields']['field_image']['id'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['table'] = 'search_api_index_default_multilingual_node_index';
  $handler->display->display_options['fields']['field_image']['field'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['label'] = '';
  $handler->display->display_options['fields']['field_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image']['settings'] = array(
    'image_style' => 'thumbnail',
    'image_link' => 'content',
  );
  /* Field: Indexed Multilingual Node: Cover image */
  $handler->display->display_options['fields']['field_cover_image']['id'] = 'field_cover_image';
  $handler->display->display_options['fields']['field_cover_image']['table'] = 'search_api_index_default_multilingual_node_index';
  $handler->display->display_options['fields']['field_cover_image']['field'] = 'field_cover_image';
  $handler->display->display_options['fields']['field_cover_image']['label'] = '';
  $handler->display->display_options['fields']['field_cover_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_cover_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_cover_image']['settings'] = array(
    'image_style' => 'thumbnail',
    'image_link' => 'content',
  );
  /* Field: Search: Excerpt */
  $handler->display->display_options['fields']['search_api_excerpt']['id'] = 'search_api_excerpt';
  $handler->display->display_options['fields']['search_api_excerpt']['table'] = 'search_api_index_default_multilingual_node_index';
  $handler->display->display_options['fields']['search_api_excerpt']['field'] = 'search_api_excerpt';
  $handler->display->display_options['fields']['search_api_excerpt']['label'] = '';
  $handler->display->display_options['fields']['search_api_excerpt']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['search_api_excerpt']['alter']['text'] = '[search_api_excerpt] <a href=\'[url]\'>See more</a>';
  $handler->display->display_options['fields']['search_api_excerpt']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['search_api_excerpt']['link_to_entity'] = 0;
  /* Field: Indexed Multilingual Node: Country */
  $handler->display->display_options['fields']['field_country']['id'] = 'field_country';
  $handler->display->display_options['fields']['field_country']['table'] = 'search_api_index_default_multilingual_node_index';
  $handler->display->display_options['fields']['field_country']['field'] = 'field_country';
  $handler->display->display_options['fields']['field_country']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_country']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['field_country']['view_mode'] = 'full';
  $handler->display->display_options['fields']['field_country']['bypass_access'] = 0;
  /* Field: Indexed Multilingual Node: Provider */
  $handler->display->display_options['fields']['field_provider']['id'] = 'field_provider';
  $handler->display->display_options['fields']['field_provider']['table'] = 'search_api_index_default_multilingual_node_index';
  $handler->display->display_options['fields']['field_provider']['field'] = 'field_provider';
  $handler->display->display_options['fields']['field_provider']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_provider']['settings'] = array(
    'field_formatter_class' => '',
  );
  /* Field: Indexed Multilingual Node: Article type */
  $handler->display->display_options['fields']['field_article_type']['id'] = 'field_article_type';
  $handler->display->display_options['fields']['field_article_type']['table'] = 'search_api_index_default_multilingual_node_index';
  $handler->display->display_options['fields']['field_article_type']['field'] = 'field_article_type';
  $handler->display->display_options['fields']['field_article_type']['label'] = 'Type';
  $handler->display->display_options['fields']['field_article_type']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_article_type']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['field_article_type']['view_mode'] = 'full';
  $handler->display->display_options['fields']['field_article_type']['bypass_access'] = 0;
  /* Field: Indexed Multilingual Node: Campaign material type */
  $handler->display->display_options['fields']['field_campaign_material_type']['id'] = 'field_campaign_material_type';
  $handler->display->display_options['fields']['field_campaign_material_type']['table'] = 'search_api_index_default_multilingual_node_index';
  $handler->display->display_options['fields']['field_campaign_material_type']['field'] = 'field_campaign_material_type';
  $handler->display->display_options['fields']['field_campaign_material_type']['label'] = 'Type';
  $handler->display->display_options['fields']['field_campaign_material_type']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_campaign_material_type']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['field_campaign_material_type']['view_mode'] = 'full';
  $handler->display->display_options['fields']['field_campaign_material_type']['bypass_access'] = 0;
  /* Field: Indexed Multilingual Node: Organisation Type */
  $handler->display->display_options['fields']['field_orgtype']['id'] = 'field_orgtype';
  $handler->display->display_options['fields']['field_orgtype']['table'] = 'search_api_index_default_multilingual_node_index';
  $handler->display->display_options['fields']['field_orgtype']['field'] = 'field_orgtype';
  $handler->display->display_options['fields']['field_orgtype']['label'] = 'Type';
  $handler->display->display_options['fields']['field_orgtype']['hide_empty'] = TRUE;
  /* Field: Indexed Multilingual Node: Publication Type */
  $handler->display->display_options['fields']['field_publication_type']['id'] = 'field_publication_type';
  $handler->display->display_options['fields']['field_publication_type']['table'] = 'search_api_index_default_multilingual_node_index';
  $handler->display->display_options['fields']['field_publication_type']['field'] = 'field_publication_type';
  $handler->display->display_options['fields']['field_publication_type']['label'] = 'Type';
  $handler->display->display_options['fields']['field_publication_type']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_publication_type']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['field_publication_type']['view_mode'] = 'full';
  $handler->display->display_options['fields']['field_publication_type']['bypass_access'] = 0;
  /* Field: Indexed Multilingual Node: Type */
  $handler->display->display_options['fields']['field_tool_type']['id'] = 'field_tool_type';
  $handler->display->display_options['fields']['field_tool_type']['table'] = 'search_api_index_default_multilingual_node_index';
  $handler->display->display_options['fields']['field_tool_type']['field'] = 'field_tool_type';
  $handler->display->display_options['fields']['field_tool_type']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_tool_type']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['field_tool_type']['view_mode'] = 'full';
  $handler->display->display_options['fields']['field_tool_type']['bypass_access'] = 0;
  /* Field: Indexed Multilingual Node: Type */
  $handler->display->display_options['fields']['field_partner_type']['id'] = 'field_partner_type';
  $handler->display->display_options['fields']['field_partner_type']['table'] = 'search_api_index_default_multilingual_node_index';
  $handler->display->display_options['fields']['field_partner_type']['field'] = 'field_partner_type';
  $handler->display->display_options['fields']['field_partner_type']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_partner_type']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['field_partner_type']['view_mode'] = 'full';
  $handler->display->display_options['fields']['field_partner_type']['bypass_access'] = 0;
  /* Field: Indexed Multilingual Node: Type */
  $handler->display->display_options['fields']['field_contact_type']['id'] = 'field_contact_type';
  $handler->display->display_options['fields']['field_contact_type']['table'] = 'search_api_index_default_multilingual_node_index';
  $handler->display->display_options['fields']['field_contact_type']['field'] = 'field_contact_type';
  $handler->display->display_options['fields']['field_contact_type']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_contact_type']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['field_contact_type']['view_mode'] = 'full';
  $handler->display->display_options['fields']['field_contact_type']['bypass_access'] = 0;
  /* Field: Indexed Multilingual Node: File */
  $handler->display->display_options['fields']['field_file']['id'] = 'field_file';
  $handler->display->display_options['fields']['field_file']['table'] = 'search_api_index_default_multilingual_node_index';
  $handler->display->display_options['fields']['field_file']['field'] = 'field_file';
  $handler->display->display_options['fields']['field_file']['label'] = '';
  $handler->display->display_options['fields']['field_file']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_file']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_file']['type'] = 'multilanguage_file';
  $handler->display->display_options['fields']['field_file']['settings'] = array(
    'field_formatter_class' => '',
  );
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Search: Relevance */
  $handler->display->display_options['sorts']['search_api_relevance']['id'] = 'search_api_relevance';
  $handler->display->display_options['sorts']['search_api_relevance']['table'] = 'search_api_index_default_multilingual_node_index';
  $handler->display->display_options['sorts']['search_api_relevance']['field'] = 'search_api_relevance';
  $handler->display->display_options['sorts']['search_api_relevance']['order'] = 'DESC';
  $handler->display->display_options['sorts']['search_api_relevance']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['search_api_relevance']['expose']['label'] = 'Relevance';
  /* Sort criterion: Indexed Multilingual Node: Publication date */
  $handler->display->display_options['sorts']['field_publication_date']['id'] = 'field_publication_date';
  $handler->display->display_options['sorts']['field_publication_date']['table'] = 'search_api_index_default_multilingual_node_index';
  $handler->display->display_options['sorts']['field_publication_date']['field'] = 'field_publication_date';
  $handler->display->display_options['sorts']['field_publication_date']['order'] = 'DESC';
  $handler->display->display_options['sorts']['field_publication_date']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['field_publication_date']['expose']['label'] = 'Publication date';
  /* Sort criterion: Indexed Multilingual Node: Title #2 */
  $handler->display->display_options['sorts']['title2']['id'] = 'title2';
  $handler->display->display_options['sorts']['title2']['table'] = 'search_api_index_default_multilingual_node_index';
  $handler->display->display_options['sorts']['title2']['field'] = 'title2';
  $handler->display->display_options['sorts']['title2']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['title2']['expose']['label'] = 'Title';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['filter_groups']['groups'] = array(
    1 => 'AND',
    2 => 'OR',
    3 => 'OR',
  );
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Search: Fulltext search */
  $handler->display->display_options['filters']['search_api_views_fulltext']['id'] = 'search_api_views_fulltext';
  $handler->display->display_options['filters']['search_api_views_fulltext']['table'] = 'search_api_index_default_multilingual_node_index';
  $handler->display->display_options['filters']['search_api_views_fulltext']['field'] = 'search_api_views_fulltext';
  $handler->display->display_options['filters']['search_api_views_fulltext']['group'] = 1;
  $handler->display->display_options['filters']['search_api_views_fulltext']['exposed'] = TRUE;
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['operator_id'] = 'search_api_views_fulltext_op';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['label'] = 'Search';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['operator'] = 'search_api_views_fulltext_op';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['identifier'] = 'search_block_form';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
    9 => 0,
    10 => 0,
  );
  $handler->display->display_options['filters']['search_api_views_fulltext']['fields'] = array(
    'attachments_field_file' => 'attachments_field_file',
    'attachments_field_publication_related_res' => 'attachments_field_publication_related_res',
    'attachments_field_related_documents' => 'attachments_field_related_documents',
    'body:summary' => 'body:summary',
    'body:value' => 'body:value',
    'field_aditional_resources:body:summary' => 'field_aditional_resources:body:summary',
    'field_aditional_resources:body:value' => 'field_aditional_resources:body:value',
    'field_aditional_resources:field_summary' => 'field_aditional_resources:field_summary',
    'field_aditional_resources:title' => 'field_aditional_resources:title',
    'field_aditional_resources:title_field' => 'field_aditional_resources:title_field',
    'field_summary' => 'field_summary',
    'title_field' => 'title_field',
  );
  /* Filter criterion: Indexed Multilingual Node: Status */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'search_api_index_default_multilingual_node_index';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = array(
    1 => '1',
  );
  $handler->display->display_options['filters']['status']['group'] = 1;
  /* Filter criterion: Indexed Multilingual Node: Item language */
  $handler->display->display_options['filters']['search_api_language']['id'] = 'search_api_language';
  $handler->display->display_options['filters']['search_api_language']['table'] = 'search_api_index_default_multilingual_node_index';
  $handler->display->display_options['filters']['search_api_language']['field'] = 'search_api_language';
  $handler->display->display_options['filters']['search_api_language']['value'] = array(
    'en' => 'en',
  );
  $handler->display->display_options['filters']['search_api_language']['group'] = 3;
  /* Filter criterion: Indexed Multilingual Node: Item language */
  $handler->display->display_options['filters']['search_api_language_1']['id'] = 'search_api_language_1';
  $handler->display->display_options['filters']['search_api_language_1']['table'] = 'search_api_index_default_multilingual_node_index';
  $handler->display->display_options['filters']['search_api_language_1']['field'] = 'search_api_language';
  $handler->display->display_options['filters']['search_api_language_1']['value'] = array(
    'current' => 'current',
  );
  $handler->display->display_options['filters']['search_api_language_1']['group'] = 3;
  /* Filter criterion: Indexed Multilingual Node: Publication date */
  $handler->display->display_options['filters']['field_publication_date']['id'] = 'field_publication_date';
  $handler->display->display_options['filters']['field_publication_date']['table'] = 'search_api_index_default_multilingual_node_index';
  $handler->display->display_options['filters']['field_publication_date']['field'] = 'field_publication_date';
  $handler->display->display_options['filters']['field_publication_date']['operator'] = '<=';
  $handler->display->display_options['filters']['field_publication_date']['value'] = 'now';
  $handler->display->display_options['filters']['field_publication_date']['group'] = 2;
  /* Filter criterion: Indexed Multilingual Node: Publication date */
  $handler->display->display_options['filters']['field_publication_date_1']['id'] = 'field_publication_date_1';
  $handler->display->display_options['filters']['field_publication_date_1']['table'] = 'search_api_index_default_multilingual_node_index';
  $handler->display->display_options['filters']['field_publication_date_1']['field'] = 'field_publication_date';
  $handler->display->display_options['filters']['field_publication_date_1']['operator'] = 'empty';
  $handler->display->display_options['filters']['field_publication_date_1']['group'] = 2;
  $handler->display->display_options['path'] = 'search';
  $handler->display->display_options['menu']['title'] = 'Site';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'menu-search';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $handler->display->display_options['tab_options']['type'] = 'tab';
  $handler->display->display_options['tab_options']['title'] = 'Site';
  $handler->display->display_options['tab_options']['weight'] = '1';
  $translatables['search'] = array(
    t('Master'),
    t('Search'),
    t('more'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('«'),
    t('‹'),
    t('›'),
    t('»'),
    t('Displaying @start - @end of @total'),
    t('No results'),
    t('Relevance'),
    t('Site search'),
    t('[search_api_excerpt] <a href=\'[url]\'>See more</a>'),
    t('Country'),
    t('Provider'),
    t('Type'),
    t('Publication date'),
    t('Title'),
  );
  $export['search'] = $view;

  $view = new view();
  $view->name = 'search_autocomplete';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'search_api_index_default_multilingual_node_index';
  $view->human_name = 'search_autocomplete';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Search';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['search_api_bypass_access'] = 0;
  $handler->display->display_options['query']['options']['parse_mode'] = 'direct';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Search';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'search_autocomplete';
  $handler->display->display_options['style_options']['group_by'] = 'type';
  $handler->display->display_options['style_options']['input_label'] = 'title_field';
  $handler->display->display_options['style_options']['input_link'] = 'url';
  $handler->display->display_options['style_options']['output_fields'] = array(
    'title_field' => 'title_field',
    'type' => 'type',
  );
  /* Field: Indexed Multilingual Node: Title */
  $handler->display->display_options['fields']['title_field']['id'] = 'title_field';
  $handler->display->display_options['fields']['title_field']['table'] = 'search_api_index_default_multilingual_node_index';
  $handler->display->display_options['fields']['title_field']['field'] = 'title_field';
  $handler->display->display_options['fields']['title_field']['label'] = '';
  $handler->display->display_options['fields']['title_field']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title_field']['settings'] = array(
    'title_style' => 'div',
    'title_link' => 'content',
    'title_class' => '',
  );
  /* Field: Indexed Multilingual Node: URL */
  $handler->display->display_options['fields']['url']['id'] = 'url';
  $handler->display->display_options['fields']['url']['table'] = 'search_api_index_default_multilingual_node_index';
  $handler->display->display_options['fields']['url']['field'] = 'url';
  $handler->display->display_options['fields']['url']['label'] = '';
  $handler->display->display_options['fields']['url']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['url']['display_as_link'] = FALSE;
  $handler->display->display_options['fields']['url']['link_to_entity'] = 0;
  /* Field: Indexed Multilingual Node: Content type */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'search_api_index_default_multilingual_node_index';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  $handler->display->display_options['fields']['type']['label'] = '';
  $handler->display->display_options['fields']['type']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['type']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['type']['format_name'] = 1;
  /* Sort criterion: Search: Relevance */
  $handler->display->display_options['sorts']['search_api_relevance']['id'] = 'search_api_relevance';
  $handler->display->display_options['sorts']['search_api_relevance']['table'] = 'search_api_index_default_multilingual_node_index';
  $handler->display->display_options['sorts']['search_api_relevance']['field'] = 'search_api_relevance';
  $handler->display->display_options['sorts']['search_api_relevance']['order'] = 'DESC';
  $handler->display->display_options['sorts']['search_api_relevance']['expose']['label'] = 'Relevance';
  /* Sort criterion: Indexed Multilingual Node: Publication date */
  $handler->display->display_options['sorts']['field_publication_date']['id'] = 'field_publication_date';
  $handler->display->display_options['sorts']['field_publication_date']['table'] = 'search_api_index_default_multilingual_node_index';
  $handler->display->display_options['sorts']['field_publication_date']['field'] = 'field_publication_date';
  $handler->display->display_options['sorts']['field_publication_date']['order'] = 'DESC';
  /* Filter criterion: Search: Fulltext search */
  $handler->display->display_options['filters']['search_api_views_fulltext']['id'] = 'search_api_views_fulltext';
  $handler->display->display_options['filters']['search_api_views_fulltext']['table'] = 'search_api_index_default_multilingual_node_index';
  $handler->display->display_options['filters']['search_api_views_fulltext']['field'] = 'search_api_views_fulltext';
  $handler->display->display_options['filters']['search_api_views_fulltext']['exposed'] = TRUE;
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['operator_id'] = 'search_api_views_fulltext_op';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['label'] = 'Search';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['operator'] = 'search_api_views_fulltext_op';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['identifier'] = 'filter';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
  );
  $handler->display->display_options['filters']['search_api_views_fulltext']['fields'] = array(
    'body:summary' => 'body:summary',
    'body:value' => 'body:value',
    'field_summary' => 'field_summary',
    'title_field' => 'title_field',
  );
  /* Filter criterion: Indexed Multilingual Node: Item language */
  $handler->display->display_options['filters']['search_api_language']['id'] = 'search_api_language';
  $handler->display->display_options['filters']['search_api_language']['table'] = 'search_api_index_default_multilingual_node_index';
  $handler->display->display_options['filters']['search_api_language']['field'] = 'search_api_language';
  $handler->display->display_options['filters']['search_api_language']['value'] = array(
    'current' => 'current',
  );

  /* Display: Autocomplete */
  $handler = $view->new_display('page', 'Autocomplete', 'search_site_autocomplete');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Search: Fulltext search */
  $handler->display->display_options['filters']['search_api_views_fulltext']['id'] = 'search_api_views_fulltext';
  $handler->display->display_options['filters']['search_api_views_fulltext']['table'] = 'search_api_index_default_multilingual_node_index';
  $handler->display->display_options['filters']['search_api_views_fulltext']['field'] = 'search_api_views_fulltext';
  $handler->display->display_options['filters']['search_api_views_fulltext']['exposed'] = TRUE;
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['operator_id'] = 'search_api_views_fulltext_op';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['label'] = 'Search';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['operator'] = 'search_api_views_fulltext_op';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['identifier'] = 'filter';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
    9 => 0,
    10 => 0,
    11 => 0,
    12 => 0,
  );
  $handler->display->display_options['filters']['search_api_views_fulltext']['fields'] = array(
    'attachments_field_file' => 'attachments_field_file',
    'attachments_field_publication_related_res' => 'attachments_field_publication_related_res',
    'attachments_field_related_documents' => 'attachments_field_related_documents',
    'body:summary' => 'body:summary',
    'body:value' => 'body:value',
    'field_summary' => 'field_summary',
    'title_field' => 'title_field',
  );
  /* Filter criterion: Indexed Multilingual Node: Item language */
  $handler->display->display_options['filters']['search_api_language']['id'] = 'search_api_language';
  $handler->display->display_options['filters']['search_api_language']['table'] = 'search_api_index_default_multilingual_node_index';
  $handler->display->display_options['filters']['search_api_language']['field'] = 'search_api_language';
  $handler->display->display_options['filters']['search_api_language']['value'] = array(
    'current' => 'current',
  );
  /* Filter criterion: Indexed Multilingual Node: Content type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'search_api_index_default_multilingual_node_index';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['operator'] = '<>';
  $handler->display->display_options['filters']['type']['value'] = array(
    'banner' => 'banner',
    'page' => 'page',
  );
  $handler->display->display_options['filters']['type']['expose']['operator_id'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['label'] = 'Content type';
  $handler->display->display_options['filters']['type']['expose']['operator'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['identifier'] = 'type';
  /* Filter criterion: Indexed Multilingual Node: Publication date */
  $handler->display->display_options['filters']['field_publication_date']['id'] = 'field_publication_date';
  $handler->display->display_options['filters']['field_publication_date']['table'] = 'search_api_index_default_multilingual_node_index';
  $handler->display->display_options['filters']['field_publication_date']['field'] = 'field_publication_date';
  $handler->display->display_options['filters']['field_publication_date']['operator'] = '<=';
  $handler->display->display_options['filters']['field_publication_date']['value'] = 'now';
  /* Filter criterion: Indexed Multilingual Node: Status */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'search_api_index_default_multilingual_node_index';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = array(
    1 => '1',
  );
  $handler->display->display_options['path'] = 'search/site/autocomplete';
  $handler->display->display_options['menu']['title'] = 'Site';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'menu-search';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $handler->display->display_options['tab_options']['type'] = 'tab';
  $handler->display->display_options['tab_options']['title'] = 'Site';
  $handler->display->display_options['tab_options']['weight'] = '1';
  $translatables['search_autocomplete'] = array(
    t('Master'),
    t('Search'),
    t('more'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('« first'),
    t('‹ previous'),
    t('next ›'),
    t('last »'),
    t('Relevance'),
    t('Autocomplete'),
    t('Content type'),
  );
  $export['search_autocomplete'] = $view;

  return $export;
}
