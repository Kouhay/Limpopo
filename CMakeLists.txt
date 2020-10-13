project(Limpopo_exam)
cmake_minimum_required(VERSION 2.8)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c99")

set (LIBS "-pthread")

aux_source_directory(src SRCS)

find_package(Boost 1.54 COMPONENTS program_options REQUIRED)
add_executable(
    exam/exam.cpp
    exam/http_server.h
    exam/http_server.cpp
    exam/thread_safe_socket_queue.h
    exam/thread_safe_socket_queue.cpp)

target_link_libraries(
    ${Boost_PROGRAM_OPTIONS_LIBRARIES})
