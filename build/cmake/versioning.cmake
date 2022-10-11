FIND_PACKAGE(Python3 REQUIRED COMPONENTS Interpreter REQUIRED)

add_custom_target(adjustCopyright
        COMMAND ${CMAKE_COMMAND} -E echo adjustCopyright
        COMMENT "adjust copyright information with version and new year")

add_custom_command(TARGET adjustCopyright
        COMMAND python3 adjustCopyright.py ${PROJECT_VERSION} "${COPYRIGHT_INFO}"
        WORKING_DIRECTORY ${ROOT_DIR}/build/scripts
        VERBATIM)