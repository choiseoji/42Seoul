# 베이스 이미지 Debian Bullseye
FROM debian:bullseye

# nginx 설치 및 기본 패키지 업데이트
RUN apt-get update -y && \
    apt-get upgrade -y && \
    apt-get -y install nginx openssl

# ssl
RUN mkdir -p /etc/nginx/ssl && \
    openssl genpkey -algorithm RSA -out /etc/nginx/ssl/seojchoi.key -pkeyopt rsa_keygen_bits:2048 && \
    openssl req -new -x509 -key /etc/nginx/ssl/seojchoi.key -out /etc/nginx/ssl/seojchoi.crt -days 365 \
    -subj "/C=KR/ST=Seoul/L=Seoul/O=Seojchoi/OU=IT/CN=seojchoi.42.fr/emailAddress=seojchoi@student.42seoul.kr"

# nginx가 사용하는 443 포트를 개방
EXPOSE 443

# nginx config 파일 복사
COPY ./conf/nginx.conf /etc/nginx/nginx.conf

# nginx 서버 실행
# 포그라운드 - Docker는 기본적으로 컨테이너 내부의 프로세스가 종료되면 컨테이너 자체를 종료 처리하기 때문에 해당 설정이 필요하다.
CMD ["nginx", "-g", "daemon off;"]
