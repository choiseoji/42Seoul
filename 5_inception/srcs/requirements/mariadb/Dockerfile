# 베이스 이미지 Debian Bullseye
FROM debian:bullseye

# MariaDB 설치 및 기본 패키지 업데이트
# MaridDB는 기본적으로 /run/mysqld/mysqld.sock 경로에 소켓 파일을 생성하고 이를 통해 클라이언트와 서버 간의 통신이 이루어진다.
RUN apt-get update -y && \
    apt-get upgrade -y && \
    apt-get -y install mariadb-server &&\
    mkdir -p /run/mysqld && \
    chown -R mysql:mysql /run/mysqld

# ENV MYSQL_ROOT_PASSWORD=${MYSQL_ROOT_PASSWORD}
# ENV MYSQL_USER=${MYSQL_USER}
# ENV MYSQL_PASSWORD=${MYSQL_PASSWORD}
# COPY ./tools/init.sh /docker-entrypoint-initdb.d/init.sh

# # 실행 권한 추가
# RUN chmod +x /docker-entrypoint-initdb.d/init.sh

# MariaDB가 사용하는 3306 포트를 개방
EXPOSE 3306

# MariaDB 서버 실행
CMD ["mysqld", "--character-set-server=utf8mb4", "--collation-server=utf8mb4_unicode_ci"]
