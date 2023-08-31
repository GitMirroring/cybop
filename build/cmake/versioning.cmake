FIND_PACKAGE(Python3 REQUIRED COMPONENTS Interpreter REQUIRED)

add_custom_target(copyright
        COMMAND ${CMAKE_COMMAND} -E echo copyright
        COMMENT "Adjust copyright information with version and new year")

add_custom_command(TARGET copyright
        COMMAND python3 adjustCopyright.py ${PROJECT_VERSION} "${COPYRIGHT_INFO}"
        WORKING_DIRECTORY ${ROOT_DIR}/build/scripts
        VERBATIM)
