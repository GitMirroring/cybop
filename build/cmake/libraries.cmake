# set module path for library finds
set(CMAKE_MODULE_PATH "${CMAKE_MODULE_PATH}" "${PROJECT_SOURCE_DIR}/cmake")

# link necessary libraries

#
# Add support for OpenGL.
#
# Legacy: GL
# New: GLVND (GL vendor-neutral)
#
# Old solution:
# find_package (OpenGL REQUIRED)
#
# New solution:
# find_package(OpenGL REQUIRED COMPONENTS OpenGL)
#
find_package(OpenGL REQUIRED COMPONENTS OpenGL)

if(OPENGL_FOUND)
    include_directories(${OpenGL_INCLUDE_DIRS})
    target_link_libraries(${BINARY_NAME} ${OPENGL_LIBRARIES})
endif(OPENGL_FOUND)

find_package(Threads REQUIRED)
# link posix thread (pthread) library to cyboi target
target_link_libraries(${BINARY_NAME} ${CMAKE_THREAD_LIBS_INIT})

# link optional libraries

find_package(GLUT)

if(GLUT_FOUND)
    include_directories(${GLUT_INCLUDE_DIRS})
    # overwrite _glut_libraries only with entries that exist
    set(_glut_libraries)
    foreach(_lib ${GLUT_LIBRARIES})
        if(_lib)
            list(APPEND _glut_libraries ${_lib})
        endif()
    endforeach()
    set(GLUT_LIBRARIES ${_glut_libraries})
    target_link_libraries(${BINARY_NAME} ${GLUT_LIBRARIES})
endif(GLUT_FOUND)

find_package(X11)

if(X11_FOUND)
    include_directories(${X11_INCLUDE_DIR})
    target_link_libraries(${BINARY_NAME} ${X11_LIBRARIES})
endif(X11_FOUND)

find_package(XCB)

if(XCB_FOUND)
    include_directories(${XCB_INCLUDE_DIRS})
    add_definitions(${XCB_DEFINITIONS})
    target_link_libraries(${BINARY_NAME} ${XCB_LIBRARIES})
endif(XCB_FOUND)

if(UNIX)
    # link math library to cyboi target
    target_link_libraries(${BINARY_NAME} m)
endif(UNIX)

if(XDT_LIBRARY_CMAKE_CONFIGURATION)

    # link libraries to executable
    #target_link_libraries(${BINARY_NAME} PUBLIC ${EXTRA_LIBS})
    target_link_libraries(${BINARY_NAME} ${EXTRA_LIBS})

    #
    # add binary tree to search path for include files
    #
    # CAUTION! The "PUBLIC" is important.
    #
    target_include_directories(${BINARY_NAME} PUBLIC
        # "${PROJECT_BINARY_DIR}"
        "${ROOT_DIR}/src/xdt"
        #"${ROOT_DIR}/src/${EXTRA_INCLUDES}"
    )

endif(XDT_LIBRARY_CMAKE_CONFIGURATION)
