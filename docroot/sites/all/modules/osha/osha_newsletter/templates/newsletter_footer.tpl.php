<?php
global $base_url;
global $language;

$directory = drupal_get_path('module', 'osha_newsletter');
?>
<table border="0" cellpadding="10" cellspacing="0" width="800" style="display: inline-block; background: url('<?php print file_create_url($directory.'/images/footer-newsletter.png'); ?>') no-repeat; width:800px; height: 88px; margin-left: 25px; font-size: 14px;">
  <!--[if gte mso 9]>
  <v:rect xmlns:v="urn:schemas-microsoft-com:vml" fill="true" stroke="false" style="display: inline-table; width:800px;height:88px;">
    <v:fill type="tile" src="<?php print file_create_url($directory.'/images/footer-newsletter.png'); ?>"/>
    <v:textbox inset="0,0,0,0">
  <![endif]-->
  <tbody>
    <tr>
      <td width="800" style="padding-top: 0px; padding-bottom: 0px;">
        <table border="0" cellpadding="5" cellspacing="0" width="100%">
          <tbody>
          <tr>
            <td style="padding-top: 32px;vertical-align: top;">
              <?php
              if (isset($campaign_id)) {
                $url_query = array('pk_campaign' => $campaign_id);
              } else {
                $url_query = array();
              }
              $urllegal = url($base_url.'/'.$language->language.'/privacy-policy-campaign-newsletter', array('query' => $url_query));
              ?>
              <a style="text-decoration: none;" href="<?php echo $urllegal; ?>"><span style="font-family: Arial, sans-serif; font-weight: bold; color: #ffffff; font-size: 14px;"><?php print t('Privacy notice'); ?></span></a>
              <?php
              $url = url($base_url.'/'.$language->language.'/healthy-workplaces-newsletter', array('query' => $url_query));
              ?>
              <span style="color:#ffffff; font-size: 14px;font-family: Arial, sans-serif;"> | </span>
              <a style="text-decoration: none;" href="<?php echo $url; ?>"><span style="font-family: Arial, sans-serif; font-weight: bold; color: #ffffff; font-size: 14px;"><?php print t('Unsubscribe'); ?></span></a>
            </td>
            <td width="1%" style="vertical-align: top; padding-top: 32px; text-align: right; white-space: nowrap">
              <h2 style="color: #ffffff; display: inline; font-family: Arial, sans-serif; font-weight: bold; font-size: 14px; font-style: normal;"><?php print t('Follow us on'); ?>:</h2>
            </td>
            <td width="160" style="vertical-align: top; padding-top: 32px; text-align: right;">
              <?php
              $social = array(
                'twitter' => array(
                  'path' => 'https://twitter.com/eu_osha',
                  'alt' => t('Twitter')
                ),
                'face' => array(
                  'path' => 'https://www.facebook.com/EuropeanAgencyforSafetyandHealthatWork',
                  'alt' => t('Facebook')
                ),
                'linkedin' => array(
                  'path' => 'https://www.linkedin.com/company/european-agency-for-safety-and-health-at-work',
                  'alt' => t('LinkedIn')
                ),
                'youtube' => array(
                  'path' => 'https://www.youtube.com/user/EUOSHA',
                  'alt' => t('Youtube')
                ),
                'flickr' => array(
                  'path' => 'https://www.flickr.com/photos/euosha',
                  'alt' => t('Flickr')
                )
              );

              foreach ($social as $name => $options) {
                $directory = drupal_get_path('module','osha_newsletter');
                print '&nbsp;&nbsp;' . l(theme('image', array(
                  'path' => $directory . '/images/' . $name . '.png',
                  'width' => 'auto',

                  'alt' => $options['alt'],
                  'attributes' => array('style' => 'border: 0px;')
                )), $options['path'], array(
                  'attributes' => array('style' => 'font-family: Arial, sans-serif; color:#144989; text-decoration:none; display: inline-block; vertical-align: middle;'),
                  'html' => TRUE,
                  'external' => TRUE
                ));
              }
              ?>
            </td>
          </tr>
          </tbody>
        </table>
      </td>
    </tr>
  </tbody>
  <!--[if gte mso 9]>
    </v:textbox>
    </v:rect>
  <![endif]-->
</table>
