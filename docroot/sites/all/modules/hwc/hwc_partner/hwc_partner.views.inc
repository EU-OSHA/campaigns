<?php

/**
 * Implements hook_views_data_alter().
 */
function hwc_partner_views_data_alter(&$data) {
  // Define group.
  $data['hwc_partner']['table']['group'] = t('HWC Partner');
  $data['hwc_partner']['table']['join'] = array(
    // #global is a special flag which let's a table appear all the time.
    '#global' => array(),
  );
  // Filters nodes that are in current users RM section.
  $data['hwc_partner']['belongs_partner'] = array(
    'title' => t('If node belongs to current partner or user is author'),
    'help' => t('If node belongs to current partner or user is author'),
    'filter' => array(
      'label' => t('Node belongs to partner or curr user is the author'),
      'handler' => 'hwc_partner_handler_filter_node_belongs_partner',
    ),
  );
  $data['hwc_partner']['cpm_assigned'] = array(
    'title' => t('If node has current CPM assigned'),
    'help' => t('If node has current CPM assigned'),
    'filter' => array(
      'label' => t('If node has current CPM assigned'),
      'handler' => 'hwc_partner_handler_filter_node_is_cpm_assigned',
    ),
  );
  $data['workbench_moderation_node_history']['state']['field']['handler'] = 'hwc_partner_workbench_moderation_handler_field_state';
}


/**
 * Filters nodes that belongs to users partner or the user is author.
 */
class hwc_partner_handler_filter_node_belongs_partner extends views_handler_filter_boolean_operator {

  /**
   * Overrides views_handler_field::query().
   */
  function query() {
    global $user;
    if (empty($user->workbench_access)) {
      workbench_access_user_load_data($user);
    }
    $role = user_role_load_by_name(ROLE_CAMPAIGN_PARTNER);
    if (empty($this->value)) {
      $in_operator = 'NOT IN';
      $equal_operator = '!=';
    }
    else {
      $in_operator = 'IN';
      $equal_operator = '=';
    }
    if (user_has_role($role->rid)) {
      $sections = array_keys($user->workbench_access);
      $subquery = db_select('workbench_access_node', 'workbench_access_node');
      $subquery->addField('workbench_access_node', 'nid');
      $subquery->distinct();
      $subquery->condition('workbench_access_node.access_id', $sections, 'IN');
      $this->query->add_where(0, "{$this->query->base_table}.nid", $subquery, $in_operator);
    }
    else {
      $this->query->add_where(0, "{$this->query->base_table}.uid", $user->uid, $equal_operator);
    }
  }
}


/**
 * Filters nodes that are assigned to current CPM.
 */
class hwc_partner_handler_filter_node_is_cpm_assigned extends views_handler_filter_boolean_operator {

  /**
   * Overrides views_handler_field::query().
   */
  function query() {
    global $user;
    if (empty($user->workbench_access)) {
      workbench_access_user_load_data($user);
    }
    $is_admin = OshaWorkflowPermissions::userHasRole(OSHA_WORKFLOW_ROLE_ADMINISTRATOR, $user);
    $is_supervisor = OshaWorkflowPermissions::userHasRole(ROLE_SUPERVISOR, $user);
    if ($is_admin || $is_supervisor) {
//      return;
    }
    if (empty($this->value)) {
      $in_operator = 'NOT IN';
      $equal_operator = '!=';
    }
    else {
      $in_operator = 'IN';
      $equal_operator = '=';
    }
    $join = new views_join();
    $join->table = 'osha_workflow_node_project_managers';
    $join->field = 'nid';
    $join->left_table = $this->query->base_table;
    $join->left_field = 'nid';
    $join->type = 'INNER';
    $join->extra = array(
      array(
        'field' => 'uid',
        'value' => $user->uid,
      )
    );
    $this->query->add_relationship($this->query->base_table . '_osha_workflow_node_project_managers', $join, $this->query->base_table);
  }
}
