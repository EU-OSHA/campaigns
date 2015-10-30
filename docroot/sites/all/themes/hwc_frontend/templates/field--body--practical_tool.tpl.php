<?php
$label = t('Description');
?>
<div class="field field-name-body field-type-text-long field-label-inline clearfix">
  <div class="field-label"><?php print $label; ?>:&nbsp;</div>
  <div class="field-items">
    <?php foreach ($items as $item): ?>
      <?php print render($item); ?>
    <?php endforeach; ?>
  </div>
</div>
