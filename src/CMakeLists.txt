## Library ##

# CFLAGS
set(CFLAGS "-Wall" "-Werror" "-std=c99")

if(DEBUG_BUILD)
    message("-- BUILD: Debug --")
    add_definitions(-DDEBUG)
    list(APPEND CFLAGS "-g" "-Og")
else()
    message("-- BUILD: Release --")
    list(APPEND CFLAGS "-O2")
endif(DEBUG_BUILD)

add_definitions(${CFLAGS})

# headers
include_directories("${INCLUDE_DIRS_PATH}")

# lib sources
set(LIB_SOURCES utils.c)

# add src subdirectories here
add_subdirectory(list)

# make libs
add_library(${LIB_NAME_STATIC} STATIC ${LIB_SOURCES})
add_library(${LIB_NAME_SHARED} SHARED ${LIB_SOURCES})

# install libs
install(TARGETS
    ${LIB_NAME_STATIC} ${LIB_NAME_SHARED}
    ARCHIVE DESTINATION ${DEFAULT_LIB_INSTALL_PATH}
    LIBRARY DESTINATION ${DEFAULT_LIB_INSTALL_PATH})
