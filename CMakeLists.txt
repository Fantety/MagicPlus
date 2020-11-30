cmake_minimum_required(VERSION 2.8)
project(MagicPlus)
link_libraries(sqlite3)
include_directories(include)
add_subdirectory(src)

add_executable(MagicPlus main.cpp)
target_link_libraries(MagicPlus magicplus)