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

<table id="node-<?php print $node->nid; ?>" border="0" cellpadding="0" cellspacing="0" width="100%" style="padding-top: 0px; margin-left: 0px;">
  <tbody>
  <tr>
    <td>
      <table border="0" cellpadding="0" cellspacing="0" class="item-summary" width="100%" style="margin-bottom: 10px; border-bottom: 1px dotted #749b00;">
        <tbody>
        <tr>
          <td style="padding-bottom: 10px; width: 20%; font-size: 12px; font-family: Arial, sans-serif; color: #000000;">
            <?php
            print l(theme('image_style', array(
              'style_name' => 'newsletter_thumb',
              'path' => (isset($field_image) && !empty($field_image)) ? $field_image[0]['uri'] : '',
              'width' => 100,
              'alt' => (isset($field_image) && !empty($field_image)) ? $field_image[0]['alt'] : '',
              'attributes' => array('style' => 'border: 0px; width: 100px; max-width: 100px; padding-right: 5px; padding-bottom: 5px; margin: 0;', 'align' => 'left', 'hspace' => '20', 'vspace' => '20')
            )), url('node/' . $node->nid, array('absolute' => TRUE)), array(
              'html' => TRUE,
              'external' => TRUE
            ));
            ?>
          </td>
          <td style="padding-bottom: 10px; width: 80%; font-size: 12px; font-family: Arial, sans-serif; color: #000000;">
            <b>
              <?php
              $date = (isset($field_publication_date) && !empty($field_publication_date)) ? strtotime($field_publication_date[0]['value']) : '';
              print format_date($date, 'custom', 'M d, Y');
              ?>
            </b>
            <p style="padding-top: 10px; padding-bottom: 10px;">
              <?php
              if (isset($variables['elements']['#campaign_id'])) {
                $url_query = array('pk_campaign' => $variables['elements']['#campaign_id']);
              } else {
                $url_query = array();
              }
              if ($node->type == 'publication') {
                print l($title, url('node/' . $node->nid . '/view', array('absolute' => TRUE)), array(
                  'attributes' => array('style' => 'font-family: Arial, sans-serif; color: #003399; padding-bottom: 10px; padding-left: 0px; padding-right: 0px; font-family: Oswald, Arial, sans-serif; font-size: 18px; vertical-align: top; text-decoration: none;'),
                  'query' => $url_query,
                  'external' => TRUE
                ));
              } else {
                print l($title, url('node/' . $node->nid, array('absolute' => TRUE)), array(
                  'attributes' => array('style' => 'font-family: Arial, sans-serif; color: #003399; padding-bottom: 10px; padding-left: 0px; padding-right: 0px; font-family: Oswald, Arial, sans-serif; font-size: 18px; vertical-align: top; text-decoration: none;'),
                  'query' => $url_query,
                  'external' => TRUE
                ));
              }
              ?>
            </p>

            <?php
            if (!empty($elements['field_summary'])) {?>
              <span style="font-weight: bold;">
                <?php print render($elements['field_summary']); ?>
              </span>
              <br>
            <?php } ?>

            <?php
            if (!empty($elements['body'])) {
              print render($elements['body']);
            }
            ?>
          </td>
        </tr>
        </tbody>
      </table>

    </td>
  </tr>
  </tbody>
</table>