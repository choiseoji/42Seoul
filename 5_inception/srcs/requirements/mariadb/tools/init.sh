# #!/bin/bash

# if [ ! -d "/var/lib/mysql/mysql" ]; then
    # mkdir -p /run/mysqld
    # chown -R mysql:mysql /run/mysqld

    # service mariadb start
mysqld_safe

cat <<EOF > user.sql
CREATE DATABASE IF NOT EXISTS wordpress;
CREATE USER IF NOT EXISTS '$MYSQL_USER'@'%' IDENTIFIED BY '$MYSQL_PASSWORD';
GRANT ALL PRIVILEGES ON wordpress.* TO '$MYSQL_USER'@'%' WITH GRANT OPTION;
FLUSH PRIVILEGES;
EOF

mysql -u root < user.sql
rm -rf user.sql

# else
#     chown -R mysql:mysql /var/lib/mysql
# fi

mysqld