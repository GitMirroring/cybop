set(cmake_generated
        ${CMAKE_BINARY_DIR}/CMakeCache.txt
        ${CMAKE_BINARY_DIR}/cmake_install.cmake
        ${CMAKE_BINARY_DIR}/CPackConfig.cmake
        ${CMAKE_BINARY_DIR}/CPackSourceConfig.cmake
        ${CMAKE_BINARY_DIR}/Makefile
        ${CMAKE_BINARY_DIR}/CMakeFiles
        ${CMAKE_BINARY_DIR}/result.txt
        ${ROOT_DIR}/src/controller/${BINARY_NAME})

foreach (file ${cmake_generated})

    if (EXISTS ${file})
        file(REMOVE_RECURSE ${file})
    endif ()

endforeach (file)