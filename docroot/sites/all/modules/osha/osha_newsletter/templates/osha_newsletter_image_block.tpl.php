<div id="join_subscribers">
	<?php if($background_image_url != NULL) {
		print theme('image', array(
			'path' => $background_image_url,
			'alt' => 'Newsletter background',
		));
	} else {
		$theme_path = drupal_get_path('theme', variable_get('theme_default', 'hwc_frontend'));
		print theme('image', array(
			'path' => $theme_path . '/images/block_newsletter/background.jpg',
			'alt' => 'Newsletter background',
		));
	}?>
	<div id="block_newsletter_image_text">
		<?php print $intro_text ?>
        <?php print($subscribe_form) ?>
    <?php if (!empty($details_link)) { print($details_link); } ?>
	</div>
</div>