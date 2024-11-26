#!/bin/sh

if [ ! -f /usr/local/bin/wp ]; then
    # WP-CLI 설치
    curl -O https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar
    chmod +x wp-cli.phar
    mv wp-cli.phar /usr/local/bin/wp
fi

cd /var/www/html

# WordPress 다운로드 및 초기화
if [ ! -f wp-config.php ]; then
    echo "[INFO] Initializing WordPress setup..."
    rm -rf *

    wp core download --allow-root

    wp config create \
        --skip-check \
        --dbname=${WP_DB_NAME} \
        --dbuser=${MYSQL_USER} \
        --dbpass=${MYSQL_ROOT_PASSWORD} \
        --dbhost=${WP_DB_HOST} \
        --allow-root

    wp core install \
        --url=${DOMAIN_NAME} \
        --title=${WP_TITLE} \
        --admin_user=${WP_ADMIN_NAME} \
        --admin_password=${WP_ADMIN_PASSWORD} \
        --admin_email=${WP_ADMIN_EMAIL} \
        --skip-email \
        --allow-root
else
    echo "[INFO] WordPress already initialized. Skipping setup."
fi

# 유저 생성 (존재 여부 확인 후 생성)
if ! wp user get ${WP_ROOT_NAME} --allow-root > /dev/null 2>&1; then
    echo "[INFO] Creating new user '${WP_ROOT_NAME}'..."
    wp user create ${WP_ROOT_NAME} ${WP_ROOT_EMAIL} --user_pass=${WP_ROOT_PASSWORD} --role=author --allow-root
else
    echo "[INFO] User '${WP_ROOT_NAME}' already exists. Skipping user creation."
fi

# 퍼미션 설정
chmod -R 777 /var/www

# PHP-FPM 실행
mkdir -p /run/php
php-fpm7.4 -F
