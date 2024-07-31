# Use Dockerfile

Run `docker build --no-cache -t buffercapacity4-docker .` to build image

Run `docker run --name buffercapacity4 -it buffercapacity4-docker /bin/bash` to create new container shell

- Run `docker start <container_name>` to start existing container
- Run `docker exec -it <container_name> /bin/bash` to run existing container shell
- Container name is buffercapacity4

Run `source $(pipenv --venv)/bin/activate` to activate pipenv

Run `make` to install toolchains for gfortran that supports scipy

Run `buildozer android debug`

# After having apk file

Run `docker cp buffercapacity4:/root/BufferCapacity4/bin/homescreen-0.1-arm64-v8a_armeabi-v7a-debug.apk /Users/tonnu.hongan999/Documents/apk` to copy file from container to local machine

Boot up a virtual device in Android Studio

Run `adb devices` to see list of devices

Run `adb -s <emulator_id> install path/to/myapp.apk` to install apk on device emulator

Voila!
