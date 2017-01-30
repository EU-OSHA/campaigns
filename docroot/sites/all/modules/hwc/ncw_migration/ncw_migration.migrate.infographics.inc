<?php

/**
 * Class NCWInfographicsMigration migrates infographics.
 *
 * Set hwc_migration_infographics_url variable for explicit source URL.
 */
class NCWInfographicsMigration extends AbstractNCWNodeMigration {

  public function __construct($arguments) {
    parent::__construct($arguments, 'NCWInfographicsSource', 'infographic');
    $this->description = 'Import infographics from NCW';
  }

  function addFieldMappings() {
    parent::addFieldMappings();

    $this->addFieldMapping('field_tags:source_type')->defaultValue('tid');
    $this->addFieldMapping('field_tags:create_term')->defaultValue(FALSE);
    $this->addFieldMapping('field_tags', 'field_tags');

    $this->addUnmigratedDestinations(array(
      'field_tags:ignore_case',
      'field_image:title',
      'field_image:file_class',
      'field_image:preserve_files',
      'field_image:destination_dir',
      'field_image:destination_file',
      'field_image:urlencode',
      'field_image:source_dir',
      'field_image:alt',
      'field_thumbnail:title',
      'field_thumbnail:file_class',
      'field_thumbnail:preserve_files',
      'field_thumbnail:destination_dir',
      'field_thumbnail:destination_file',
      'field_thumbnail:urlencode',
      'field_thumbnail:source_dir',
      'field_thumbnail:alt',
      'field_file:file_class',
      'field_file:preserve_files',
      'field_file:destination_dir',
      'field_file:destination_file',
      'field_file:source_dir',
      'field_file:urlencode',
      'field_file:description',
      'field_file:display',
      'field_publication_date:rrule',
    ));
    $this->ignoreMetatagMigration();
  }

  protected function getManuallyMigratedFields() {
    return array('field_tags');
  }

  function prepareRow($row) {
    parent::prepareRow($row);
    // field_twin_infographics
    $fi = field_info_field('field_twin_infographics');
    osha_migration_normalize_field_entityreference($row, 'field_twin_infographics', $fi);
    $twin_infographics = $row->field_twin_infographics;
    $row->field_twin_infographics = array();
    foreach ($twin_infographics as $original_nid) {
      $row->field_twin_infographics[] = $this->handleSourceMigration('infographics', $original_nid);
    }
    $row->field_tags = osha_migration_normalize_migrated_term_reference($row->field_tags, 'tax_tags');
  }
}


class NCWInfographicsSource extends AbstractNCWNodeSource {

  /**
   * The list of available fields to map from the source, keyed by field name.
   */
  public function contentFields() {
    $fields = array(
      'title_field',
      'title_field_language',
      'field_publication_date',
      'field_publication_date_timezone',
      'field_publication_date_value2',
      'body',
      'body_language',
      'body_summary',
      'body_format',
      'field_tags',
      'field_image',
      'field_image_language',
      'field_thumbnail',
      'field_thumbnail_language',
      'field_file',
      'field_file_language',
      'field_twin_infographics'
    );
    return array_combine($fields, $fields);
  }

  /**
   * Include the related infographics recursively into the migrated content.
   */
  public function readData() {
    $this->rows = array();
    $content = $this->fileGetContents($this->endpoint_url);
    if ($data = json_decode($content)) {
      foreach ($data->items as $ob) {
        $ob = $ob->item;
        $id = $this->itemIdentifier($ob);
        $node_url = $this->itemURL($id);
        if ($rowd = $this->fileGetContents($node_url)) {
          if ($row_ob = json_decode($rowd, TRUE)) {
            $row = new stdClass();
            foreach ($row_ob as $k => $v) { $row->$k = $v; }
            $this->rows[$id] = $row;
            $this->children_recursive_infographics($row);
          }
        }
        else {
          $msg = format_string('Failed to read data from !url', array('!url' => $node_url));
          watchdog('ncw_migration', $msg, [], WATCHDOG_ERROR);
          $this->rows[$id] = NULL;
        }
      }
    }
    else {
      $msg = format_string('Failed to read data from !url', array('!url' => $this->endpoint_url));
      watchdog('ncw_migration', $msg, [], WATCHDOG_ERROR);
      throw new MigrateException($msg, Migration::MESSAGE_ERROR);
    }
    reset($this->rows);
  }


  protected function children_recursive_infographics($row) {
    // Check the field_twin_infographics for children and add to source
    $tmp = new stdClass();
    $tmp->field_twin_infographics = $row->field_twin_infographics;
    $firp = field_info_field('field_twin_infographics');
    osha_migration_normalize_field_entityreference($tmp, 'field_twin_infographics', $firp);
    foreach($tmp->field_twin_infographics as $cid) {
      // Skip records already added
      if (array_key_exists($cid, $this->rows)) {
        continue;
      }
      $child_url = $this->itemURL($cid);
      if ($child_rowd = $this->fileGetContents($child_url)) {
        if ($child_row_ob = json_decode($child_rowd, TRUE)) {
          $child_row = new stdClass();
          foreach ($child_row_ob as $k => $v) { $child_row->$k = $v; }
          $this->rows[$cid] = $child_row;
          $this->children_recursive_infographics($child_row);
        }
      }
    }
  }
}
