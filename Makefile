# https://github.com/kivy/python-for-android/issues/2508

# Those android NDK/SDK variables can be override when running the file
ANDROID_NDK_VERSION ?= 25b
ANDROID_NDK_VERSION_LEGACY ?= 21e
ANDROID_SDK_TOOLS_VERSION ?= 6514223
ANDROID_SDK_BUILD_TOOLS_VERSION ?= 29.0.3
ANDROID_HOME ?= $(HOME)/.android
ANDROID_API_LEVEL ?= 27

# per OS dictionary-like
UNAME_S := $(shell uname -s)
TARGET_OS_Linux = linux
TARGET_OS_ALIAS_Linux = $(TARGET_OS_Linux)
TARGET_OS_Darwin = darwin
TARGET_OS_ALIAS_Darwin = mac
TARGET_OS = $(TARGET_OS_$(UNAME_S))
TARGET_OS_ALIAS = $(TARGET_OS_ALIAS_$(UNAME_S))

ANDROID_SDK_HOME=$(ANDROID_HOME)/android-sdk
ANDROID_SDK_TOOLS_ARCHIVE=commandlinetools-$(TARGET_OS_ALIAS)-$(ANDROID_SDK_TOOLS_VERSION)_latest.zip
ANDROID_SDK_TOOLS_DL_URL=https://dl.google.com/android/repository/$(ANDROID_SDK_TOOLS_ARCHIVE)

ANDROID_NDK_HOME=$(ANDROID_HOME)/android-ndk
ANDROID_NDK_FOLDER=$(ANDROID_HOME)/android-ndk-r$(ANDROID_NDK_VERSION)
ANDROID_NDK_ARCHIVE=android-ndk-r$(ANDROID_NDK_VERSION)-$(TARGET_OS).zip

ANDROID_NDK_HOME_LEGACY=$(ANDROID_HOME)/android-ndk-legacy
ANDROID_NDK_FOLDER_LEGACY=$(ANDROID_HOME)/android-ndk-r$(ANDROID_NDK_VERSION_LEGACY)
ANDROID_NDK_ARCHIVE_LEGACY=android-ndk-r$(ANDROID_NDK_VERSION_LEGACY)-$(TARGET_OS)-x86_64.zip

ANDROID_NDK_GFORTRAN_ARCHIVE_ARM64=gcc-arm64-linux-x86_64.tar.bz2
ANDROID_NDK_GFORTRAN_ARCHIVE_ARM=gcc-arm-linux-x86_64.tar.bz2

ANDROID_NDK_DL_URL=https://dl.google.com/android/repository/$(ANDROID_NDK_ARCHIVE)
ANDROID_NDK_DL_URL_LEGACY=https://dl.google.com/android/repository/$(ANDROID_NDK_ARCHIVE_LEGACY)

$(info Target install OS is          : $(target_os))
$(info Android SDK home is           : $(ANDROID_SDK_HOME))
$(info Android NDK home is           : $(ANDROID_NDK_HOME))
$(info Android NDK Legacy  home is   : $(ANDROID_NDK_HOME_LEGACY))
$(info Android SDK download url is   : $(ANDROID_SDK_TOOLS_DL_URL))
$(info Android NDK download url is   : $(ANDROID_NDK_DL_URL))
$(info Android API level is          : $(ANDROID_API_LEVEL))
$(info Android NDK version is        : $(ANDROID_NDK_VERSION))
$(info Android NDK Legacy version is : $(ANDROID_NDK_VERSION_LEGACY))
$(info JAVA_HOME is                  : $(JAVA_HOME))

all: install_ndk

install_ndk: download_android_ndk_legacy download_android_ndk_gfortran extract_android_ndk_legacy extract_android_ndk_gfortran export_env

download_android_ndk_legacy:
	curl --location --progress-bar --continue-at - \
	$(ANDROID_NDK_DL_URL_LEGACY) --output $(ANDROID_NDK_ARCHIVE_LEGACY)

download_android_ndk_gfortran:
	curl --location --progress-bar --continue-at - \
	https://github.com/mzakharo/android-gfortran/releases/download/r$(ANDROID_NDK_VERSION_LEGACY)/$(ANDROID_NDK_GFORTRAN_ARCHIVE_ARM64) --output $(ANDROID_NDK_GFORTRAN_ARCHIVE_ARM64)
	curl --location --progress-bar --continue-at - \
	https://github.com/mzakharo/android-gfortran/releases/download/r$(ANDROID_NDK_VERSION_LEGACY)/$(ANDROID_NDK_GFORTRAN_ARCHIVE_ARM)  --output $(ANDROID_NDK_GFORTRAN_ARCHIVE_ARM)

extract_android_ndk_legacy:
	@echo "Create android-ndk-r21e folder"
	mkdir -p $(ANDROID_NDK_FOLDER_LEGACY)
	@echo "Unzip returns folder android-ndk-r21e which replaces the empty folder we just created previously"
	unzip -q $(ANDROID_NDK_ARCHIVE_LEGACY) -d $(ANDROID_HOME)
	@echo "Move android-ndk-r21e to android-ndk-legacy"
	mv $(ANDROID_NDK_FOLDER_LEGACY) $(ANDROID_NDK_HOME_LEGACY)
	@echo "Create android-ndk-r21e folder"
	rm -f $(ANDROID_NDK_ARCHIVE_LEGACY)

extract_android_ndk_gfortran:
	@echo "Remove old toolchains"
	rm -rf $(ANDROID_NDK_HOME_LEGACY)/toolchains/aarch64-linux-android-4.9/prebuilt/linux-x86_64/ 
	@echo "Create new toolchains placeholder folder"
	mkdir $(ANDROID_NDK_HOME_LEGACY)/toolchains/aarch64-linux-android-4.9/prebuilt/linux-x86_64/ 
	@echo "Unzip into our placeholder folder"
	tar -xf $(ANDROID_NDK_GFORTRAN_ARCHIVE_ARM64) -C $(ANDROID_NDK_HOME_LEGACY)/toolchains/aarch64-linux-android-4.9/prebuilt/linux-x86_64/ --strip-components 1 
	@echo "Remove the zip file"
	rm -f $(ANDROID_NDK_GFORTRAN_ARCHIVE_ARM64) 
	@echo "Remove old toolchains"
	rm -rf $(ANDROID_NDK_HOME_LEGACY)/toolchains/arm-linux-androideabi-4.9/prebuilt/linux-x86_64/ 
	@echo "Create new toolchains placeholder folder"
	mkdir $(ANDROID_NDK_HOME_LEGACY)/toolchains/arm-linux-androideabi-4.9/prebuilt/linux-x86_64/ 
	@echo "Unzip into our placeholder folder"
	tar -xf $(ANDROID_NDK_GFORTRAN_ARCHIVE_ARM) -C $(ANDROID_NDK_HOME_LEGACY)/toolchains/arm-linux-androideabi-4.9/prebuilt/linux-x86_64/ --strip-components 1 
	@echo "Remove the zip file"
	rm -f $(ANDROID_NDK_GFORTRAN_ARCHIVE_ARM) 

export_env:
	export LEGACY_NDK=$(ANDROID_NDK_HOME_LEGACY)

.PHONY: clean

clean:
	rm -f $(ANDROID_NDK_ARCHIVE_LEGACY)
	rm -f $(ANDROID_NDK_GFORTRAN_ARCHIVE_ARM64)
	rm -f $(ANDROID_NDK_GFORTRAN_ARCHIVE_ARM)
	rm -rf $(ANDROID_NDK_HOME_LEGACY)
	rm -rf $(ANDROID_NDK_HOME_LEGACY)/toolchains/aarch64-linux-android-4.9/prebuilt/linux-x86_64/
	rm -rf $(ANDROID_NDK_HOME_LEGACY)/toolchains/arm-linux-androideabi-4.9/prebuilt/linux-x86_64/
	unset LEGACY_NDK
