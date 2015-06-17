<?php
/**
 * @file
 * The "Main" layout for Panels Everywhere.
 *
 * @var array $content
 */
?>
<?php if (!empty($content['header'])): ?>
  <header role="banner" class="clearfix">
    <?php print $content['header']; ?>
  </header>
<?php endif; ?>

<?php if (!empty($content['main'])): ?>
  <main role="main" class="clearfix">
    <div class="container">
      <?php print $content['main']; ?>
    </div>
  </main>
<?php endif; ?>

<?php if (!empty($content['footer'])): ?>
  <footer role="contentinfo" class="clearfix">
    <?php print $content['footer']; ?>
  </footer>
<?php endif; ?>
