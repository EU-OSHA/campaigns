<?php
/**
 * @file
 * hwc_social_sprites.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function hwc_social_sprites_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'access printfriendly'.
  $permissions['access printfriendly'] = array(
    'name' => 'access printfriendly',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'printfriendly',
  );

  // Exported permission: 'administer printfriendly'.
  $permissions['administer printfriendly'] = array(
    'name' => 'administer printfriendly',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'printfriendly',
  );

  return $permissions;
}
