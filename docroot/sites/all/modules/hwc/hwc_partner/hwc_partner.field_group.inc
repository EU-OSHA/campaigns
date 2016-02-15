<?php
/**
 * @file
 * hwc_partner.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function hwc_partner_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_category|node|partner|form';
  $field_group->group_name = 'group_category';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'partner';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Category',
    'weight' => '8',
    'children' => array(
      0 => 'field_partner_type',
      1 => 'field_quote',
      2 => 'field_social_dialog_partner',
      3 => 'field_pledge',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-category field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_category|node|partner|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_ceo|node|partner|form';
  $field_group->group_name = 'group_ceo';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'partner';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'CEO',
    'weight' => '7',
    'children' => array(
      0 => 'field_ceo',
      1 => 'field_ceo_photo',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-ceo field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_ceo|node|partner|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_guid_main_contact|node|partner|form';
  $field_group->group_name = 'group_guid_main_contact';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'partner';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Main Contact',
    'weight' => '6',
    'children' => array(
      0 => 'field_guid_main_contact',
      1 => 'field_main_contact',
      2 => 'field_main_contact_email',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Main Contact',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-main-contact field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsible',
    ),
  );
  $field_groups['group_guid_main_contact|node|partner|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_guid_organisation|node|partner|form';
  $field_group->group_name = 'group_guid_organisation';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'partner';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Guid organisation',
    'weight' => '2',
    'children' => array(
      0 => 'field_campaign_website',
      1 => 'field_general_email',
      2 => 'field_general_phone',
      3 => 'field_guid_organisation',
      4 => 'field_logo',
      5 => 'field_mission_statement',
      6 => 'field_website',
      7 => 'title_field',
      8 => 'field_bussines_sector',
      9 => 'field_orgtype',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-guid-organisation field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_guid_organisation|node|partner|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_ph_address|node|partner|form';
  $field_group->group_name = 'group_ph_address';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'partner';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Ph Address',
    'weight' => '4',
    'children' => array(
      0 => 'field_ph_address',
      1 => 'field_ph_cp',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-ph-address field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_ph_address|node|partner|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('CEO');
  t('Category');
  t('Guid organisation');
  t('Main Contact');
  t('Ph Address');

  return $field_groups;
}
