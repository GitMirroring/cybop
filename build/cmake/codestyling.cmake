# additional target to perform clang-format run, requires clang-format

# get all project files
file(GLOB_RECURSE ALL_SOURCE_FILES ${CMAKE_CURRENT_SOURCE_DIR}/../src/*.c)

if(UNIX AND NOT APPLE)
    set(clang_command "/usr/bin/clang-format-3.5")
elseif (APPLE)
    set(clang_command "/usr/local/bin/clang-format")
else()
    message( SEND_ERROR "Windows is not supported yet" )
endif()

# --- clang-format target --- #
add_custom_target(
        clangformat
        COMMAND ${clang_command}
        -style=file
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
        cppcheck
        COMMAND ${cppcheck_command}
        --enable=warning,performance,portability,information,missingInclude
        --std=c++11
        --library=qt.cfg
        --template="[{severity}][{id}] {message} {callstack} \(On {file}:{line}\)"
        --verbose
        #--quiet
        ${ALL_SOURCE_FILES}
)
