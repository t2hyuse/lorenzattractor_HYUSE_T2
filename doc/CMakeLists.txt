cmake_minimum_required(VERSION 3.10)

find_package(Doxygen)
if(DOXYGEN_FOUND)
    add_custom_target(doc
        COMMAND doxygen ${CMAKE_CURRENT_SOURCE_DIR}/doxyfilerc
        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
        COMMENT "Generating API documentation with Doxygen"
        VERBATIM
    )
endif()
