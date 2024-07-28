# Old flow

0. Run and setup pipenv first so you have dependencies necessary for project during development

1. Check your machine CPU type: `uname -m`

1. Go to Makefile and use the right install_ndk

1. Run `make`

- Run `make clean` if you want to reset

3. Export $LEGACY_NDK

`export LEGACY_NDK=$ANDROID_HOME/android-ndk-legacy`

4. Go to buildozer and change to right android.archs

5. Run buildozer

`buildozer android debug`

# Docker (my version)

## Run container

```
docker compose up -d
```

## Run container shell

```
docker exec -it ubuntu_container /bin/bash
```

## My activity log

Install sudo

```
apt update -y
apt install sudo
```

Target Android on Ubuntu 22.04

https://buildozer.readthedocs.io/en/latest/installation.html#targeting-android

# Docker (buildozer version)

## Clone repo

Clone this to local computer

`git clone https://github.com/kivy/buildozer.git .`

## Build

Swing up a linux environment for buildozer

For MacOS, use:

`docker buildx build --platform=linux/amd64 -t kivy/buildozer .`

For others, use:

`docker build --tag=kivy/buildozer .`

## Run container

Run one-time buildozer command:

```
docker run \
  --volume "$HOME/.buildozer":/home/user/.buildozer \
  --volume "$PWD":/home/user/hostcwd \
  kivy/buildozer --version
```

```
docker run \
  --volume "$HOME/.buildozer":/home/user/.buildozer \
  --volume "$PWD":/home/user/hostcwd \
  kivy/buildozer android debug
```

Or for interactive shell:

```
docker run --interactive --tty --rm \
  --volume "$HOME/.buildozer":/home/user/.buildozer \
  --volume "$PWD":/home/user/hostcwd \
  --entrypoint /bin/bash \
  kivy/buildozer
```

# Useful commands

Start pipenv in current shell (not subshell):

`source $(pipenv --venv)/bin/activate`

# Bugs

1. scipy: https://stackoverflow.com/questions/73539112/ndk-version-conflict-in-buildozer-for-kivy-app
   a. https://github.com/mzakharo/android-gfortran/releases/tag/r19c
   b. https://stackoverflow.com/questions/73539112/ndk-version-conflict-in-buildozer-for-kivy-app
   c. https://github.com/kivy/python-for-android/issues/2508
