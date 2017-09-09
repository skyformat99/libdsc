# append to the LIB_SOURCES here
set(LIST_DIR ${CMAKE_CURRENT_SOURCE_DIR}) 
set(LIB_SOURCES
    ${LIB_SOURCES}
    ${LIST_DIR}/singly-linked-list.c
    ${LIST_DIR}/list-private.h
    PARENT_SCOPE)
