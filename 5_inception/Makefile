.PHONY: all down

DOCKER_COMPOSE_PATH = ./srcs/docker-compose.yml
DATA_PATH = /Users/seoji/data

all:
	docker compose -f ${DOCKER_COMPOSE_PATH} up -d --build

down:
	docker compose -f ${DOCKER_COMPOSE_PATH} down

re: clean all

clean: down
	docker volume remove srcs_mariadb_data
	docker volume remove srcs_wordpress_data
