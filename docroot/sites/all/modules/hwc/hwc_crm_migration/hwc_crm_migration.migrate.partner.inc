<?php

/**
 * Class MigrateOshaBlog migrates blog.txt contents. The data
 * is stored inside the <em>Blog</em> content type.
 */
class PartnerMigration extends HwcCrmMigration {

  /**
   * {@inheritdoc}
   */
  public function __construct($arguments) {
    $this->source = new MigrateSourceList(
      new PartnerMigrateListXml(),
      new PartnerContentItemXML(),
      $this->exposedFields()
    );
    parent::__construct($arguments);
  }

  protected function getManuallyMigratedFields() {
    return array();
  }

  public function exposedFields() {
    return array(
      'field_guid_organisation',
      'title',
      'title_field',
      'field_general_email',
      'field_general_phone',
      'field_website',
      'field_orgtype',
      'field_bussines_sector',
      'field_mission_statement',
      'field_logo',
      'field_campaign_website',
      'field_ph_address',
      'field_ph_cp',
      'field_ph_town',
      'field_country',
      'field_guid_main_contact',
      'field_main_contact',
      'field_main_contact_email',
      'field_ceo',
      'field_ceo_photo',
      'field_category',
      'field_social_dialog_partner',
      'field_pledge',
      'field_quote',
      'field_partner_type',
      'field_organisation_rep',
      'field_position_identifier',
      'field_appform_status',
      'field_facebook_profile',
      'field_twitter_profile',
      'field_youtube_profile',
      'field_slideshare_profile',
      'field_linkedin_profile',
      'field_google_plus_profile',
      'field_pinterest_profile',
      'field_abbreviation_name',
    );
  }

  public function prepareRow($row) {
    /** @var stdClass $term */
    if ($term = osha_workflow_get_partner_section_by_guid($row->field_guid_organisation)) {
      $row->workbench_access[$term->tid] = $term->tid;
      if (strtolower($term->name) != strtolower($row->title)) {
        $term->name = $row->title;
        taxonomy_term_save($term);
        $row->regenerate_alias = TRUE;
      }
    }
    else {
      if ($term = osha_workflow_create_section($row->title, $row->field_guid_organisation)) {
        $this->currentMigration()->displayMessage(
          strtr('Creating new section with GUID: @guid for partner \'@partner\'',
            array('@guid' => $row->field_guid_organisation, '@partner' => $row->title)
          ),
          'warning'
        );
        $row->workbench_access[$term->tid] = $term->tid;
      }
      else {
        $this->currentMigration()->displayMessage(
            strtr('Unable to create new section with GUID: @guid for partner \'@partner\'',
                array('@guid' => $row->field_guid_organisation, '@partner' => $row->title)
            ),
            'error'
        );
        return FALSE;
      }
    }
    if (isset($row->field_orgtype)) {
      $tid = _hwc_crm_migration_get_term_by_code('organisation_type', $row->field_orgtype);
      if (!empty($tid)) {
        $term = taxonomy_term_load($tid);
        $row->field_orgtype = $term->name;
      }
      else {
        $this->currentMigration()->displayMessage(
          strtr('Could not find organisation_type term with code @code for partner \'@partner\'',
            array('@code' => $row->field_orgtype, '@partner' => $row->title)
          ),
          'warning'
        );
        unset($row->field_orgtype);
      }
    }
    if (isset($row->field_bussines_sector)) {
      $tid = _hwc_crm_migration_get_term_by_code('bussines_sector', $row->field_bussines_sector);
      if (!empty($tid)) {
        $term = taxonomy_term_load($tid);
        $row->field_bussines_sector = $term->name;
      }
      else {
        $this->currentMigration()->displayMessage(
          strtr('Could not find bussines_sector term with code @code for partner \'@partner\'',
            array('@code' => $row->field_bussines_sector, '@partner' => $row->title)
          ),
          'warning'
        );
      }
    }
    if (!empty($row->field_country)) {
      $term = taxonomy_get_term_by_name($row->field_country);
      if (empty($term)) {
        $voc = taxonomy_vocabulary_machine_name_load('country');
        $term = new stdClass();
        $term->vid = $voc->vid;
        $term->name = ucwords(strtolower($row->field_country));
        $term->language = 'en';
        taxonomy_term_save($term);
        $row->field_country = $term->name;
      }
    }
    return TRUE;
  }

  public function prepare($entity, $row) {
    $entity->status = 1;
    // Unpublish partner if status is not 863680005 (MH-129) - except fop.
    $term = taxonomy_get_term_by_name($row->field_partner_type, 'partner_types');
    $is_fop = FALSE;
    if (!empty($term)) {
      $term = current($term);
      if ($term->uuid == PARTNER_TYPE_FOP) {
        $is_fop = TRUE;
      }
    }
    if (!$is_fop && $row->field_appform_status != 863680005) {
      $this->currentMigration()->displayMessage(
        strtr('The partner profile "@partner" does not have app form status published; unpublishing...',
          array('@partner' => $row->title)
        ),
        'warning'
      );
      $entity->status = 0;
    }
    $entity->path['pathauto'] = TRUE;
    if (!empty($row->regenerate_alias) && !empty($entity->nid)) {
      if ($existing_alias = _pathauto_existing_alias_data('node/' . $entity->nid, 'en')) {
        // Remove old alias
        path_delete($existing_alias['pid']);
        // Redirect old alias
        $redirect = new stdClass();
        redirect_object_prepare($redirect);
        $redirect->source = $existing_alias['alias'];
        $redirect->redirect = $existing_alias['source'];
        $redirect->language = LANGUAGE_NONE;
        // Check if the redirect exists before saving.
        $hash = redirect_hash($redirect);
        if (!redirect_load_by_hash($hash)) {
          redirect_save($redirect);
        }
      }
    }
  }
}


class PartnerMigrateListXml extends AbstractCrmMigrateListXml {

  public function __construct() {
    $file = variable_get('hwc_crm_data_dir', '') . '/PublicProfile.xml';
    parent::__construct($file);
  }

  public function transliterateString($string) {
    if (function_exists('transliterator_transliterate')) {
      return transliterator_transliterate('Any-Latin; Latin-ASCII; [\u0080-\u7fff] remove', $string);
    }
    return iconv('UTF-8', 'ASCII//TRANSLIT//IGNORE', $string);
  }

  public function prepareFileName($data, $suf) {
    $filename = $this->transliterateString($data->title);
    $short_title = trim(substr($filename, 0, 20));
    return $short_title . $suf . '_' . $data->field_guid_organisation;
  }


  protected function parseSourceFile() {
    self::$data = array();
    if (!is_readable($this->file)) {
      watchdog('hwc_crm_migration', 'Cannot find migration files: @file (set `hwc_crm_data_dir` properly)', array('@file' => $this->file), WATCHDOG_WARNING);
      throw new MigrateException(strtr('Cannot find migration files: @file', array('@file' => $this->file)));
    }
    if ($xml = simplexml_load_file($this->file, 'SimpleXMLElement', LIBXML_COMPACT | LIBXML_PARSEHUGE)) {
      // Contact fields are attributes of Detail.
      foreach ($xml->xpath('//Details') as $item) {
        $data = new stdClass();
        $attributes = $item->attributes();
        $data->title = trim((string) $attributes['Textbox1']);
        $data->title_field = $data->title;
        $data->field_guid_organisation = (string) $attributes['Table0_Details1'];
        $data->field_general_email = (string) $attributes['Textbox2'];
        $data->field_general_phone = (string) $attributes['Textbox3'];
        $data->field_website = (string) $attributes['Textbox4'];
        $data->field_orgtype = (string) $attributes['Textbox5'];
        $data->field_bussines_sector = (string) $attributes['Textbox6'];
        $data->field_mission_statement = (string) $attributes['Textbox7'];
        $data->field_abbreviation_name = (string) $attributes['Textbox38'];

        $logo_image = base64_decode((string) $attributes['Textbox8']);
        $logo_ext = (string) $attributes['Textbox9'];
        if (!empty($logo_image) && !empty($logo_ext)) {
          $data->field_logo = $logo_image;
          $filename = $this->prepareFileName($data, '_logo');
          $data->field_logo_file = file_munge_filename($filename . '.' . $logo_ext, '');
          $data->field_logo_mime = (string) $attributes['Textbox9'];
        }

        $data->field_campaign_website = (string) $attributes['Textbox10'];
        $data->field_facebook_profile = (string) $attributes['Textbox11'];
        $data->field_twitter_profile = (string) $attributes['Textbox12'];
        $data->field_youtube_profile = (string) $attributes['Textbox13'];
        $data->field_slideshare_profile = (string) $attributes['Textbox14'];
        $data->field_linkedin_profile = (string) $attributes['Textbox15'];
        $data->field_google_plus_profile = (string) $attributes['Textbox37'];
        $data->field_pinterest_profile = (string) $attributes['Textbox36'];

        $data->field_ph_address = (string) $attributes['Textbox16'];
        $data->field_ph_cp = (string) $attributes['Textbox17'];
        $data->field_country = (string) $attributes['Textbox18'];
        $data->field_ph_town = (string) $attributes['Textbox19'];
        $data->field_guid_main_contact = (string) $attributes['Textbox20'];
        $data->field_main_contact = trim((string) $attributes['Textbox21'] . ' ' . (string) $attributes['Textbox22']);
        $data->field_main_contact_email = (string) $attributes['Textbox23'];

        $data->field_ceo = trim((string) $attributes['Textbox24'] . ' ' . (string) $attributes['Textbox25']);
        $ceo_image = base64_decode((string) $attributes['Textbox26']);
        $ceo_image_ext = (string) $attributes['Textbox27'];
        if (!empty($ceo_image) && !empty($ceo_image_ext)) {
          $data->field_ceo_photo = $ceo_image;
          $filename = $this->prepareFileName($data, '_ceo');
          $data->field_ceo_photo_file = file_munge_filename($filename . '.' . $ceo_image_ext, '');
        }

        // Try to assign a valid partner type term
        $partner_type = (string) $attributes['Textbox28'];
        $term = taxonomy_get_term_by_name($partner_type, 'partner_types');
        if (!empty($term)) {
          $data->field_partner_type = (string) $attributes['Textbox28'];
        }
        else {
          watchdog('hwc_crm_migration', 'Ignoring partner with type @type in the vocabulary for organisation @organisation',
            array(
              '@type' => $partner_type,
              '@organisation' => $data->title
            ), WATCHDOG_WARNING);
          continue;
        }

        $data->field_social_dialog_partner = (string) $attributes['Textbox29'];
        if (strtolower($data->field_social_dialog_partner) == 'false') {
          $data->field_social_dialog_partner = 0;
        }
        else {
          $data->field_social_dialog_partner = 1;
        }

        $data->field_quote = (string) $attributes['Textbox30'];
        $data->field_pledge = (string) $attributes['Textbox31'];
        $data->field_organisation_rep = trim((string) $attributes['Textbox32'] . ' ' . (string) $attributes['Textbox33']);
        $data->field_position_identifier = (string) $attributes['Textbox34'];
        $data->field_appform_status = (string) $attributes['Textbox35'];
        if (empty(self::$data[$data->field_guid_organisation])) {
          self::$data[$data->field_guid_organisation] = $data;
        }
      }
    }
  }
}

class PartnerContentItemXML extends MigrateItem {

  /**
   * {@inheritdoc}
   */
  public function getItem($item_id) {
    if (array_key_exists($item_id, PartnerMigrateListXml::$data)) {
      return (object) PartnerMigrateListXml::$data[$item_id];
    }
    return NULL;
  }
}
