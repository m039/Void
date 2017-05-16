#!/bin/bash
# ---------------------------------------------------------------------
#
#           This script is tested on Ubuntu 16.04 LTS.
#         You need to run it only once to build all stuff.
#
# ---------------------------------------------------------------------
#
# References:
#
# - https://libcinder.org/docs/guides/linux-notes/ubuntu.html
# - https://libcinder.org/docs/guides/boost/index.html
#

set -e

pushd $(dirname "$0")/..

# 0. Preliminaries.

sudo apt-get install \
     cmake\
     libxcursor-dev \
     libxrandr-dev \
     libxinerama-dev \
     libxi-dev \
     libgl1-mesa-dev \
     libglu1-mesa-dev \
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
     gstreamer1.0-plugins-bad \
     python-dev

# 1. Build Cinder.

pushd third-party/Cinder
mkdir -p build && cd build && cmake .. && make -j 8
popd

# 2. Build void-boost.

pushd third-party/void-boost
./bootstrap.sh
./b2 define=_GLIBCXX_USE_CXX11_ABI=0 -j 8 stage
cp stage/lib/libboost_*.a ../../precompiled/linux/
popd

# 3. Build gainput.

pushd third-party/gainput/lib
mkdir -p build && cd build && cmake .. -DGAINPUT_BUILD_STATIC=true && make
cp libgainputstatic.a ../../../../precompiled/linux/
popd

# 4. Build the project.

mkdir -p build && cd build && cmake .. && make -j 8
ln -s ../void-app/assets/ assets

popd
