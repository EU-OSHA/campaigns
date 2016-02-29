<?php foreach ($items as $item): ?>
  <?php print l($entity->title, $item['url'], array('attributes' => array('class' => array('external_url'), 'target' => '_blank'))); ?>
<?php endforeach; ?>
