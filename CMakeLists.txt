cmake_minimum_required(VERSION 3.20)
project(urechko_a_e)

set(CMAKE_CXX_STANDARD 14)

include_directories(queue_p queue_r doctest)
add_subdirectory(urechko_a_e/queue_p)
add_subdirectory(urechko_a_e/queue_r)
