<?php
/**
 * @file
 * The "Block" variant of "Contact" pane.
 *
 * @var array $content
 *   An array with all data from settings form.
 */
?>
<section role="region" class="contact--minimized">
  <?php if (!empty($content['override_title_text'])): ?>
    <h4 role="heading">
      <?php print $content['override_title_text']; ?>
    </h4>
  <?php endif; ?>
  <address>
    <?php print $content['zip']; ?> <?php print $content['city']; ?>
    |
    <?php print $content['street']; ?>, <?php print $content['build']; ?>
    |
    <?php print $content['phone']; ?>
  </address>
</section>
