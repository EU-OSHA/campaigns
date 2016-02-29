<div class="hwc-partner-private-link-block-title">
  <?php print $hwc_partner_private_link_title; ?>
</div>
<div class="hwc-partner-private-link-block-description">
  <?php print $hwc_partner_private_link_description; ?>
  <?php print $hwc_partner_private_link_link_text; ?>
  <p class="draft">
    <?php if ($delta == 'hwc_partner_private_link_0' && !empty($node)) {
      print l('Not published events', 'node/' . $node->nid . '/events');
    }
    if ($delta == 'hwc_partner_private_link_1' && !empty($node)) {
      print l('Not published news', 'node/' . $node->nid . '/news');
    } ?>
  </p>
</div>
