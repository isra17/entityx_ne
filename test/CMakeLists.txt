cmake_minimum_required(VERSION 2.8)
cmake_policy(SET CMP0015 NEW)
project (entityx_ne_test)

set (SRCS
main.cpp
interpolator_test.cpp
net_entity_manager_test.cpp
../src/net_entity_manager.cpp
)

set( CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} -std=c++11)

link_directories ( ../vendor/${OS_DIR} )
include_directories (../vendor/ ../include)


add_executable(entityx_ne_test ${SRCS})
target_link_libraries(entityx_ne_test libgtest.a libentityx.a)
