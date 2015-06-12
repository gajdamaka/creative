# Creative site

## Requirements

- PHP 5.4
- Bash 3.x
- Drush 6.x
- Composer 1.x

## Installation

### Project-wide installation

```
git clone ssh://git@github.com:gajdamaka/creative.git && cd unga
```

```
composer install
```

```
./bin/drupal-builder --site-name="Creative site"
```

### System-wide installation

```
composer global require drupal/drupal-builder:dev-master
```

```
sudo ln -s ~/.composer/vendor/bin/drupal-builder /usr/bin/
```

```
drupal-builder --site-name="Creative site" --git="ssh://git@github.com:gajdamaka/creative.git"
```
