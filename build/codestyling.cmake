# additional target to perform clang-format run, requires clang-format

# get all project files
file(GLOB_RECURSE ALL_SOURCE_FILES ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)

# --- clang-format target --- #
add_custom_target(
        clangformat
        COMMAND /usr/local/bin/clang-format
        -style=LLVM
        -i
        ${ALL_SOURCE_FILES}
)

# --- cppcheck Configuration --- #
add_custom_target(
        cppcheck
        COMMAND /usr/local/bin/cppcheck
        --enable=warning,performance,portability,information,missingInclude
        --std=c++11
        --library=qt.cfg
        --template="[{severity}][{id}] {message} {callstack} \(On {file}:{line}\)"
        --verbose
        #--quiet
        ${ALL_SOURCE_FILES}
)