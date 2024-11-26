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
    vim

RUN apt-get update && apt-get install -y dumb-init

RUN wget https://wordpress.org/latest.tar.gz && \
    tar -xvf latest.tar.gz && \
    mkdir -p /var/www/html/ && \
    mv /wordpress/* /var/www/html/ && \
    chown -R www-data:www-data /var/www/html && \
    rm -r /wordpress latest.tar.gz

COPY ./conf/www.conf /etc/php/7.4/fpm/pool.d/www.conf

COPY ./tools/entrypoint.sh /entrypoint.sh
RUN chmod +x /entrypoint.sh

CMD ["dumb-init", "/entrypoint.sh"]
