CMAKE_MINIMUM_REQUIRED(VERSION 2.8)
PROJECT(ghost)
FIND_PACKAGE(Qt4 REQUIRED)

add_definitions("-O0 -g")

ADD_SUBDIRECTORY(libofono-qt)
ADD_SUBDIRECTORY(mongoose)
ADD_SUBDIRECTORY(src)
