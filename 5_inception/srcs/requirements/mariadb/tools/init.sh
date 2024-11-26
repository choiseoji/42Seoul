#!/bin/bash

if [ ! -d "/var/lib/mysql/mysql" ]; then
    echo "[INFO] Initializing MariaDB data directory."
    mkdir -p /run/mysqld
    chown -R mysql:mysql /run/mysqld
    mariadb-install-db --user=mysql --datadir=/var/lib/mysql --basedir=/usr --rpm

    echo "[INFO] Running MariaDB bootstrap to set up database and user."
    mysqld --bootstrap --user=mysql <<EOF
-- 데이터베이스 생성
CREATE DATABASE IF NOT EXISTS $WP_DB_NAME;

-- 유저 생성 및 암호화 방식 확인
CREATE USER IF NOT EXISTS '$MYSQL_USER'@'%' IDENTIFIED BY '$MYSQL_PASSWORD';

-- 권한 부여
GRANT ALL PRIVILEGES ON $WP_DB_NAME.* TO '$MYSQL_USER'@'%';
FLUSH PRIVILEGES;
EOF
else
    echo "[INFO] MariaDB data directory already exists, skipping initialization."
    chown -R mysql:mysql /var/lib/mysql
fi

echo "[INFO] Starting MariaDB service."
exec mysqld_safe --user=mysql
