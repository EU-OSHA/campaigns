<?php if($node->title != NULL) {?>
<table id="node-<?php print $node->nid; ?>" border="0" cellpadding="0" cellspacing="0" width="100%">
  <tbody>
    <?php
    if (isset($node->field_publication_date[LANGUAGE_NONE][0]['value']) && $node->type != 'newsletter_article') {
      $date = strtotime($node->field_publication_date[LANGUAGE_NONE][0]['value']);
    ?>
      <tr>
        <td colspan="2">
          <?php
          if($node->type == 'news'){
          $show_date = variable_get('newsletter_items_date_enable',0);
          if($show_date){
            ?>
            <span class="item-date"><?php print format_date($date, 'custom', 'M d, Y');?></span>
            <?php
            }
          }
          else {
            ?>
            <span class="item-date"><?php print format_date($date, 'custom', 'M d, Y');?></span>
            <?php
          }
          ?>
        </td>
      </tr>
    <?php
    } if ($node->type == 'events') {
      $date = (isset($field_start_date) && !empty($field_start_date)) ? strtotime($field_start_date[0]['value']) : '';
      $city_location = (isset($field_city) && !empty($field_city)) ? $field_city[0]['safe_value'] : '';
      ?>
      <tr>
         <td style="font-family: Arial, sans-serif; font-size: 12px;">
          <span class="item-date"><?php print format_date($date, 'custom', 'M d, Y'); ?></span>
        </td>
      </tr>
    <?php
    }
    ?>
    <tr>
    <!--   <td align="left" width="5%" style="padding-left: 0px; padding-right: 0px; vertical-align: top; padding-top: 5px;">
        <?php
          $directory = drupal_get_path('module','osha_newsletter');
          global $base_url; // TODO: should link to node
          print l(theme('image', array(
          'path' => $directory . '/images/link-arrow.png',
          'width' => 7,
          'height' => 11,
          'alt' => 'link arrow',
          'attributes' => array('style' => 'border: 0px;')
          )), $base_url, array(
          'html' => TRUE,
          'external' => TRUE
        ));
        ?>
      </td> -->
       <td style="text-align: left; padding-top: 5px;">
        <?php
        if (isset($variables['elements']['#campaign_id'])) {
          $url_query = array('pk_campaign' => $variables['elements']['#campaign_id']);
        } else {
          $url_query = array();
        }
        if ($node->type == 'publication') {
          print l($node->title, url('node/' . $node->nid . '/view', array('absolute' => TRUE)), array(
            'attributes' => array('style' => 'color: #003399; text-decoration: none; font-family:Arial, sans-serif; font-size: 12px; font-weight: bold;'),
            'query' => $url_query,
            'external' => TRUE
          ));
        } else {
          print l($node->title, url('node/' . $node->nid, array('absolute' => TRUE)), array(
            'attributes' => array('style' => 'color: #003399; text-decoration: none; font-family:Arial, sans-serif; font-size: 12px; font-weight: bold;'),
            'query' => $url_query,
            'external' => TRUE
          ));
        }
        ?>
      </td>
    </tr>
    <tr>
      <td colspan="2" style="font-family: Arial, sans-serif; font-size: 12px;">
        <?php
        if($node->type == 'events'){
          ?>
          <span class="item-date"><?php print $node->field_city['und'][0]['value']; ?></span>
          <?php
        }
        ?>
      </td>
    </tr>
    <tr>
      <td colspan="2" style="border-bottom: 1px dotted #749b00; padding-top:10px;"></td>
    </tr>
    <tr>
      <td colspan="2" style="padding-bottom: 10px;" class="space-beyond-dotted-line"></td>
    </tr>
  </tbody>
</table>
<?php } ?>