# Tests for CMake Libraries

[CMake Libraries](https://github.com/mikucionisaau/cmake-libs) repository contains a set of CMake scripts to download and build libraries. The purpose of this repository is to test them.

The list of supported libraries:
- [sanitizers](sanitizers/CMakeLists.txt) `ubsan`, `lsan`, `asan`.
- [catch2](catch2/CMakeLists.txt) `factorial_catch2` from [Catch2](https://github.com/catchorg/Catch2).
- [doctest](doctest/CMakeLists.txt) `factorial_doctest` from [doctest](https://github.com/doctest/doctest).
- [benchmark](benchmark/CMakeLists.txt) `fastsort_bm`.
- [matplotplusplus_main](matplotplusplus/CMakeLists.txt) `matplotplusplus_main`.
- [armadillo](armadillo/CMakeLists.txt) `armadillo_main`.

## Test
See available CMake workflow presets:
```shell
cmake --workflow --list-presets
```
Run the workflow for release:
```shell
cmake --workflow --preset release
```
Run the workflow for debug:
```shell
cmake --workflow --preset debug
```

Cleanup:
```shell
rm -Rf build build-*
rm -Rf cmake-build-*
```
