#!/bin/bash

service mariadb start

cat <<EOF > user.sql
CREATE DATABASE IF NOT EXISTS wordpress;
CREATE USER IF NOT EXISTS '$MYSQL_USER'@'%' IDENTIFIED BY '$MYSQL_PASSWORD';
GRANT ALL PRIVILEGES ON wordpress.* TO '$MYSQL_USER'@'%' WITH GRANT OPTION;
FLUSH PRIVILEGES;
EOF

mysql -u root < user.sql
mysql mariadb stop
mysqld --character-set-server=utf8mb4 --collation-server=utf8mb4_unicode_ci