# Creative site

## Requirements

- PHP 5.4
- Bash 3.x
- Drush 6.x
- Composer 1.x

## Installation

### Project-wide installation

```
git clone git@github.com:gajdamaka/creative.git && cd creative
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
drupal-builder --site-name="Creative site" --git="git@github.com:gajdamaka/creative.git"
```
