#!/bin/bash

service mariadb start

cat <<EOF > /user.sql
CREATE DATABASE IF NOT EXISTS wordpress;
CREATE USER IF NOT EXISTS '$MYSQL_USER'@'%' IDENTIFIED BY '$MYSQL_PASSWORD';
GRANT ALL PRIVILEGES ON *.* TO '$MYSQL_USER'@'%' WITH GRANT OPTION;
FLUSH PRIVILEGES;
EOF

mysql -u root < /user.sql
rm -rf /user.sql

service mariadb stop
exec mysqld_safe --user=$MYSQL_USER
