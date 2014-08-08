cmake_minimum_required(VERSION 2.8)
project (entityx_ne)

if(APPLE)
  set(OS_DIR mac)
elseif(UNIX)
  set(OS_DIR linux)
elseif(WIN32)
  set(OS_DIR win32)
endif()

set( CMAKE_EXPORT_COMPILE_COMMANDS 1 )

set( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -fexceptions -std=c++11 -Wno-unused-parameter -Wno-unused-variable -Wno-c++11-extensions -stdlib=libc++" )

add_subdirectory(test)
