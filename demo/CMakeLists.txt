cmake_minimum_required(VERSION 3.10)

add_executable(lorenzattractor_demo
    demo_lorenzattractor.cxx
)

target_include_directories(lorenzattractor_demo PRIVATE
    ${CMAKE_SOURCE_DIR}/include
)

target_link_libraries(lorenzattractor_demo PRIVATE
    lorenzattractor_lib
)
