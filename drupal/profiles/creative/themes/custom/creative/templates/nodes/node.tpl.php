<?php
/**
 * @file
 * Default theme implementation to display a node.
 *
 * @var bool $page
 * @var array $content
 * @var string $classes
 * @var string $attributes
 */
?>
<article role="article" class="<?php print $classes; ?>"<?php print $attributes; ?>>
  <?php hide($content['comments']); ?>
  <?php hide($content['links']); ?>

  <?php print render($content); ?>
</article>
