# set module path for library finds
SET (CMAKE_MODULE_PATH "${CMAKE_MODULE_PATH}" "${PROJECT_SOURCE_DIR}/build")

# --- link necessary libraries --- #

find_package (OpenGL REQUIRED)
IF ( OPENGL_FOUND )
    include_directories(${OpenGL_INCLUDE_DIRS})
    target_link_libraries(${BINARY_NAME} ${OPENGL_LIBRARIES})
ENDIF ( OPENGL_FOUND)

FIND_PACKAGE ( Threads REQUIRED )
target_link_libraries(${BINARY_NAME} ${CMAKE_THREAD_LIBS_INIT}) # link posix thread library to cyboi target

# --- link optional libraries --- #

find_package(GLUT)
IF ( GLUT_FOUND )
    include_directories(${GLUT_INCLUDE_DIRS})
    #override _glut_libraries only with entries that exists
    set(_glut_libraries)
    foreach(_lib ${GLUT_LIBRARIES})
        if(_lib)
            list(APPEND _glut_libraries ${_lib})
        endif()
    endforeach()
    set(GLUT_LIBRARIES ${_glut_libraries})
    target_link_libraries(${BINARY_NAME} ${GLUT_LIBRARIES})
ENDIF ( GLUT_FOUND )


FIND_PACKAGE ( X11 )
IF ( X11_FOUND )
      INCLUDE_DIRECTORIES ( ${X11_INCLUDE_DIR} )
      target_link_libraries(${BINARY_NAME} ${X11_LIBRARIES} )
ENDIF ( X11_FOUND )

FIND_PACKAGE ( XCB )
IF ( XCB_FOUND )
    INCLUDE_DIRECTORIES ( ${XCB_INCLUDE_DIRS} )
    ADD_DEFINITIONS ( ${XCB_DEFINITIONS} )
    target_link_libraries(${BINARY_NAME} ${XCB_LIBRARIES} )
ENDIF ( XCB_FOUND )

IF (UNIX)
  TARGET_LINK_LIBRARIES(${BINARY_NAME} m) # link math library to cyboi target
ENDIF(UNIX)