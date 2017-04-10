# additional target to perform clang-format run, requires clang-format

# get all project files
file(GLOB_RECURSE ALL_SOURCE_FILES ${CMAKE_CURRENT_SOURCE_DIR}/../src/*.c)

# --- clang-format target --- #
add_custom_target(
        clangformat
#        COMMAND /usr/local/bin/clang-format
        COMMAND /usr/bin/clang-format-3.5
        -style=file
        -i
        ${ALL_SOURCE_FILES}
)

# --- cppcheck Configuration --- #
add_custom_target(
        cppcheck
#        COMMAND /usr/local/bin/cppcheck
        COMMAND /usr/bin/cppcheck
        --enable=warning,performance,portability,information,missingInclude
        --std=c++11
        --library=qt.cfg
        --template="[{severity}][{id}] {message} {callstack} \(On {file}:{line}\)"
        --verbose
        #--quiet
        ${ALL_SOURCE_FILES}
)
