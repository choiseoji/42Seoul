FROM debian:bullseye

RUN apt-get update -y && \
    apt-get upgrade -y && \
    apt-get -y install nginx openssl

RUN mkdir -p /etc/nginx/ssl && \
    openssl genpkey -algorithm RSA -out /etc/nginx/ssl/seojchoi.key -pkeyopt rsa_keygen_bits:2048 && \
    openssl req -new -x509 -key /etc/nginx/ssl/seojchoi.key -out /etc/nginx/ssl/seojchoi.crt -days 365 \
    -subj "/C=KR/ST=Seoul/L=Seoul/O=Seojchoi/OU=IT/CN=seojchoi.42.fr/emailAddress=seojchoi@student.42seoul.kr"

EXPOSE 443

COPY ./conf/nginx.conf /etc/nginx/nginx.conf

CMD ["nginx", "-g", "daemon off;"]
