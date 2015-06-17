<?php
/**
 * @file
 * The "Heading" variant of "Preview" pane.
 *
 * @var array $content
 *   An array with all data from settings form.
 */
?>
<section role="region" class="preview--heading">

  <div class="media-preview">
    <?php print media_file($content['image']); ?>
  </div>

  <div class="content">
    <div class="row">
      <div class="cell wrapper" role="presentation">
        <?php if (!empty($content['override_title_text'])): ?>
          <h1 role="heading">
            <?php print $content['override_title_text']; ?>
          </h1>
        <?php endif; ?>
        <?php if (!empty($content['link'])): ?>
          <a href="<?php print $content['link']['url']; ?>" role="button" class="button red">
            <?php print $content['link']['title']; ?>
          </a>
        <?php endif; ?>
      </div>
    </div>
  </div>
</section>
