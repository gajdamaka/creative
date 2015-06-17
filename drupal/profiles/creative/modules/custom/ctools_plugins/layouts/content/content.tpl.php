<?php
/**
 * @file
 * The "Main" layout for Panels Everywhere.
 *
 * @var array $content
 */
?>
<section role="region" class="wrapper content-wrapper clearfix">
  <?php if (!empty($content['content'])): ?>
    <section role="region">
      <?php print $content['content']; ?>
    </section>
  <?php endif; ?>
</section>
