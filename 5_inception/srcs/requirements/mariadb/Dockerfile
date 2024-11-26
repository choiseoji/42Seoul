FROM debian:bullseye

RUN apt-get update -y && \
    apt-get upgrade -y && \
    apt-get -y install mariadb-server
    # mkdir -p /run/mysqld && \
    # chown -R mysql:mysql /run/mysqld

EXPOSE 3306

COPY ./tools/init.sh /init.sh
COPY ./conf/50-server.cnf /etc/mysql/mariadb.conf.d/50-server.cnf
RUN chmod +x /init.sh
CMD ["/init.sh"]
