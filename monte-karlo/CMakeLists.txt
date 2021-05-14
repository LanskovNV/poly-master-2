cmake_minimum_required(VERSION 3.17)
project(monte_karlo C)

set(CMAKE_C_STANDARD 99)

add_executable(monte_karlo main.c)
target_link_libraries(monte_karlo m) # link libm with some math functions like pow, log etc. on linux