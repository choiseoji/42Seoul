#!/bin/bash

# MariaDB 서비스 시작
service mariadb start

# 데이터베이스 및 사용자 생성
mysql -u root -p "$MYSQL_ROOT_PASSWORD" <<EOF
DELETE FROM mysql.user WHERE user='';
CREATE DATABASE IF NOT EXISTS wordpress;
CREATE USER IF NOT EXISTS '$MYSQL_USER'@'%' IDENTIFIED BY '$MYSQL_PASSWORD';
GRANT ALL PRIVILEGES ON wordpress.* TO '$MYSQL_USER'@'%' WITH GRANT OPTION;
FLUSH PRIVILEGES;
EOF

mysql -uroot -p"$MYSQL_ROOT_PASSWORD" <<EOF
ALTER USER 'root'@'localhost' IDENTIFIED BY '$MYSQL_ROOT_PASSWORD';
EOF
