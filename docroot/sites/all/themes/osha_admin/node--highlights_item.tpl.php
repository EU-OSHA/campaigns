<?php

/**
 * @file
 * EU-OSHA's theme implementation to display a newsletter item in Newsletter Highlights view mode.
 *
 * @see template_preprocess()
 * @see template_preprocess_node()
 * @see template_process()
 */
?>
<table id="node-<?php print $node->nid; ?>" border="0" cellpadding="0" cellspacing="0" width="100%" style="padding-top: 0px; margin-bottom: 10px; border-bottom: 1px dotted #749b00;">
  <tbody>
    <tr>
      <td>
        <table border="0" cellpadding="0" cellspacing="0" class="item-thumbnail-and-title" width="100%">
          <tbody>
            <tr>
              <td width="67%" valign="top" style="color: #003399; padding-bottom: 10px; padding-left: 0px; padding-right: 0px; font-family: Oswald, Arial, sans-serif; font-size: 18px; vertical-align: top;">
                <?php
                if (isset($variables['elements']['#campaign_id'])) {
                  $url_query = array('pk_campaign' => $variables['elements']['#campaign_id']);
                } else {
                  $url_query = array();
                }
                if ($node->type == 'publication') {
                  print l($title, url('node/' . $node->nid . '/view', array('absolute' => TRUE)), array(
                    'attributes' => array('style' => 'font-family: Arial, sans-serif; color: #003399; text-decoration: none;'),
                    'query' => $url_query,
                    'external' => TRUE
                  ));
                } else {
                  print l($title, url('node/' . $node->nid, array('absolute' => TRUE)), array(
                    'attributes' => array('style' => 'font-family: Arial, sans-serif; color: #003399; text-decoration: none;'),
                    'query' => $url_query,
                    'external' => TRUE
                  ));
                }
                ?>
              </td>
            </tr>
            <tr>
              <td style="font-family: Arial, sans-serif; font-weight: bold; font-size: 12px; padding-bottom: 10px;">
                <?php
                $date = (isset($field_publication_date) && !empty($field_publication_date)) ? strtotime($field_publication_date[0]['value']) : '';
                print format_date($date, 'custom', 'M d, Y');
                ?>
              </td>
            </tr>
          </tbody>
        </table>
        <table border="0" cellpadding="0" cellspacing="0" class="item-summary" width="100%" style="padding-bottom: 10px;">
          <tbody>
            <tr>
              <td style="width: 100%; font-size: 13px; font-family: Arial, sans-serif; color: #000000;">
                <?php
                print l(theme('image_style', array(
                  'style_name' => 'newsletter_thumb',
                  'path' => (isset($field_image) && !empty($field_image)) ? $field_image[0]['uri'] : '',
                  'width' => 100,
                  'alt' => (isset($field_image) && !empty($field_image)) ? $field_image[0]['alt'] : '',
                  'attributes' => array('style' => 'width: 100px; heigth: auto; border: 0px; padding-right: 5px; padding-bottom: 5px;', 'align' => 'left', 'hspace' => 20, 'vspace' => 20)
                )), url('node/' . $node->nid, array('absolute' => TRUE)), array(
                  'html' => TRUE,
                  'external' => TRUE
                ));
                ?>

                <?php
                if (!empty($field_summary['en'][0]['safe_value'])) {?>
                  <span style="font-weight: bold;">
                    <?php print $field_summary['en'][0]['safe_value']; ?>
                  </span>
                  <br>
                <?php } ?>
                <?php if (isset($body) && is_array($body)) {
                  if (!empty($body)) {
                    if (isset($body[0]['safe_value'])) { ?>
                     <div class="safe_value"> <?php print($body[0]['safe_value']); ?> </div>
              <?php }
                  }
                }?>
              </td>
            </tr>
          </tbody>
        </table>
      </td>
    </tr>
  </tbody>
</table>