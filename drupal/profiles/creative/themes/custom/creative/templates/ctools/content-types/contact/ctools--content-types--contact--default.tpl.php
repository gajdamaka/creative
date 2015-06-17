<?php
/**
 * @file
 * The "Block" variant of "Contact" pane.
 *
 * @var array $content
 *   An array with all data from settings form.
 */
?>
<section role="region" class="contact--default">
  <?php if (!empty($content['override_title_text'])): ?>
    <h4 role="heading">
      <?php print $content['override_title_text']; ?>
    </h4>
  <?php endif; ?>
  <div class="about">
    <address>
      <?php print t('Adress'); ?>: <?php print $content['street']; ?> <?php print $content['build']; ?>, <?php print $content['zip']; ?> <?php print $content['city']; ?>
      <br />
      <?php print t('Telefon'); ?>: <?php print $content['phone']; ?>  E-post: <a href="mailto:<?php print $content['email']; ?>"><?php print $content['email']; ?></a>
    </address>
  </div>
</section>
