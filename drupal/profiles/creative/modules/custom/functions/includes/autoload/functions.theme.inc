<?php
/**
 * @file
 * Helper functions for theming mechanism.
 */

/**
 * Get the HTML markup of Drupal menu.
 *
 * @param string $menu_name
 *   The name of menu.
 *
 * @throws \Exception
 *   When theme is not initialized.
 *
 * @return string
 *   Menu HTML markup.
 */
function menu($menu_name = '') {
  $links = menu_not_empty($menu_name);

  return empty($links) ? '' : render($links);
}

/**
 * Get ready for render menu array.
 *
 * @param string $menu_name
 *   The name of menu.
 *
 * @return array
 *   Drupal render array.
 */
function menu_not_empty($menu_name = '') {
  static $links = array(), $latest = array();

  if (empty($menu_name) && !empty($latest)) {
    return $latest;
  }
  else {
    if (empty($links[$menu_name])) {
      $links[$menu_name] = $latest = menu_tree($menu_name);
    }

    return $links[$menu_name];
  }
}

/**
 * Render an image by file ID.
 *
 * @see theme_image()
 * @see theme_image_style()
 *
 * @param string|int|array $file
 *   File ID.
 * @param string $style_name
 *   Image style name.
 *
 * @throws \Exception
 *   When theme is not initialized.
 *
 * @return string
 *   Rendered image.
 */
function media_file($file, $style_name = '') {
  if (is_array($file)) {
    $file = (object) $file;
  }
  else {
    $file = file_load($file);
  }

  if (!empty($file)) {
    switch ($file->type) {
      case 'image':
        $dimensions = array(
          'width' => '',
          'height' => '',
        );

        $attributes = array(
          'role' => 'img',
        );

        if (!empty($file->image_dimensions)) {
          $dimensions = $file->image_dimensions;
        }

        $attributes += $dimensions;

        if (!empty($style_name)) {
          $image_styles = image_style_options();

          if (isset($image_styles[$style_name])) {
            return theme('image_style', $dimensions + array(
              'path' => $file->uri,
              'style_name' => $style_name,
              'attributes' => $attributes,
            ));
          }
        }

        return theme('image', array('path' => $file->uri, 'attributes' => $attributes));

      case 'video':
        if ('image' == $style_name) {
          $wrapper = file_stream_wrapper_get_instance_by_uri($file->uri);
          $thumb = sprintf('%s/images/no-video-thumb.jpg', $GLOBALS['theme_path']);

          if (is_object($wrapper) && method_exists($wrapper, 'getOriginalThumbnailPath')) {
            $thumb = $wrapper->getOriginalThumbnailPath();
          }

          $file = file_uri_to_object($thumb);
          $file->type = $style_name;

          return call_user_func(__FUNCTION__, (array) $file);
        }

        $file = file_view_file($file, $style_name);
        return drupal_render($file);
    }
  }

  return '';
}
