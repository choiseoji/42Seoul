#!/bin/bash

service mariadb start

cat <<EOF > /user.sql

-- 데이터베이스 생성
CREATE DATABASE IF NOT EXISTS '$WP_DB_NAME';

-- 유저 생성 및 암호화 방식 확인
CREATE USER IF NOT EXISTS '$MYSQL_USER'@'%' IDENTIFIED BY '$MYSQL_PASSWORD';

-- 권한 부여
GRANT ALL PRIVILEGES ON *.* TO '$MYSQL_USER'@'%' WITH GRANT OPTION;
FLUSH PRIVILEGES;
EOF

mysql -u root < /user.sql
rm -rf /user.sql

service mariadb stop
exec mysqld_safe --user=$MYSQL_USER
