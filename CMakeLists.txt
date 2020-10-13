project(Limpopo_exam)
cmake_minimum_required(VERSION 2.8)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Weffc++")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wshadow -Werror")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-missing-field-initializers")

add_executable(../box/final
    exam/exam.cpp
    exam/http_server.h
    exam/http_server.cpp
    exam/thread_safe_socket_queue.h
    exam/thread_safe_socket_queue.cpp)

target_link_libraries(../box/final
    pthread
    ${Boost_PROGRAM_OPTIONS_LIBRARIES})
