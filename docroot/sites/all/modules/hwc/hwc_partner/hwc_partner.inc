<?php

/**
 * Retrieve partner node by its corresponding section ID.
 *
 * @param integer $id
 *   Section id for the corresponding partner.
 *
 * @return mixed
 *   Returns partner node object or FALSE if not found
 */
function hwc_partner_by_section_id_load($id) {
  // @todo: We could improve with direct query on node & workbench_access_node.
  $q = new EntityFieldQuery();
  $q->entityCondition('entity_type', 'node');
  $q->entityCondition('bundle', 'partner');
//  $q->propertyCondition('status', NODE_PUBLISHED);
//  $q->fieldCondition('field_appform_status', 'value', _hwc_partner_get_appform_codes(), 'IN');
  $result = $q->execute();
  if (isset($result['node'])) {
    $partners = entity_load('node', array_keys($result['node']));
    foreach($partners as $partner) {
      if(!empty($partner->workbench_access) && in_array($id, $partner->workbench_access)) {
        return $partner;
      }
    }
  }
  return FALSE;
}

function _hwc_partner_get_appform_codes() {
  return array(863680002, 863680003, 863680011, 863680005);
}

/**
 * Check if the given user matches a partner node (they are in same section).
 *
 * @param stdClass $node
 * @param stdClass $account
 *
 * @return bool
 *   TRUE if the account is partner and matches the current 'partner' $node.
 */
function hwc_partner_match_user_partner($node, $account = NULL) {
  if (empty($account)) {
    global $user;
    $account = $user;
  }
  if (empty($account->workbench_access)) {
    workbench_access_user_load_data($account);
  }
  if ($node && $node->type == 'partner' && in_array(ROLE_CAMPAIGN_PARTNER, $account->roles) && !empty($account->workbench_access) && !empty($node->workbench_access)) {
    foreach(array_keys($account->workbench_access) as $id_section) {
      if (in_array($id_section, $node->workbench_access)) {
        return TRUE;
      }
    }
  }
  return FALSE;
}

/**
 * Retrieve the corresponding partner for a given account.
 *
 * It checks the sections and matches current user sections (editor) with
 * agains partner sections.
 *
 * @param stdClass $account
 *   Account to retrieve partner for - if NULL, global $user is used
 *
 * @return null
 */
function hwc_partner_get_account_partner($account = NULL) {
  $ret = NULL;
  if (empty($account)) {
    global $user;
    $account = $user;
  }
  if (empty($account->workbench_access)) {
    workbench_access_user_load_data($account);
  }
  if (!empty($account->workbench_access)) {
    reset($account->workbench_access);
    if ($id_section = key($account->workbench_access)) {
      $ret = hwc_partner_by_section_id_load($id_section);
    }
  }
  return $ret;
}

function hwc_partner_is_ocp($partner) {
  $ret = FALSE;
  if ($partner && $partner->type == 'partner') {
    /** @var stdClass $wrapper */
    $wrapper = entity_metadata_wrapper('node', $partner);
    if ($type = $wrapper->field_partner_type->value()) {
      return $type->uuid == PARTNER_TYPE_OCP;
    }
  }
  return $ret;
}

function hwc_partner_is_mp($partner) {
  $ret = FALSE;
  if ($partner && $partner->type == 'partner') {
    /** @var stdClass $wrapper */
    $wrapper = entity_metadata_wrapper('node', $partner);
    if ($type = $wrapper->field_partner_type->value()) {
      return $type->uuid == PARTNER_TYPE_MP;
    }
  }
  return $ret;
}

function hwc_partner_is_fop($partner) {
  $ret = FALSE;
  if ($partner && $partner->type == 'partner') {
    /** @var stdClass $wrapper */
    $wrapper = entity_metadata_wrapper('node', $partner);
    if ($type = $wrapper->field_partner_type->value()) {
      return $type->uuid == PARTNER_TYPE_FOP;
    }
  }
  return $ret;
}

/**
 * Retrieve partner type.
 *
 * @param stdClass $account
 *   User account to check the partner type.
 *
 * @return mixed
 *   Returns partner type (PARTNER_TYPE_FOP, PARTNER_TYPE_MP, PARTNER_TYPE_OCP) or null
 */
function hwc_partner_get_partner_type($account = NULL) {
  $partner = hwc_partner_get_account_partner($account);

  if (hwc_partner_is_ocp($partner)) {
    return PARTNER_TYPE_OCP;
  } elseif (hwc_partner_is_mp($partner)) {
    return PARTNER_TYPE_MP;
  } elseif (hwc_partner_is_fop($partner)) {
    return PARTNER_TYPE_FOP;
  } else {
    return NULL;
  }

}
