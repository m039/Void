#!/usr/bin/env bash
# ---------------------------------------------------------------------

set -e

pushd $(dirname "$0")/..

cd build && ./Debug/VoidCinder/VoidCinder
