#!/usr/bin/env bash
# ---------------------------------------------------------------------

set -e

BASEDIR=$(dirname "$0")

sudo amixer cset numid=3 1 # Force output to headphone jack.
pulseaudio -D
cd ${BASEDIR}/../build && ./Debug/VoidCinder/VoidCinder
