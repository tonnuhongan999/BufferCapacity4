# Use Dockerfile

Run `docker build -t buffercapacity4-docker .` to build image

Run `docker run --name buffercapacity4 -it buffercapacity4-docker /bin/bash` to create new container shell

- Run `docker exec -it <container_name> /bin/bash` to run existing container shell
- Container name is buffercapacity4

Run `source $(pipenv --venv)/bin/activate` to activate pipenv
