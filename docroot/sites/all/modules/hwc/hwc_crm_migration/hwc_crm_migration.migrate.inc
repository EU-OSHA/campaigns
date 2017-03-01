<?php

function hwc_crm_migration_migrate_api() {
  return array(
    'api' => 2,
    'groups' => array(
      'hwc_crm' => array(
        'title' => 'Import data from CRM',
      ),
    ),
    'migrations' => array(
      'partner' => array(
        'group_name' => 'hwc_crm',
        'class_name' => 'PartnerMigration',
        'destination' => 'partner',
      ),
    ),
  );
}

/**
 *
 */
class HwcCrmMigration extends Migration {

  /**
   * {@inheritdoc}
   */
  public function __construct($arguments) {
    parent::__construct($arguments);

    $this->map = new MigrateSQLMap($this->machineName,
      array(
        'id' => array(
          'type' => 'varchar',
          'length' => 200,
          'not null' => TRUE,
          'description' => 'Item code',
        ),
      ),
      MigrateDestinationNode::getKeySchema()
    );

    $node_options = MigrateDestinationNode::options('en', 'full_html');
    $this->destination = new MigrateDestinationNode($arguments['destination'], $node_options);
    $this->bundle = $arguments['destination'];
    $this->addFieldMappings();
  }

  /**
   * Executes after import.
   */
  public function postImport() {
    parent::postImport();
    $this->removeNeedsUpdateItems();
  }

  /**
   * Configure field mappings, reads bundle field information
   */
  protected function addFieldMappings() {
    // Node base fields
    $this->addFieldMapping('uid')->defaultValue(0);
    $this->addFieldMapping('comment')->defaultValue(0);
    $this->addFieldMapping('title', 'title');
    $this->addFieldMapping('workbench_access', 'workbench_access')->defaultValue('section'); // Assign default section

    // Handle field migration in a generic way
    $fields = field_info_instances('node', $this->bundle);
    $exposed = $this->source->fields();
    foreach($fields as $field_name => $field_info) {
      if (in_array($field_name, $exposed) && !in_array($field_name, $this->getManuallyMigratedFields())) {
        $this->addFieldMapping($field_name, $field_name);

        // Extra mappings depending on field type
        $fi = field_info_field($field_name);
        if ($fi['type'] == 'taxonomy_term_reference') {
          $this->addFieldMapping("$field_name:create_term")->defaultValue(TRUE);
          $this->addFieldMapping("$field_name:ignore_case")->defaultValue(TRUE);
        }
        if ($fi['type'] == 'file' || $fi['type'] == 'image') {
          $this->addFieldMapping("$field_name:file_replace")->defaultValue(FILE_EXISTS_REPLACE);
          $this->addFieldMapping("$field_name:file_class")->defaultValue('MigrateFileBlob');
          $this->addFieldMapping("$field_name:value", $field_name);
          $this->addFieldMapping("$field_name:destination_file", $field_name . "_file");
        }
      }
    }
    $this->addUnmigratedDestinations(
      array(
        'revision', 'tnid', 'translate', 'revision_uid', 'is_new', 'status', 'changed', 'created',
        'sticky', 'log', 'language', 'path',
      )
    );
  }

  protected function getManuallyMigratedFields() {
    return array();
  }

  public function removeNeedsUpdateItems() {
    // Remove non-existing sources.
    $removed = [];
    // Getting guids from source.
    $guids = $this->source->idsToProcess;

    // Get existing nodes.
    $query = db_select('field_data_field_guid_organisation', 'g');
    $query->fields('g', ['entity_id', 'field_guid_organisation_value']);
    $result = $query->execute();
    $existing_partners = $result->fetchAllKeyed();

    // Check guids that are in website and not in source.
    foreach ($existing_partners as $nid => $guid) {
      if (!in_array($guid, $guids)) {
        $removed[] = $nid;
      }
    }
    if (!empty($removed)) {
      foreach ($removed as $nid) {
        if ($node = node_load($nid)) {
          if ($node->status == 1 || !empty($node->field_appform_status)) {
            $node->status = 0;
            $node->field_appform_status = NULL;
            node_save($node);
            $this->currentMigration()->displayMessage(
              strtr('Unpublishing partner @partner - not found in source anymore.',
                array('@partner' => $node->title)
              ),
              'warning'
            );
          }
        }
      }
    }
  }
}

abstract class AbstractCrmMigrateListXml extends MigrateList {
  public static $data = array();

  protected $file = '';

  /**
   * {@inheritdoc}
   */
  public function __construct($file) {
    $this->file = $file;
    $this->parseSourceFile();
  }

  /**
   * {@inheritdoc}
   */
  public function __toString() {
    return $this->file;
  }

  /**
   * Parse the XML file and populate the local cache.
   */
  abstract protected function parseSourceFile();

  /**
   * {@inheritdoc}
   */
  public function getIdList() {
    if (empty(self::$data)) {
      $this->parseSourceFile();
    }
    return array_keys(self::$data);
  }

  /**
   * {@inheritdoc}
   */
  public function computeCount() {
    return count(self::$data);
  }
}
