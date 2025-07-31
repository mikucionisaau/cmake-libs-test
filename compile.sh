#!/usr/bin/env bash
set -e

FEATURES="ubsan lsan asan tsan san ssp hardened"
case "$CXX" in
clang*)
  FEATURES="$FEATURES msan"
  ;;
esac

cmake --workflow --preset release
cmake --workflow --preset debug
for feature in $FEATURES ; do
  cmake --workflow --preset "release-${feature}"
  cmake --workflow --preset "debug-${feature}"
done
