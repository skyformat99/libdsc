## APPS ## 

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

# app targets
set(APP_TARGETS "")

# add apps subdirectories here
add_subdirectory(list)

# make apps
set(APP_SRC "")
set(TARGET_APPS "")
foreach(APP_SRC IN LISTS APP_TARGETS)
    # extract app-name
    get_filename_component(APP_NAME ${APP_SRC} NAME_WE)
    list(APPEND TARGET_APPS ${APP_NAME})
    message("-- APP: ${APP_NAME}")
    # create executable
    add_executable(${APP_NAME} ${APP_SRC})
    target_link_libraries(${APP_NAME} ${LIB_NAME_STATIC})
endforeach(APP_SRC)

# install apps
install(TARGETS ${TARGET_APPS}
    RUNTIME DESTINATION ${DEFAULT_APPS_INSTALL_PATH})
