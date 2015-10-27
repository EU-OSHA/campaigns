<div class="<?php print $classes; ?>"<?php print $attributes; ?>>
  <?php if (!$label_hidden): ?>
    <div class="field-label"<?php print $title_attributes; ?>><?php print $label ?>:&nbsp;</div>
  <?php endif; ?>
  <div class="field-items"<?php print $content_attributes; ?>>
    <?php foreach ($items as $delta => $item): ?>
      <div class="field-item col-sm-4 <?php print $delta % 3 ? '' : 'clearfix'; ?>"<?php print $item_attributes[$delta]; ?>><?php print render($item); ?></div>
    <?php endforeach; ?>
  </div>
</div>