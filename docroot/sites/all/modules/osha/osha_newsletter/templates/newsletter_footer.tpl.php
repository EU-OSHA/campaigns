<?php
  global $base_url;
  $directory = drupal_get_path('module', 'osha_newsletter');
  if (isset($campaign_id)) {
    $url_query = array('pk_campaign' => $campaign_id);
  } else {
    $url_query = array();
  }
  ?>
<table border="0" cellpadding="0" cellspacing="0" width="800" style="background: url('<?php print file_create_url($directory.'/images/footer-newsletter.png'); ?>') no-repeat; width:800px; height: 88px; margin-left: 25px; font-size: 14px;">
  <tbody>
    <tr>
      <td class="social" style="padding-left: 10px;">
			<?php
				$urllegal = url($base_url.'/en/privacy-policy-campaign-newsletter', array('query' => $url_query));
			?>
			<a href="<?php echo $urllegal; ?>" style="@style; font-weight: bold; color: #FFF">Privacy notice</a>
			<?php
				$url = url($base_url.'/en/healthy-workplaces-newsletter', array('query' => $url_query));
			?>
			<span style="color:#FFF"> | </span> 
			<a href="<?php echo $url; ?>" style="@style; font-weight: bold; color: #FFF">Unsubscribe</a>
      </td>
      <td style="text-align: right; padding-right: 10px;">
			<h2 style="color: #ffffff; display: inline; font-weight: bold; font-size: 14px; font-style: normal;">Follow us on:</h2>
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
				  'attributes' => array('style' => 'color:#144989; text-decoration:none; display: inline-block; vertical-align: middle; margin-left: 10px;'),
				  'html' => TRUE,
				  'external' => TRUE
				));
			  }
			?>  
      </td>
    </tr>
  </tbody>
</table>
