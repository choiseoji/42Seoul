FROM debian:bullseye

RUN apt-get update -y && \
    apt-get upgrade -y && \
    apt-get -y install mariadb-server

RUN apt-get update && apt-get install -y dumb-init

EXPOSE 3306

COPY ./tools/init.sh /init.sh
COPY ./conf/50-server.cnf /etc/mysql/mariadb.conf.d/50-server.cnf
RUN chmod +x /init.sh
CMD ["dumb-init", "/init.sh"]
