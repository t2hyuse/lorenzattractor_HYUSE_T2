cmake_minimum_required(VERSION 3.10)
project(lorenzattractor)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Build targets
add_subdirectory(src)
add_subdirectory(test)
add_subdirectory(demo)

# Documentation target
find_package(Doxygen)
if(DOXYGEN_FOUND)
    add_custom_target(doc
        COMMAND doxygen ${CMAKE_CURRENT_SOURCE_DIR}/doc/doxyfilerc
        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
        COMMENT "Generating API documentation with Doxygen"
        VERBATIM
    )
else()
    message(WARNING "Doxygen not found, 'make doc' will not be available.")
endif()
