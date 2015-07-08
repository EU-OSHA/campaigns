<?php
/**
 * @file
 * hwc_social_sprites.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function hwc_social_sprites_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}
