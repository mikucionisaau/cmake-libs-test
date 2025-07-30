#!/usr/bin/env bash
set -e

FEATURES="ubsan lsan asan tsan san ssp hardened"
case "$CXX" in
clang*)
  FEATURES="$FEATURES msan"
  ;;
esac

cmake --workflow release
cmake --workflow debug
for feature in $FEATURES ; do
  cmake --workflow "release-${feature}"
  cmake --workflow "debug-${feature}"
done
