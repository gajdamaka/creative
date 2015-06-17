<?php
/**
 * @file
 * The "Categories" variant of "Terms" pane.
 *
 * @var array $content
 *   An array with all data from settings form.
 */
?>
<?php if (!empty($content['terms'])): ?>
  <div class="block-item">
    <h3 role="heading">
      <?php print t('Kategorier'); ?>
    </h3>
    <div class="content">
      <ul role="list">
        <?php foreach ($content['terms'] as $term): ?>
          <li role="listitem">
            <a href="<?php print term_uri($term); ?>" class="blue-left-arrow">
              <?php print $term->name; ?>
            </a>
          </li>
        <?php endforeach; ?>
      </ul>
    </div>
  </div>
<?php endif; ?>
