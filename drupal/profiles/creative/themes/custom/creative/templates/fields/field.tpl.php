<?php
/**
 * @file
 * Default template implementation to display the value of a field.
 *
 * @var bool $label_hidden
 * @var string $field_name_css
 * @var array $items
 * @var string $label
 */
?>
<?php foreach ($items as $delta => $item): ?>
  <?php if (!$label_hidden): ?>
    <div class="<?php print $field_name_css; ?>">
      <label><?php print $label; ?></label>
  <?php endif; ?>

  <?php print render($item); ?>

  <?php if (!$label_hidden): ?>
    </div>
  <?php endif; ?>
<?php endforeach; ?>
