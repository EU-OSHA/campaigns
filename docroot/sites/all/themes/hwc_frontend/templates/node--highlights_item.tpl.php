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
<table id="node-<?php print $node->nid; ?>" border="0" cellpadding="0" cellspacing="0" width="100%" style="padding-top: 15px;">
  <tbody>
    <tr>
      <td>
        <table border="0" cellpadding="0" cellspacing="0" class="item-thumbnail-and-title" width="100%">
          <tbody>
            <tr>
              <td width="29%" style="padding-bottom:0px;vertical-align: top;padding-top:0px;">
                <?php
                  print l(theme('image_style', array(
                    'style_name' => 'thumbnail',
                    'path' => (isset($field_image) && !empty($field_image)) ? $field_image[0]['uri'] : '',
                    'width' => 100,
                    'alt' => (isset($field_image) && !empty($field_image)) ? $field_image[0]['alt'] : '',
                    'attributes' => array('style' => 'border: 0px;')
                  )), url('node/' . $node->nid, array('absolute' => TRUE)), array(
                    'html' => TRUE,
                    'external' => TRUE
                  ));
                ?>
              </td>
              <td width="67%" valign="top" style="color: #003399; padding-bottom: 10px; padding-left: 0px; padding-right: 0px; font-family: Oswald, Arial, sans-serif; font-size: 18px; vertical-align: top;">
                <?php
                if (isset($variables['elements']['#campaign_id'])) {
                  $url_query = array('pk_campaign' => $variables['elements']['#campaign_id']);
                } else {
                  $url_query = array();
                }
                if ($node->type == 'publication') {
                  print l($title, url('node/' . $node->nid . '/view', array('absolute' => TRUE)), array(
                    'attributes' => array('style' => 'color: #003399; text-decoration: none;'),
                    'query' => $url_query,
                    'external' => TRUE
                  ));
                } else {
                  print l($title, url('node/' . $node->nid, array('absolute' => TRUE)), array(
                    'attributes' => array('style' => 'color: #003399; text-decoration: none;'),
                    'query' => $url_query,
                    'external' => TRUE
                  ));
                }
                ?>
              </td>
            </tr>
          </tbody>
        </table>
        <table border="0" cellpadding="0" cellspacing="0" class="item-summary" width="100%" style="padding-bottom: 10px;">
          <tbody>
            <tr>
              <td style="width: 100%; font-size: 13px; font-family: Arial, sans-serif; color: #000000;">
                <?php if (isset($body) && is_array($body)) {
                  if (!empty($body)) {
                    if (isset($body[0]['safe_value'])) {
                      print($body[0]['safe_value']);
                    }
                  } else if (isset($field_summary) && is_array($field_summary)) {
                    if (!empty($field_summary)) {
                      print($field_summary[0]['safe_value']);
                    }
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