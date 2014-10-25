cmake_minimum_required(VERSION 2.8)
cmake_policy(SET CMP0015 NEW)
project (entityx_ne_test)

if(APPLE)
  set(OS_DIR mac)
elseif(UNIX)
  set(OS_DIR linux)
elseif(WIN32)
  set(OS_DIR win32)
endif()

set( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -fexceptions -std=c++11 -Wno-unused-parameter -Wno-unused-variable -Wno-c++11-extensions -stdlib=libc++ -g -O0" )

set (SRCS
main.cpp
interpolator_test.cpp
net_entity_manager_test.cpp
net_event_test.cpp

support/test_net_connection.cpp

../src/net_entity_manager.cpp
)


link_directories ( ../vendor/${OS_DIR} )
include_directories (../include)
include_directories (SYSTEM ../vendor)

add_executable(entityx_ne_test ${SRCS})
target_link_libraries(entityx_ne_test libgtest.a libentityx.a)
