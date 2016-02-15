<<?php print $layout_wrapper; print $layout_attributes; ?> class="hwc-2col-stacked-2col <?php print $classes;?> clearfix">

<?php if (!empty($content['submit_content_form'])): ?>
  <div class="node-submit-validation-form">
    <?php print drupal_render($content['submit_content_form']); ?>
  </div>
<?php endif; ?>

<?php if (isset($title_suffix['contextual_links'])): ?>
  <?php print render($title_suffix['contextual_links']); ?>
<?php endif; ?>
<<?php print $header_wrapper ?> class="group-header<?php print $header_classes; ?>">
<?php print $header; ?>
</<?php print $header_wrapper ?>>

<<?php print $left_wrapper ?> class="group-left<?php print $left_classes; ?>">
<?php print $left; ?>
</<?php print $left_wrapper ?>>

<<?php print $right_wrapper ?> class="group-right<?php print $right_classes; ?>">
<?php print $right; ?>
</<?php print $right_wrapper ?>>

<<?php print $center_wrapper ?> class="group-center<?php print $center_classes; ?>">
<?php print $center; ?>
</<?php print $center_wrapper ?>>

<?php if (!empty($left2) || !empty($right2) || !empty($footer)) { ?>

<<?php print $left2_wrapper ?> class="group-left2<?php print $left2_classes; ?>">
<?php print $left2; ?>
</<?php print $left2_wrapper ?>>

<<?php print $right2_wrapper ?> class="group-right2<?php print $right2_classes; ?>">
<?php print $right2; ?>
</<?php print $right2_wrapper ?>>

  <?php if (!empty($footer)): ?>
    <div class="field-label further-info-label"><?php print t('Further information'); ?></div>
    <<?php print $footer_wrapper ?> class="group-footer<?php print $footer_classes; ?>">
    <?php print $footer; ?>
    </<?php print $footer_wrapper ?>>
  <?php endif; ?>
<?php } ?>

</<?php print $layout_wrapper ?>>

<?php if (!empty($drupal_render_children)): ?>
  <?php print $drupal_render_children ?>
<?php endif; ?>
