FROM debian:bullseye

RUN apt-get update -y && \
    apt-get upgrade -y && \
    apt-get -y install \
    php7.4 \
    php-fpm \
    php-cli \
    wget \
    curl \
    php-mysql \
    php-mbstring \
    php-xml \
    sendmail \
    vim

RUN wget https://wordpress.org/latest.tar.gz && \
    tar -xvf latest.tar.gz && \
    mkdir -p /var/www/html/ && \
    mv /wordpress/* /var/www/html/ && \
    chown -R www-data:www-data /var/www/html && \ 
    rm -r /wordpress latest.tar.gz

COPY ./tools/wp-config.php /var/www/html/wp-config.php
COPY ./conf/www.conf /etc/php/7.4/fpm/pool.d/www.conf

RUN mkdir -p /run/php && \
    chown -R www-data:www-data /run/php

EXPOSE 9000

CMD ["php-fpm7.4", "-F"]