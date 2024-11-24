#!/bin/sh

if [ ! -f /usr/local/bin/wp ]; then
	curl -O https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar
	chmod +x wp-cli.phar
	mv wp-cli.phar /usr/local/bin/wp

	cd /var/www/html

	rm -rf *

	wp core download --allow-root

	wp config create \
		--skip-check \
		--dbname=${WORDPRESS_DB_NAME} \
		--dbuser=${MYSQL_USER} \
		--dbpass=${MYSQL_ROOT_PASSWORD} \
		--dbhost=${WORDPRESS_DB_HOST} \
		--allow-root

	wp core install \
		--url=${DOMAIN_NAME} \
		--title=${WP_TITLE} \
		--admin_user=${WP_ROOT_NAME} \
		--admin_password=${WP_ROOT_PASSWORD} \
		--admin_email=${WP_ROOT_EMAIL} \
		--skip-email \
		--allow-root

	wp user create ${WORDPRESS_DB_USER} --skip-email --user_pass=${WORDPRESS_DB_PASSWORD} --role=author --allow-root
fi

chmod -R 777 /var/www

mkdir -p /run/php

php-fpm7.4 -F
