<?php
/**
 * @file
 * The "Header" layout for mini-pane.
 *
 * @var array $content
 */
?>
<div class="wrapper">
  <?php if (!empty($content['title'])): ?>
    <?php print $content['title']; ?>
  <?php endif; ?>

  <?php if (!empty($content['address'])): ?>
    <?php print $content['address']; ?>
  <?php endif; ?>

  <span class="mobile-menu" hidden data-toggle="collapse" data-target="#bs-example-navbar-collapse-1"></span>

  <div class="mobile-menu-wrapper collapse clearfix"  id="bs-example-navbar-collapse-1">
    <?php if (!empty($content['menu'])): ?>
      <nav role="navigation" class="container">
        <?php print $content['menu']; ?>
      </nav>
    <?php endif; ?>
  </div>
</div>
