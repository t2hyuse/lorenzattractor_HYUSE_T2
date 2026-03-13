cmake_minimum_required(VERSION 3.10)

add_executable(lorenzattractor_test
    test_lorenzattractor.cxx
)

target_include_directories(lorenzattractor_test PRIVATE
    ${CMAKE_SOURCE_DIR}/include
)

target_link_libraries(lorenzattractor_test PRIVATE
    lorenzattractor_lib
)
