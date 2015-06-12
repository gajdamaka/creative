<?php
/**
 * @file
 * Main panel pane template.
 *
 * @var array $content
 * @var string $title
 * @var string $title_heading
 * @var \stdClass $pane
 */
$attributes = array();
?>
<?php foreach (array('class', 'id') as $attribute): ?>
  <?php $prop = 'css_' . $attribute; ?>
  <?php if (!empty($pane->css[$prop])): ?>
    <?php $attributes[$attribute] = $pane->css[$prop]; ?>
  <?php endif; ?>
<?php endforeach; ?>

<?php if (!empty($attributes)): ?>
  <div<?php print drupal_attributes($attributes); ?>>
<?php endif; ?>

  <?php if (!empty($title)): ?>
    <<?php print $title_heading ?> class="pane-title">
      <?php print $title; ?>
    </<?php print $title_heading ?>>
  <?php endif; ?>

  <?php print render($content); ?>

<?php if (!empty($pane->css)): ?>
  </div>
<?php endif; ?>
