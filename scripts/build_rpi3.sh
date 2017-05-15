#!/bin/bash
# ---------------------------------------------------------------------
#
#           This script is tested on Raspbian Jessie.
#    You need to run it only once to build all necessary stuff.
#
# ---------------------------------------------------------------------
#
# Hindsight notes:
#
# - Don't use Clang: there is a bug and audio won't play.
# - Sometimes Raspberry Pi hangs when a compilation with several jobs
#   are enabled, even with -j2 option.
#
# References:
#
# - https://libcinder.org/docs/guides/linux-notes/rpi3.html
# - https://libcinder.org/docs/guides/boost/index.html
#

set -e

pushd $(dirname "$0")/..

# 0. Preliminaries.

sudo apt-get install 	
				cmake\
				libxcursor-dev \
				libgles2-mesa-dev \
				zlib1g-dev \
				libfontconfig1-dev \
				libmpg123-dev \
				libsndfile1 \
				libsndfile1-dev \
				libpulse-dev \
				libasound2-dev \
				libcurl4-gnutls-dev \
				libgstreamer1.0-dev \
				libgstreamer-plugins-bad1.0-dev \
				libgstreamer-plugins-base1.0-dev \
				gstreamer1.0-libav \
				gstreamer1.0-alsa \
				gstreamer1.0-pulseaudio \
				gstreamer1.0-plugins-bad

# 1. Build Cinder.

pushd third-party/Cinder
mkdir -p build && cd build && cmake .. -DCINDER_TARGET_GL=es2-rpi && make
popd

# 2. Build void-boost.

pushd third-party/void-boost
./bootstrap.sh
./b2 define=_GLIBCXX_USE_CXX11_ABI=0 stage
cp stage/lib/libboost_*.a ../../precompiled/linux/
popd

# 3. Build gainput.

pushd third-party/gainput/lib
mkdir -p build && cd build && cmake .. -DGAINPUT_BUILD_STATIC=true && make
cp libgainputstatic.a ../../../../precompiled/linux/
popd

# 4. Build the project.

mkdir -p build && cd build && cmake .. -DCINDER_TARGET_GL=es2-rpi && make
ln -s ../void-app/assets/ assets

popd