<?php
/**
 * @file
 * osha_search.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function osha_search_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "facetapi" && $api == "facetapi_defaults") {
    return array("version" => "1");
  }
  if ($module == "path_breadcrumbs" && $api == "path_breadcrumbs") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function osha_search_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_default_search_api_index().
 */
function osha_search_default_search_api_index() {
  $items = array();
  $items['default_multilingual_node_index'] = entity_import('search_api_index', '{
    "name" : "Default multilingual node index",
    "machine_name" : "default_multilingual_node_index",
    "description" : "An automatically created search index for indexing multilingual node data. Might be configured to specific needs.",
    "server" : "solr_server",
    "item_type" : "search_api_et_node",
    "options" : {
      "index_directly" : 1,
      "cron_limit" : "10",
      "search_api_et" : { "include" : "incomplete", "fallback language" : "" },
      "fields" : {
        "attachments_field_file" : { "type" : "text" },
        "attachments_field_publication_related_res" : { "type" : "text" },
        "attachments_field_related_documents" : { "type" : "text" },
        "author" : { "type" : "integer", "entity_type" : "user" },
        "body:summary" : { "type" : "text" },
        "body:value" : { "type" : "text" },
        "changed" : { "type" : "date" },
        "created" : { "type" : "date" },
        "edit_url" : { "type" : "uri" },
        "field_access_tool_link_fc" : {
          "type" : "list\\u003Cinteger\\u003E",
          "entity_type" : "field_collection_item"
        },
        "field_activity" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_additional_information" : { "type" : "text" },
        "field_aditional_resources" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "node" },
        "field_aditional_resources:body:summary" : { "type" : "list\\u003Ctext\\u003E" },
        "field_aditional_resources:body:value" : { "type" : "list\\u003Ctext\\u003E" },
        "field_aditional_resources:field_article_type" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_aditional_resources:field_summary" : { "type" : "list\\u003Ctext\\u003E" },
        "field_aditional_resources:field_tags" : {
          "type" : "list\\u003Clist\\u003Cinteger\\u003E\\u003E",
          "entity_type" : "taxonomy_term"
        },
        "field_aditional_resources:title" : { "type" : "list\\u003Ctext\\u003E" },
        "field_aditional_resources:title2" : { "type" : "list\\u003Cstring\\u003E" },
        "field_aditional_resources:title_field" : { "type" : "list\\u003Ctext\\u003E" },
        "field_appform_status" : { "type" : "text" },
        "field_archived" : { "type" : "boolean" },
        "field_article_type" : { "type" : "integer", "entity_type" : "taxonomy_term" },
        "field_author" : { "type" : "text" },
        "field_bussines_sector" : { "type" : "integer", "entity_type" : "taxonomy_term" },
        "field_campaign_material_type" : { "type" : "integer", "entity_type" : "taxonomy_term" },
        "field_ceo" : { "type" : "text" },
        "field_character_count" : { "type" : "integer" },
        "field_city" : { "type" : "text" },
        "field_contact_name" : { "type" : "text" },
        "field_contact_phone" : { "type" : "text" },
        "field_contact_type" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_content_reference" : { "type" : "integer", "entity_type" : "node" },
        "field_country" : { "type" : "integer", "entity_type" : "taxonomy_term" },
        "field_country_code" : { "type" : "string" },
        "field_expiration_date" : { "type" : "date" },
        "field_external_urls" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "node" },
        "field_file:file" : { "type" : "integer", "entity_type" : "file" },
        "field_free" : { "type" : "boolean" },
        "field_gallery" : { "type" : "integer", "entity_type" : "node" },
        "field_general_email" : { "type" : "text" },
        "field_general_phone" : { "type" : "text" },
        "field_guid_main_contact" : { "type" : "text" },
        "field_image_caption" : { "type" : "text" },
        "field_location" : { "type" : "text" },
        "field_main_contact" : { "type" : "text" },
        "field_main_contact_email" : { "type" : "text" },
        "field_mission_statement" : { "type" : "text" },
        "field_objective" : { "type" : "text" },
        "field_organisation_rep" : { "type" : "text" },
        "field_organizer" : { "type" : "text" },
        "field_orgtype" : { "type" : "integer", "entity_type" : "taxonomy_term" },
        "field_page_count" : { "type" : "decimal" },
        "field_partner_id" : { "type" : "text" },
        "field_partner_type" : { "type" : "integer", "entity_type" : "taxonomy_term" },
        "field_personal_title" : { "type" : "text" },
        "field_ph_address" : { "type" : "text" },
        "field_ph_cp" : { "type" : "text" },
        "field_ph_town" : { "type" : "text" },
        "field_pledge" : { "type" : "text" },
        "field_position_identifier" : { "type" : "text" },
        "field_pr_embargo_date" : { "type" : "date" },
        "field_pr_notes_to_editor" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "node" },
        "field_press_contact_job_title" : { "type" : "text" },
        "field_press_contact_location" : { "type" : "text" },
        "field_press_contact_organization" : { "type" : "text" },
        "field_provider" : { "type" : "text" },
        "field_publication_bookshop_id" : { "type" : "text" },
        "field_publication_date" : { "type" : "date" },
        "field_publication_type" : { "type" : "integer", "entity_type" : "taxonomy_term" },
        "field_quote" : { "type" : "text" },
        "field_recommended_articles" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "node" },
        "field_recommended_resources" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "node" },
        "field_related_publications" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "node" },
        "field_schedule" : {
          "type" : "list\\u003Cinteger\\u003E",
          "entity_type" : "field_collection_item"
        },
        "field_segment" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_social_dialog_partner" : { "type" : "boolean" },
        "field_speaker" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "node" },
        "field_start_date:value" : { "type" : "date" },
        "field_start_date:value2" : { "type" : "date" },
        "field_summary" : { "type" : "text" },
        "field_tags" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_tags:name" : { "type" : "list\\u003Ctext\\u003E" },
        "field_tool_type" : { "type" : "integer", "entity_type" : "taxonomy_term" },
        "field_twin_infographics" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "node" },
        "field_wg_category" : { "type" : "integer", "entity_type" : "taxonomy_term" },
        "field_wg_role_1" : { "type" : "integer", "entity_type" : "taxonomy_term" },
        "field_wg_role_2" : { "type" : "integer", "entity_type" : "taxonomy_term" },
        "field_zip_code" : { "type" : "text" },
        "language" : { "type" : "string" },
        "nid" : { "type" : "integer" },
        "search_api_access_node" : { "type" : "list\\u003Cstring\\u003E" },
        "search_api_et_id" : { "type" : "string" },
        "search_api_language" : { "type" : "string" },
        "search_api_url" : { "type" : "uri" },
        "status" : { "type" : "integer" },
        "title" : { "type" : "text" },
        "title2" : { "type" : "string" },
        "title_field" : { "type" : "text" },
        "type" : { "type" : "string" },
        "url" : { "type" : "uri" },
        "uuid" : { "type" : "text" },
        "vid" : { "type" : "integer" }
      },
      "data_alter_callbacks" : {
        "search_api_alter_bundle_filter" : {
          "status" : 1,
          "weight" : "-10",
          "settings" : {
            "default" : "0",
            "bundles" : {
              "article" : "article",
              "campaign_materials" : "campaign_materials",
              "event_speaker" : "event_speaker",
              "events" : "events",
              "hwc_gallery" : "hwc_gallery",
              "infographic" : "infographic",
              "news" : "news",
              "partner" : "partner",
              "practical_tool" : "practical_tool",
              "press_release" : "press_release",
              "publication" : "publication"
            }
          }
        },
        "search_api_alter_node_access" : { "status" : 1, "weight" : "0", "settings" : [] },
        "search_api_alter_node_status" : { "status" : 0, "weight" : "0", "settings" : [] },
        "search_api_attachments_alter_settings" : {
          "status" : 1,
          "weight" : "0",
          "settings" : {
            "excluded_extensions" : "aif art avi bmp gif ico mov oga ogv png psd ra ram rgb flv webm mp4 wmv zip rar swf fla flv",
            "number_indexed" : "0"
          }
        },
        "search_api_alter_language_control" : {
          "status" : 1,
          "weight" : "0",
          "settings" : { "lang_field" : "", "languages" : [] }
        },
        "search_api_alter_add_hierarchy" : { "status" : 0, "weight" : "0", "settings" : { "fields" : [] } },
        "search_api_alter_add_url" : { "status" : 1, "weight" : "0", "settings" : [] },
        "search_api_alter_add_aggregation" : { "status" : 0, "weight" : "0", "settings" : [] },
        "search_api_alter_add_viewed_entity" : { "status" : 0, "weight" : "0", "settings" : { "mode" : "full" } }
      },
      "processors" : {
        "search_api_et_remove_language" : { "status" : 0, "weight" : "0", "settings" : [] },
        "search_api_case_ignore" : { "status" : 1, "weight" : "0", "settings" : { "fields" : [] } },
        "search_api_html_filter" : {
          "status" : 1,
          "weight" : "10",
          "settings" : {
            "fields" : [],
            "title" : 0,
            "alt" : 1,
            "tags" : "h1 = 5\\r\\nh2 = 3\\r\\nh3 = 2\\r\\nstrong = 2\\r\\nb = 2\\r\\nem = 1.5\\r\\nu = 1.5"
          }
        },
        "search_api_tokenizer" : {
          "status" : 0,
          "weight" : "20",
          "settings" : { "fields" : [], "spaces" : "[^[:alnum:]]", "ignorable" : "[\\u0027]" }
        },
        "search_api_stopwords" : {
          "status" : 0,
          "weight" : "30",
          "settings" : {
            "fields" : [],
            "file" : "",
            "stopwords" : "but\\r\\ndid\\r\\nthe this that those\\r\\netc"
          }
        },
        "search_api_highlighting" : {
          "status" : 1,
          "weight" : "35",
          "settings" : {
            "prefix" : "\\u003Cstrong\\u003E",
            "suffix" : "\\u003C\\/strong\\u003E",
            "excerpt" : 1,
            "excerpt_length" : "256",
            "exclude_fields" : [],
            "highlight" : "always"
          }
        }
      }
    },
    "enabled" : "1",
    "read_only" : "0",
    "rdf_mapping" : []
  }');
  return $items;
}
