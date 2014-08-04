cmake_minimum_required(VERSION 2.8)
project (entityx_ne)

if(APPLE)
  set(OS_DIR mac)
elseif(UNIX)
  set(OS_DIR linux)
elseif(WIN32)
  set(OS_DIR win32)
endif()

add_subdirectory(test)
