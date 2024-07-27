# Guide

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

# Useful commands

Start pipenv in current shell (not subshell):

`source $(pipenv --venv)/bin/activate`

# Bugs

1. scipy: https://stackoverflow.com/questions/73539112/ndk-version-conflict-in-buildozer-for-kivy-app
   a. https://github.com/mzakharo/android-gfortran/releases/tag/r19c
   b. https://stackoverflow.com/questions/73539112/ndk-version-conflict-in-buildozer-for-kivy-app
   c. https://github.com/kivy/python-for-android/issues/2508
