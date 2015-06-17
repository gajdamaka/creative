<?php
/**
 * @file
 * The "Article" variant of "Article" pane.
 *
 * @var array $content
 *   An array with all data from settings form.
 */
?>
<?php if (!empty($content['node'])): ?>
  <section role="region" class="wrapper clearfix content-wrapper">
    <aside role="complementary" class="mobile-navigation" hidden>
      <?php if (menu_not_empty('menu-site-menu')): ?>
        <nav role="navigation" class="navigation">
          <?php print menu(); ?>
        </nav>
      <?php endif; ?>
    </aside>

    <article role="article">
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

    <aside role="complementary" class="right-sidebar">
      <?php if (menu_not_empty('menu-site-menu')): ?>
        <nav role="navigation" class="navigation">
          <?php print menu(); ?>
        </nav>
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

      <?php if (!empty($content['node']['related_information'])): ?>
        <div class="block-item related-information">
          <h3 role="heading">
            <?php print t('Related information'); ?>
          </h3>

          <div class="content">
            <ul role="list">
              <?php foreach ($content['node']['related_information'] as $item): ?>
                <li role="listitem">
                  <a class="title blue-left-arrow" href="<?php print $item['url']; ?>">
                      <?php print $item['title']; ?>
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
