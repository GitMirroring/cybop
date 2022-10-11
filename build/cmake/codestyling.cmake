# additional target to perform clang-format run, requires clang-format

# get all project files
file(GLOB_RECURSE ALL_SOURCE_FILES ${ROOT_DIR}/src/*.c)

find_package(ClangFormat)

# --- clang-format target --- #
add_custom_target(
        formatting
        COMMAND ${CLANG_FORMAT_EXECUTABLE}
        --dry-run
        --Werror
        -style=file
        -verbose
        -i
        ${ALL_SOURCE_FILES}
)

if(UNIX AND NOT APPLE)
    set(cppcheck_command "/usr/bin/cppcheck")
elseif (APPLE)
    set(cppcheck_command "/usr/local/bin/cppcheck")
else()
    message( SEND_ERROR "Windows is not supported yet" )
endif()

# --- cppcheck Configuration --- #
add_custom_target(
        analysis
        COMMAND ${cppcheck_command}
        --enable=all
        --inconclusive
        --error-exitcode=13
        --std=c++11
        --library=qt.cfg
        --template="[{severity}][{id}] {message} {callstack} \(On {file}:{line}\)"
        --verbose
        ${ROOT_DIR}/src
)
