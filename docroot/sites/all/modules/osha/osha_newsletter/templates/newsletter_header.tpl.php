<?php
$newsletter_ready_date = date('F Y');
if($newsletter_date) {
  $newsletter_ready_date = date('F Y', strtotime($newsletter_date));
}?>
<table border="0" cellpadding="28" cellspacing="0" width="800" style="font-family: Oswald, Arial,sans-serif; margin-left: 25px; margin-bottom: 40px; background-repeat: no-repeat;" height="300" background="<?php print file_create_url('sites/all/modules/osha/osha_newsletter/images/header-newsletter.png'); ?>">
  <tbody>
    <tr>
      <td style="vertical-align: top; padding-top: 0; padding-bottom: 0; padding-left: 50%; height: 90px;">
        <?php
          if (isset($campaign_id)) {
            $url_query = array('pk_campaign' => $campaign_id);
          }
          else {
            $url_query = array();
          }
          $directory = drupal_get_path('module', 'osha_newsletter');
          global $base_url;
        ?>
        <div style="float: left; width: 30%; line-height: 20px;">
          <h4 style="padding-top: 10px; text-align: left; font-size: 14px; font-weight: bold; color: #003399; font-family: Oswald, Arial,sans-serif;line-height: 14px;">
            <?php print t('Healthy Workplaces for All Ages'); ?>
          </h4>
        </div>
        <div style="float: left; padding-top: 8px;">
          <?php
            print l(
              theme(
                'image',
                array(
                  'path' => $directory . '/images/Osha-EU-logos.png',
                  'width' => 105,
                  'alt' => 'Osha logo',
                  'attributes' => array('style' => 'border: 0px;'),
                )
              ),
              $base_url, array(
                'html' => TRUE,
                'external' => TRUE,
                'query' => $url_query,
              )
            );
          ?>
        </div>
        <div style="float: left; padding-top: 48px;">
          <?php
            print l(
              theme(
                'image',
                array(
                  'path' => $directory . '/images/logo-eu.png',
                  'width' => 50,
                  'alt' => 'Osha logo',
                  'attributes' => array('style' => 'border: 0px;'),
                )
              ),
              $base_url, array(
                'html' => TRUE,
                'external' => TRUE,
                'query' => $url_query,
              )
            );
          ?>
        </div>
        <div style="float: left; padding-top: 13px; margin-left: 20px;">
          <?php
            print l(
              theme(
                'image',
                array(
                  'path' => $directory . '/images/healthy_workplaces.png',
                  'width' => 80,
                  'alt' => 'Healthy workplaces logo',
                  'attributes' => array('style' => 'border: 0px;'),
                )
              ),
              $base_url, array(
                'html' => TRUE,
                'external' => TRUE,
                'query' => $url_query,
              )
            );
          ?>
        </div>
      </td>
    </tr>
	<tr><td style="vertical-align: top; padding-top: 10px; padding-left: 50%;">
		<h1 style="font-size: 28px; color: #FFF; border: none; padding: 0; margin: 0; text-align: left; line-height: 28px;"><?php print $newsletter_title ?></h1>
		<h2 style="font-style: italic; font-weight: normal; font-size: 18px; color: #FFF; padding: 0; margin: 0; text-align: left;"><?php print $newsletter_ready_date ?></h2>
		<br />
    <?php if(!empty($newsletter_intro)){ ?>
		<p style="font-style: italic; color: #FFF; font-size: 12px;"><?php print($newsletter_intro);?></p>
    <?php } ?>
	</td></tr>
  </tbody>
</table>
