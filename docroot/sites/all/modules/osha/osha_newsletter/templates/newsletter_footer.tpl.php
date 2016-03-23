<?php
  global $base_url;
  $directory = drupal_get_path('module', 'osha_newsletter');
  if (isset($campaign_id)) {
    $url_query = array('pk_campaign' => $campaign_id);
  } else {
    $url_query = array();
  }
  ?>
<table border="0" cellpadding="0" cellspacing="0" width="800" style="margin-left: 25px;">
  <tbody>
    <tr>
      <td style="background: url('<?php print file_create_url('/sites/all/modules/osha/osha_newsletter/images/footer-newsletter.png'); ?>') no-repeat; width:800px; height: 88px; padding-left: 10px;" class="social">
			<?php
				$urllegal = url($base_url.'/en/privacy-policy-campaign-newsletter', array('query' => $url_query));
			?>
			<a href="<?php echo $urllegal; ?>" style="@style; font-weight: bold; color: #FFF">Privacy notice</a>
			<?php
				$url = url($base_url.'/en/healthy-workplaces-newsletter', array('query' => $url_query));
			?>
			<span style="color:#FFF"> | </span> 
			<a href="<?php echo $url; ?>" style="@style; font-weight: bold; color: #FFF">Unsubscribe</a>
			<h2 style="padding-left: 300px; color: #ffffff; display: inline; margin-right: 20px; vertical-align: top; font-weight: bold; font-size: 17px; font-style: normal;">Follow us on:</h2>
			<?php
			  $social = array(
				'face' => array(
				  'path' => 'https://www.facebook.com/EuropeanAgencyforSafetyandHealthatWork',
				  'alt' => t('Facebook')
				),
				'twitter' => array(
				  'path' => 'https://twitter.com/eu_osha',
				  'alt' => t('Twitter')
				),
				'linkedin' => array(
				  'path' => 'https://www.linkedin.com/company/european-agency-for-safety-and-health-at-work',
				  'alt' => t('LinkedIn')
				),
				'youtube' => array(
				  'path' => 'https://www.youtube.com/user/EUOSHA',
				  'alt' => t('Youtube')
				)
			  );

			  foreach ($social as $name => $options) {
				$directory = drupal_get_path('module','osha_newsletter');
				print l(theme('image', array(
				  'path' => $directory . '/images/' . $name . '.png',
				  'width' => 'auto',

				  'alt' => $options['alt'],
				  'attributes' => array('style' => 'border: 0px;')
				)), $options['path'], array(
				  'attributes' => array('style' => 'color:#144989;text-decoration:none;'),
				  'html' => TRUE,
				  'external' => TRUE
				));
				print ('&nbsp;&nbsp;&nbsp;&nbsp;');
			  }
			?>  
      </td>
    </tr>
  </tbody>
</table>
