<?php
/**
 * @file
 * Default theme implementation to display a block.
 *
 * @var \stdClass $block
 * @var string $content
 */
?>
<?php if (!empty($content)): ?>
  <?php if (!empty($block->subject)): ?>
    <?php print $block->subject; ?>
  <?php endif; ?>

  <?php print $content; ?>
<?php endif; ?>
