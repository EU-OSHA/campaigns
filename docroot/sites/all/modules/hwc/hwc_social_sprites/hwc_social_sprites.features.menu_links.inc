<?php
/**
 * @file
 * hwc_social_sprites.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function hwc_social_sprites_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: management_text-resize:admin/config/user-interface/text_resize
  $menu_links['management_text-resize:admin/config/user-interface/text_resize'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/config/user-interface/text_resize',
    'router_path' => 'admin/config/user-interface/text_resize',
    'link_title' => 'Text Resize',
    'options' => array(
      'attributes' => array(
        'title' => 'Settings for your Text Resize block.',
      ),
      'alter' => TRUE,
      'identifier' => 'management_text-resize:admin/config/user-interface/text_resize',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
    'language' => 'und',
    'menu_links_customized' => 0,
    'parent_identifier' => 'management_user-interface:admin/config/user-interface',
  );
  // Exported menu link: menu-footer-menu_accessibility:node/100
  $menu_links['menu-footer-menu_accessibility:node/100'] = array(
    'menu_name' => 'menu-footer-menu',
    'link_path' => 'node/100',
    'router_path' => 'node/%',
    'link_title' => 'Accessibility',
    'options' => array(
      'alter' => TRUE,
      'attributes' => array(),
      'item_attributes' => array(
        'id' => '',
        'class' => '',
        'style' => '',
      ),
      'identifier' => 'menu-footer-menu_accessibility:node/100',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 2,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
    'parent_identifier' => 'menu-footer-menu_links:<front>',
  );
  // Exported menu link: menu-footer-menu_contact:contact
  $menu_links['menu-footer-menu_contact:contact'] = array(
    'menu_name' => 'menu-footer-menu',
    'link_path' => 'contact',
    'router_path' => 'contact',
    'link_title' => 'Contact',
    'options' => array(
      'alter' => TRUE,
      'identifier' => 'menu-footer-menu_contact:contact',
      'attributes' => array(),
      'item_attributes' => array(
        'id' => '',
        'class' => '',
        'style' => '',
      ),
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 1,
    'customized' => 1,
    'language' => 'en',
    'menu_links_customized' => 1,
    'parent_identifier' => 'menu-footer-menu_links:<front>',
  );
  // Exported menu link: menu-footer-menu_facebook:https://www.facebook.com/EuropeanAgencyforSafetyandHealthatWork
  $menu_links['menu-footer-menu_facebook:https://www.facebook.com/EuropeanAgencyforSafetyandHealthatWork'] = array(
    'menu_name' => 'menu-footer-menu',
    'link_path' => 'https://www.facebook.com/EuropeanAgencyforSafetyandHealthatWork',
    'router_path' => '',
    'link_title' => 'Facebook',
    'options' => array(
      'attributes' => array(),
      'item_attributes' => array(
        'id' => '',
        'class' => '',
        'style' => '',
      ),
      'alter' => TRUE,
      'content' => array(
        'image' => 'public://menuimage/facebook.png',
      ),
      'identifier' => 'menu-footer-menu_facebook:https://www.facebook.com/EuropeanAgencyforSafetyandHealthatWork',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 2,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
    'parent_identifier' => 'menu-footer-menu_social:<front>',
  );
  // Exported menu link: menu-footer-menu_legal-notice:node/103
  $menu_links['menu-footer-menu_legal-notice:node/103'] = array(
    'menu_name' => 'menu-footer-menu',
    'link_path' => 'node/103',
    'router_path' => 'node/%',
    'link_title' => 'Legal notice',
    'options' => array(
      'alter' => TRUE,
      'attributes' => array(),
      'item_attributes' => array(
        'id' => '',
        'class' => '',
        'style' => '',
      ),
      'identifier' => 'menu-footer-menu_legal-notice:node/103',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 8,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
    'parent_identifier' => 'menu-footer-menu_links:<front>',
  );
  // Exported menu link: menu-footer-menu_linkedin:http://www.linkedin.com/company/european-agency-for-safety-and-health-at-work
  $menu_links['menu-footer-menu_linkedin:http://www.linkedin.com/company/european-agency-for-safety-and-health-at-work'] = array(
    'menu_name' => 'menu-footer-menu',
    'link_path' => 'http://www.linkedin.com/company/european-agency-for-safety-and-health-at-work',
    'router_path' => '',
    'link_title' => 'LinkedIn',
    'options' => array(
      'attributes' => array(),
      'item_attributes' => array(
        'id' => '',
        'class' => '',
        'style' => '',
      ),
      'alter' => TRUE,
      'content' => array(
        'image' => 'public://menuimage/linkedin.png',
      ),
      'identifier' => 'menu-footer-menu_linkedin:http://www.linkedin.com/company/european-agency-for-safety-and-health-at-work',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 3,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
    'parent_identifier' => 'menu-footer-menu_social:<front>',
  );
  // Exported menu link: menu-footer-menu_links:<front>
  $menu_links['menu-footer-menu_links:<front>'] = array(
    'menu_name' => 'menu-footer-menu',
    'link_path' => '<front>',
    'router_path' => '',
    'link_title' => 'Links',
    'options' => array(
      'alter' => TRUE,
      'attributes' => array(),
      'item_attributes' => array(
        'id' => '',
        'class' => '',
        'style' => '',
      ),
      'identifier' => 'menu-footer-menu_links:<front>',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 1,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
  );
  // Exported menu link: menu-footer-menu_log-in:user
  $menu_links['menu-footer-menu_log-in:user'] = array(
    'menu_name' => 'menu-footer-menu',
    'link_path' => 'user',
    'router_path' => 'user',
    'link_title' => 'Log in',
    'options' => array(
      'alter' => TRUE,
      'identifier' => 'menu-footer-menu_log-in:user',
      'attributes' => array(),
      'item_attributes' => array(
        'id' => '',
        'class' => '',
        'style' => '',
      ),
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 6,
    'customized' => 1,
    'language' => 'en',
    'menu_links_customized' => 1,
    'parent_identifier' => 'menu-footer-menu_links:<front>',
  );
  // Exported menu link: menu-footer-menu_privacy-notice:node/102
  $menu_links['menu-footer-menu_privacy-notice:node/102'] = array(
    'menu_name' => 'menu-footer-menu',
    'link_path' => 'node/102',
    'router_path' => 'node/%',
    'link_title' => 'Privacy notice',
    'options' => array(
      'alter' => TRUE,
      'attributes' => array(),
      'item_attributes' => array(
        'id' => '',
        'class' => '',
        'style' => '',
      ),
      'identifier' => 'menu-footer-menu_privacy-notice:node/102',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 7,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
    'parent_identifier' => 'menu-footer-menu_links:<front>',
  );
  // Exported menu link: menu-footer-menu_privacy-policy:node/101
  $menu_links['menu-footer-menu_privacy-policy:node/101'] = array(
    'menu_name' => 'menu-footer-menu',
    'link_path' => 'node/101',
    'router_path' => 'node/%',
    'link_title' => 'Privacy policy',
    'options' => array(
      'alter' => TRUE,
      'attributes' => array(),
      'item_attributes' => array(
        'id' => '',
        'class' => '',
        'style' => '',
      ),
      'identifier' => 'menu-footer-menu_privacy-policy:node/101',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 3,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
    'parent_identifier' => 'menu-footer-menu_links:<front>',
  );
  // Exported menu link: menu-footer-menu_rss:node/128
  $menu_links['menu-footer-menu_rss:node/128'] = array(
    'menu_name' => 'menu-footer-menu',
    'link_path' => 'node/128',
    'router_path' => 'node/%',
    'link_title' => 'RSS',
    'options' => array(
      'attributes' => array(),
      'item_attributes' => array(
        'id' => '',
        'class' => '',
        'style' => '',
      ),
      'alter' => TRUE,
      'identifier' => 'menu-footer-menu_rss:node/128',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 4,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
    'parent_identifier' => 'menu-footer-menu_links:<front>',
  );
  // Exported menu link: menu-footer-menu_site-map:sitemap
  $menu_links['menu-footer-menu_site-map:sitemap'] = array(
    'menu_name' => 'menu-footer-menu',
    'link_path' => 'sitemap',
    'router_path' => 'sitemap',
    'link_title' => 'Site map',
    'options' => array(
      'alter' => TRUE,
      'identifier' => 'menu-footer-menu_site-map:sitemap',
      'attributes' => array(),
      'item_attributes' => array(
        'id' => '',
        'class' => '',
        'style' => '',
      ),
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 5,
    'customized' => 1,
    'language' => 'en',
    'menu_links_customized' => 1,
    'parent_identifier' => 'menu-footer-menu_links:<front>',
  );
  // Exported menu link: menu-footer-menu_social:<front>
  $menu_links['menu-footer-menu_social:<front>'] = array(
    'menu_name' => 'menu-footer-menu',
    'link_path' => '<front>',
    'router_path' => '',
    'link_title' => 'Social',
    'options' => array(
      'alter' => TRUE,
      'attributes' => array(),
      'item_attributes' => array(
        'id' => '',
        'class' => '',
        'style' => '',
      ),
      'identifier' => 'menu-footer-menu_social:<front>',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 1,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
  );
  // Exported menu link: menu-footer-menu_twitter:https://twitter.com/eu_osha
  $menu_links['menu-footer-menu_twitter:https://twitter.com/eu_osha'] = array(
    'menu_name' => 'menu-footer-menu',
    'link_path' => 'https://twitter.com/eu_osha',
    'router_path' => '',
    'link_title' => 'Twitter',
    'options' => array(
      'alter' => TRUE,
      'content' => array(
        'image' => 'public://menuimage/twitter.png',
      ),
      'attributes' => array(
        'target' => '_blank',
      ),
      'item_attributes' => array(
        'id' => '',
        'class' => '',
        'style' => '',
      ),
      'identifier' => 'menu-footer-menu_twitter:https://twitter.com/eu_osha',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 1,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
    'parent_identifier' => 'menu-footer-menu_social:<front>',
  );
  // Exported menu link: menu-footer-menu_youtube:https://www.youtube.com/user/EUOSHA
  $menu_links['menu-footer-menu_youtube:https://www.youtube.com/user/EUOSHA'] = array(
    'menu_name' => 'menu-footer-menu',
    'link_path' => 'https://www.youtube.com/user/EUOSHA',
    'router_path' => '',
    'link_title' => 'YouTube',
    'options' => array(
      'attributes' => array(),
      'item_attributes' => array(
        'id' => '',
        'class' => '',
        'style' => '',
      ),
      'alter' => TRUE,
      'content' => array(
        'image' => 'public://menuimage/youtube.png',
      ),
      'identifier' => 'menu-footer-menu_youtube:https://www.youtube.com/user/EUOSHA',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 4,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
    'parent_identifier' => 'menu-footer-menu_social:<front>',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Accessibility');
  t('Contact');
  t('Facebook');
  t('Legal notice');
  t('LinkedIn');
  t('Links');
  t('Log in');
  t('Privacy notice');
  t('Privacy policy');
  t('RSS');
  t('Site map');
  t('Social');
  t('Text Resize');
  t('Twitter');
  t('YouTube');


  return $menu_links;
}
