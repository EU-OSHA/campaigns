<div class="hwc-partner-private-link-block-title">
  <?php print $hwc_partner_private_link_title; ?>
</div>
<div class="hwc-partner-private-link-block-description">
  <span>
    <?php print $hwc_partner_private_link_description; ?>
    <?php print $hwc_partner_private_link_link_text; ?>
  </span>
  <p class="draft">
    <?php if ($delta == 'hwc_partner_private_link_0' && !empty($node)) {
      print l('My events', 'node/' . $node->nid . '/events', array('query' =>array('type' => 'events')));
    }
    if ($delta == 'hwc_partner_private_link_1' && !empty($node)) {
      print l('My news', 'node/' . $node->nid . '/news', array('query' =>array('type' => 'news')));
    } ?>
  </p>
</div>
