.PHONY: all down

DOCKER_COMPOSE_PATH = ./srcs/docker-compose.yml

all:
	docker compose -f ${DOCKER_COMPOSE_PATH} up -d --build

down:
	docker compose -f ${DOCKER_COMPOSE_PATH} down

re: clean all

clean: down
	rm -rf /home/seojchoi/data/mysql/*
	rm -rf /home/seojchoi/data/wordpress/*
	docker volume remove srcs_maridadb_data
	docker volume remove srcs_wordpress_data
