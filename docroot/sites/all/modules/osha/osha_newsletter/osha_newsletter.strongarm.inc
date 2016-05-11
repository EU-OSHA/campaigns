<?php
/**
 * @file
 * osha_newsletter.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function osha_newsletter_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_entity_collection__newsletter_content_collection';
  $strongarm->value = array(
    'view_modes' => array(
      'block' => array(
        'custom_settings' => FALSE,
      ),
      'full' => array(
        'custom_settings' => FALSE,
      ),
      'diff_standard' => array(
        'custom_settings' => FALSE,
      ),
      'token' => array(
        'custom_settings' => FALSE,
      ),
    ),
    'extra_fields' => array(
      'form' => array(),
      'display' => array(),
    ),
  );
  $export['field_bundle_settings_entity_collection__newsletter_content_collection'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_taxonomy_term__newsletter_sections';
  $strongarm->value = array(
    'view_modes' => array(
      'full' => array(
        'custom_settings' => FALSE,
      ),
      'diff_standard' => array(
        'custom_settings' => FALSE,
      ),
      'token' => array(
        'custom_settings' => TRUE,
      ),
    ),
    'extra_fields' => array(
      'form' => array(
        'metatags' => array(
          'weight' => '5',
        ),
        'path' => array(
          'weight' => '4',
        ),
        'redirect' => array(
          'weight' => '3',
        ),
      ),
      'display' => array(
        'description' => array(
          'default' => array(
            'weight' => '0',
            'visible' => TRUE,
          ),
          'full' => array(
            'weight' => '0',
            'visible' => TRUE,
          ),
          'token' => array(
            'weight' => '0',
            'visible' => TRUE,
          ),
        ),
      ),
    ),
  );
  $export['field_bundle_settings_taxonomy_term__newsletter_sections'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'osha_newsletter_after_max_nodes';
  $strongarm->value = '19';
  $export['osha_newsletter_after_max_nodes'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'osha_newsletter_allowed_bundles';
  $strongarm->value = array(
    'events' => 'events',
    'news' => 'news',
    'article' => 0,
    'campaign_materials' => 0,
    'event_speaker' => 0,
    'external_url' => 0,
    'file' => 0,
    'flickr' => 0,
    'frontpage_slider' => 0,
    'hwc_gallery' => 0,
    'infographic' => 0,
    'internal_url' => 0,
    'note_to_editor' => 0,
    'partner' => 0,
    'practical_tool' => 0,
    'press_contact' => 0,
    'press_release' => 0,
    'private_aria_article' => 0,
    'publication' => 0,
    'slideshare' => 0,
    'webform' => 0,
    'youtube' => 0,
  );
  $export['osha_newsletter_allowed_bundles'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'osha_newsletter_image_block_background_img';
  $strongarm->value = 0;
  $export['osha_newsletter_image_block_background_img'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'osha_newsletter_image_block_details_link_label';
  $strongarm->value = 'Privacy policy';
  $export['osha_newsletter_image_block_details_link_label'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'osha_newsletter_image_block_details_link_url';
  $strongarm->value = 'node/1015';
  $export['osha_newsletter_image_block_details_link_url'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'osha_newsletter_image_block_intro_text';
  $strongarm->value = 'Would you like to stay informed about the latest developments regarding ageing workers?';
  $export['osha_newsletter_image_block_intro_text'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'osha_newsletter_image_block_text_end';
  $strongarm->value = 'subscribers';
  $export['osha_newsletter_image_block_text_end'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'osha_newsletter_image_block_text_start';
  $strongarm->value = 'Join';
  $export['osha_newsletter_image_block_text_start'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'osha_newsletter_listserv';
  $strongarm->value = 'listserv@list.osha.europa.eu';
  $export['osha_newsletter_listserv'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'osha_newsletter_listserv_from';
  $strongarm->value = 'hwc-newsletter@osha.europa.eu';
  $export['osha_newsletter_listserv_from'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'osha_newsletter_node_view_mode';
  $strongarm->value = 'newsletter_item';
  $export['osha_newsletter_node_view_mode'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'osha_newsletter_term_ct_map';
  $strongarm->value = array(
    'article' => '',
    'view_mode_article' => 'newsletter_item',
    'campaign_materials' => '',
    'view_mode_campaign_materials' => 'newsletter_item',
    'event_speaker' => '',
    'view_mode_event_speaker' => 'newsletter_item',
    'events' => '184c62a6-3f57-4551-9e82-5308affcd5c3',
    'view_mode_events' => 'newsletter_item',
    'external_url' => '',
    'view_mode_external_url' => 'newsletter_item',
    'file' => '',
    'view_mode_file' => 'newsletter_item',
    'flickr' => '',
    'view_mode_flickr' => 'newsletter_item',
    'frontpage_slider' => '',
    'view_mode_frontpage_slider' => 'newsletter_item',
    'hwc_gallery' => '',
    'view_mode_hwc_gallery' => 'newsletter_item',
    'infographic' => '',
    'view_mode_infographic' => 'newsletter_item',
    'internal_url' => '',
    'view_mode_internal_url' => 'newsletter_item',
    'news' => 'b6dd4495-169b-4d48-86ae-78e217906a95',
    'view_mode_news' => 'highlights_item',
    'note_to_editor' => '',
    'view_mode_note_to_editor' => 'newsletter_item',
    'partner' => '',
    'view_mode_partner' => 'newsletter_item',
    'practical_tool' => '',
    'view_mode_practical_tool' => 'newsletter_item',
    'press_contact' => '',
    'view_mode_press_contact' => 'newsletter_item',
    'press_release' => '',
    'view_mode_press_release' => 'newsletter_item',
    'private_aria_article' => '',
    'view_mode_private_aria_article' => 'newsletter_item',
    'publication' => '',
    'view_mode_publication' => 'newsletter_item',
    'slideshare' => '',
    'view_mode_slideshare' => 'newsletter_item',
    'webform' => '',
    'view_mode_webform' => 'newsletter_item',
    'youtube' => '',
    'view_mode_youtube' => 'newsletter_item',
  );
  $export['osha_newsletter_term_ct_map'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'subscribe_block_details_link_label';
  $strongarm->value = 'Privacy policy';
  $export['subscribe_block_details_link_label'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'subscribe_block_details_link_url';
  $strongarm->value = 'https://osha.europa.eu/en/oshmail-newsletter/privacy-statement-oshmail';
  $export['subscribe_block_details_link_url'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'subscribe_block_intro_text';
  $strongarm->value = 'Once a month, OSHmail keeps you updated on occupational safety and health in general.';
  $export['subscribe_block_intro_text'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'subscribe_block_intro_text_second_line_end';
  $strongarm->value = '';
  $export['subscribe_block_intro_text_second_line_end'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'subscribe_block_intro_text_second_line_start';
  $strongarm->value = '';
  $export['subscribe_block_intro_text_second_line_start'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'subscribe_block_newsletter_page_url';
  $strongarm->value = '';
  $export['subscribe_block_newsletter_page_url'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'subscribe_block_subscribers_no';
  $strongarm->value = '';
  $export['subscribe_block_subscribers_no'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'subscribe_extra_block_details_link_label';
  $strongarm->value = 'Privacy policy';
  $export['subscribe_extra_block_details_link_label'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'subscribe_extra_block_details_link_url';
  $strongarm->value = 'node/1015';
  $export['subscribe_extra_block_details_link_url'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'subscribe_extra_block_intro_text';
  $strongarm->value = 'To get the latest news from the Healthy Workplaces Campaign 2016–17 direct to your inbox, sign up for our bimonthly newsletter. We’ll cover all the big events and key issues to keep you up to date.';
  $export['subscribe_extra_block_intro_text'] = $strongarm;

  return $export;
}
