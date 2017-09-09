# project name
project(libdsc)

# cmake min version
cmake_minimum_required(VERSION 2.8)

# debug Mode?
OPTION(DEBUG_BUILD
    "Build type: DEBUG" ON)

# default header/include path
set(INCLUDE_DIRS_PATH "${CMAKE_SOURCE_DIR}/include")

# default install paths for libs/apps
set(DEFAULT_LIB_INSTALL_PATH "${CMAKE_SOURCE_DIR}/lib")
set(DEFAULT_APPS_INSTALL_PATH "${CMAKE_SOURCE_DIR}/bin")

# lib names
set(LIB_NAME_STATIC dsc-static)
set(LIB_NAME_SHARED dsc-shared)

# project subdirectories
add_subdirectory(src)
add_subdirectory(apps)
