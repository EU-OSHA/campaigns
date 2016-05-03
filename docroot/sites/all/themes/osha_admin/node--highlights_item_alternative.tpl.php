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

<table id="node-<?php print $node->nid; ?>" border="0" cellpadding="0" cellspacing="0" width="100%" style="padding-top: 0px; margin-bottom: 20px; border-bottom: 1px dotted #749b00;">
  <tbody>
    <tr>
      <td>
        <table border="0" cellpadding="0" cellspacing="0" class="item-thumbnail-and-title" width="100%">
          <tbody>
            <tr>
              <td>
                <?php
                print l(theme('image_style', array(
                  'style_name' => 'newsletter_thumb',
                  'path' => (isset($field_image) && !empty($field_image)) ? $field_image[0]['uri'] : '',
                  'width' => 150,
                  'alt' => (isset($field_image) && !empty($field_image)) ? $field_image[0]['alt'] : '',
                  'attributes' => array('style' => 'width: 150px; heigth: auto; border: 0px; float: left; padding-right: 20px; padding-bottom:20px;')
                )), url('node/' . $node->nid, array('absolute' => TRUE)), array(
                  'html' => TRUE,
                  'external' => TRUE
                ));
                ?>
              </td>
              <td width="67%">
                <table border="0" cellpadding="0" cellspacing="0" class="item-summary" width="100%" style="padding-bottom: 10px;">
                  <tbody>
                  <tr>
                    <td style="width: 100%; font-size: 12px; font-weight: bold; font-family: Arial, sans-serif; color: #000000;">
                      <?php
                      $date = (isset($field_publication_date) && !empty($field_publication_date)) ? strtotime($field_publication_date[0]['value']) : '';
                      print format_date($date, 'custom', 'M d, Y');
                      ?>
                    </td>
                  </tr>
                  <tr>
                    <td valign="top" style="color: #003399; padding-bottom: 10px; padding-left: 0px; padding-right: 0px; font-family: Oswald, Arial, sans-serif; font-size: 18px; vertical-align: top;">
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
                  <td style="width: 100%; font-size: 13px; font-weight:bold; font-family: Arial, sans-serif; color: #000000;">
                    <?php
                      if (!empty($elements['field_summary'])) {
                    ?>
                        <div class="safe_value"> <?php print render($elements['field_summary']); ?> </div>
                    <?php } ?>
                  </td>
                  <tr>
                    <td style="width: 100%; font-size: 13px; font-family: Arial, sans-serif; color: #000000; padding-bottom: 10px;">
                      <?php if (!empty($elements['body'])) { ?>
                            <div class="safe_value"> <?php print render($elements['body']); ?> </div>
                      <?php } ?>
                    </td>
                  </tr>

                  </tbody>
                </table>

              </td>
            </tr>
          </tbody>
        </table>

      </td>
    </tr>
  </tbody>
</table>