# libdsc: Library for "Data-Structures in C"

[![Build Status](https://travis-ci.org/its-izhar/libdsc.svg?branch=master)](https://travis-ci.org/its-izhar/libdsc)

libdsc: A fast and general purpose C library which includes implementations of common data structures.

## Build Procedure

```
  rm -rf lib bin build
  mkdir build && cd build
  cmake -DDEBUG_BUILD=YES -DCMAKE_INSTALL_PREFIX=.. ..
  make
  make install
```
