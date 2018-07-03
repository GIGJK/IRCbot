cmake_minimum_required(VERSION 2.8)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -Wall -pthread -fopenmp")

set(Boost_USE_STATIC_LIBS ON)
set(Boost_USE_MULTITHREADED ON)

find_package(Boost)
if (NOT Boost_FOUND)
    set(Boost_INCLUDE_DIRS /usr/include/boost/)
#    return()
endif()

INCLUDE_DIRECTORIES(${Boost_INCLUDE_DIRS})
link_directories(${Boost_LIBRARY_DIRS})

set(SOURCES main.cpp core/bot_connect.cpp) # And other sources
set(HEADERS core/bot_connect.hpp) # And other headers

project(IRCbot)
add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})
target_link_libraries(${PROJECT_NAME} ${Boost_LIBRARIES} boost_system boost_unit_test_framework)
