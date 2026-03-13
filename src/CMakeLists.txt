cmake_minimum_required(VERSION 3.10)

add_library(lorenzattractor_lib
    lorenzattractor.cxx
)

target_include_directories(lorenzattractor_lib PUBLIC
    ${CMAKE_SOURCE_DIR}/include
)
