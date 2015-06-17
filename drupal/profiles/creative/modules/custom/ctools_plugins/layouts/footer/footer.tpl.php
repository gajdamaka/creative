<?php
/**
 * @file
 * The "Footer" layout for mini-pane.
 *
 * @var array $content
 */
?>
<div class="wrapper row">
  <div class="cell">
    <?php foreach ($content as $region => $data): ?>
      <?php if (!empty($data)): ?>
        <?php print $data; ?>
      <?php endif; ?>
    <?php endforeach; ?>
  </div>
</div>
