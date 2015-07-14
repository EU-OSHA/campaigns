<?php
/**
 * @file
 * hwc_homepage_featured.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function hwc_homepage_featured_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'update featured_partner entityqueue'.
  $permissions['update featured_partner entityqueue'] = array(
    'name' => 'update featured_partner entityqueue',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'entityqueue',
  );

  return $permissions;
}
