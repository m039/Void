#!/usr/bin/env bash
# ---------------------------------------------------------------------

set -e

pushd $(dirname "$0")/..

sudo amixer cset numid=3 1 # Force output to a headphone jack.
pulseaudio -D
cd build && ./Debug/VoidCinder/VoidCinder
