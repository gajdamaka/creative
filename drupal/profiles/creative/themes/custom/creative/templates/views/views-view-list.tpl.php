<?php
/**
 * @file
 * Default simple view template to display a list of rows.
 *
 * @var string $list_type_prefix
 * @var string $list_type_suffix
 * @var array $classes_array
 * @var string $title
 * @var array $rows
 * @var \view $view
 */
?>
<?php if (!empty($rows)): ?>
  <?php print $list_type_prefix; ?>
  <?php foreach ($rows as $id => $row): ?>
    <li class="<?php print $classes_array[$id]; ?>">
      <?php print $row; ?>
    </li>
  <?php endforeach; ?>
  <?php print $list_type_suffix; ?>
<?php endif; ?>
