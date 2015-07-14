<?php
/**
 * @file
 * hwc_homepage_featured.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function hwc_homepage_featured_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: main-menu_campaign-material:<front>
  $menu_links['main-menu_campaign-material:<front>'] = array(
    'menu_name' => 'main-menu',
    'link_path' => '<front>',
    'router_path' => '',
    'link_title' => 'Campaign material',
    'options' => array(
      'item_attributes' => array(
        'id' => '',
        'class' => '',
        'style' => '',
      ),
      'alter' => TRUE,
      'identifier' => 'main-menu_campaign-material:<front>',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -46,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
    'parent_identifier' => 'main-menu_tools-and-resources:node/110',
  );
  // Exported menu link: main-menu_campaign-toolkit:<front>
  $menu_links['main-menu_campaign-toolkit:<front>'] = array(
    'menu_name' => 'main-menu',
    'link_path' => '<front>',
    'router_path' => '',
    'link_title' => 'Campaign toolkit',
    'options' => array(
      'item_attributes' => array(
        'id' => '',
        'class' => '',
        'style' => '',
      ),
      'alter' => TRUE,
      'identifier' => 'main-menu_campaign-toolkit:<front>',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -45,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
    'parent_identifier' => 'main-menu_tools-and-resources:node/110',
  );
  // Exported menu link: main-menu_case-studies:<front>
  $menu_links['main-menu_case-studies:<front>'] = array(
    'menu_name' => 'main-menu',
    'link_path' => '<front>',
    'router_path' => '',
    'link_title' => 'Case studies',
    'options' => array(
      'item_attributes' => array(
        'id' => '',
        'class' => '',
        'style' => '',
      ),
      'alter' => TRUE,
      'identifier' => 'main-menu_case-studies:<front>',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -48,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
    'parent_identifier' => 'main-menu_tools-and-resources:node/110',
  );
  // Exported menu link: main-menu_e-guide:<front>
  $menu_links['main-menu_e-guide:<front>'] = array(
    'menu_name' => 'main-menu',
    'link_path' => '<front>',
    'router_path' => '',
    'link_title' => 'E-Guide',
    'options' => array(
      'alter' => TRUE,
      'item_attributes' => array(
        'id' => '',
        'class' => '',
        'style' => '',
      ),
      'identifier' => 'main-menu_e-guide:<front>',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 1,
    'weight' => -50,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
    'parent_identifier' => 'main-menu_tools-and-resources:node/110',
  );
  // Exported menu link: main-menu_napo-film:<front>
  $menu_links['main-menu_napo-film:<front>'] = array(
    'menu_name' => 'main-menu',
    'link_path' => '<front>',
    'router_path' => '',
    'link_title' => 'Napo film',
    'options' => array(
      'item_attributes' => array(
        'id' => '',
        'class' => '',
        'style' => '',
      ),
      'alter' => TRUE,
      'identifier' => 'main-menu_napo-film:<front>',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -43,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
    'parent_identifier' => 'main-menu_tools-and-resources:node/110',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Campaign material');
  t('Campaign toolkit');
  t('Case studies');
  t('E-Guide');
  t('Napo film');


  return $menu_links;
}
