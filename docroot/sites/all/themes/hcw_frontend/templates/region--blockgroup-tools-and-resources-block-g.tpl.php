<?php

/**
 * @file
 * Default theme implementation to display a block group. Technically a block
 * group is a region inside a block. In most cases it does not make much sense
 * to render the block markup around the region, therefore the default
 * implementation just prints the blocks content (i.e. the region).
 *
 * Refer to block.tpl.php for a complete description of the variables available
 * in this template.
 *
 * @see block.tpl.php()
 *
 * @ingroup themeable
 */
?>
<div class="tools-and-resources-block">
<?php print($content); ?>
<?php print l(t('Go to the tools'), 'tools-and-resources', array('attributes' => array('class' => array('btn btn-default')))); ?>
</div>