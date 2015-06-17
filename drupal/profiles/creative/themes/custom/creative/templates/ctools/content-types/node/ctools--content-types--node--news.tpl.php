<?php
/**
 * @file
 * The "News" variant of "Article" pane.
 *
 * @var array $content
 *   An array with all data from settings form.
 */
?>
<?php if (!empty($content['node'])): ?>
  <section role="region" class="wrapper clearfix content-wrapper article-type-<?php print $content['theme'] ?>">
    <h1 role="heading">
      <?php print $content['node']['title']; ?>
    </h1>

    <article role="article">
      <?php print media_file($content['node']['presentation']); ?>

      <div class="share-block">
        <time datetime="<?php print date('c', $content['node']['created']); ?>" pubdate>
          <?php print format_date($content['node']['created'], 'custom', 'Y-m-d'); ?>
        </time>
        |
        <span class="share">
          <?php print t('Dela'); ?>
          <span hidden>
            <?php foreach ($content['share_links'] as $network => $link): ?>
              <a href="<?php print $link; ?>">
                <?php print ucfirst($network); ?>
              </a>
            <?php endforeach; ?>
          </span>
        </span>
        |
        <span class="print">
          <?php print t('Skriv ut'); ?>
        </span>
      </div>

      <?php print $content['node']['body']['value']; ?>
    </article>

    <aside role="complementary">
      <?php if (!empty($content['archive'])): ?>
        <div class="block-item archive">
          <h3 role="heading">
            <?php print t('Arkiv'); ?>
          </h3>

          <div class="content">
            <ul role="list">
              <?php foreach ($content['archive'] as $node): ?>
                <li role="listitem">
                  <a href="<?php print $node['url']; ?>" class="blue-left-arrow">
                    <?php print $node['title']; ?>
                  </a>
                </li>
              <?php endforeach; ?>
            </ul>
          </div>
        </div>
      <?php endif; ?>

      <?php if (!empty($content['node']['category'])): ?>
        <div class="block-item categories">
          <h3 role="heading">
            <?php print t('Kategorier'); ?>
          </h3>

          <div class="content">
            <ul role="list">
              <?php foreach ($content['node']['category'] as $category): ?>
                <li role="listitem">
                  <a href="<?php print term_uri($category); ?>" class="blue-left-arrow">
                    <?php print $category->name; ?>
                  </a>
                </li>
              <?php endforeach; ?>
            </ul>
          </div>
        </div>
      <?php endif; ?>

      <?php if (!empty($content['node']['related_pages'])): ?>
        <div class="block-item related-pages">
          <h3 role="heading">
            <?php print t('Relaterade sidor'); ?>
          </h3>

          <div class="content">
            <ul role="list">
              <?php foreach ($content['node']['related_pages'] as $item): ?>
                <li role="listitem">
                  <a href="<?php print $item['related_node']['url']; ?>">
                    <?php if ($item['show_image']): ?>
                      <?php print media_file($item['related_node']['presentation'], 'image'); ?>
                    <?php endif; ?>
                    <span class="title blue-left-arrow">
                      <?php print $item['related_node']['title']; ?>
                    </span>
                  </a>
                </li>
              <?php endforeach; ?>
            </ul>
          </div>
        </div>
      <?php endif; ?>
    </aside>
  </section>
<?php endif; ?>
