#
# The project-specific variables.
#
set(CPACK_PACKAGE_NAME "cybop")
set(CPACK_PACKAGE_CONTACT "christian.heller@cybop.org")
set(CPACK_PACKAGE_DESCRIPTION_FILE "${ROOT_DIR}/README")
set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "Cybernetics Oriented Programming (CYBOP) <http://www.cybop.org/>")
set(CPACK_RESOURCE_FILE_LICENSE "${ROOT_DIR}/COPYING")

#
# The version information.
#
SET(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
SET(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
SET(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")
SET(CPACK_PACKAGE_VERSION "${CPACK_PACKAGE_VERSION_MAJOR}.${CPACK_PACKAGE_VERSION_MINOR}.${CPACK_PACKAGE_VERSION_PATCH}")

#
# The components.
#
# The files to be added to the release,
# distributed in specific components.
# One can include directories and files using file patterns.
#

# The cyboi component.
INSTALL(DIRECTORY ${ROOT_DIR}/build/cmake/ DESTINATION build/cmake)
INSTALL(DIRECTORY ${ROOT_DIR}/build/icon/ DESTINATION build/icon)
INSTALL(FILES ${ROOT_DIR}/build/manpage/cyboi.1.gz DESTINATION build/manpage)
INSTALL(FILES ${ROOT_DIR}/build/.clang-format DESTINATION build)
INSTALL(FILES ${ROOT_DIR}/build/cmake_config.h.in DESTINATION build)
INSTALL(FILES ${ROOT_DIR}/build/CMakeLists.txt DESTINATION build)
INSTALL(DIRECTORY ${ROOT_DIR}/src/ DESTINATION src)

# The cybol component.
INSTALL(FILES ${ROOT_DIR}/build/manpage/cybol.5.gz DESTINATION build/manpage)
INSTALL(DIRECTORY ${ROOT_DIR}/tools/api-generator/ DESTINATION tools/api-generator)
#INSTALL(DIRECTORY ${ROOT_DIR}/doc/cybol/ DESTINATION doc/cybol)
INSTALL(DIRECTORY ${ROOT_DIR}/app/ DESTINATION app)

# The cybop component.
INSTALL(FILES ${ROOT_DIR}/build/manpage/cybop.7.gz DESTINATION build/manpage)
#INSTALL(FILES ${ROOT_DIR}/doc/books/cybop/cybop.pdf DESTINATION doc/books/cybop)
#INSTALL(FILES ${ROOT_DIR}/doc/presentations/lightning_talk/cybop.pdf DESTINATION doc/presentations/lightning_talk)
#INSTALL(DIRECTORY ${ROOT_DIR}/doc/lightning_talk/ DESTINATION doc/lightning_talk COMPONENT cybop FILES_MATCHING PATTERN "*.pdf")
#INSTALL(FILES ${ROOT_DIR}/doc/manual/manual-de.pdf DESTINATION doc/manual)
#INSTALL(FILES ${ROOT_DIR}/doc/manual/manual-en.pdf DESTINATION doc/manual)
INSTALL(FILES ${ROOT_DIR}/AUTHORS DESTINATION .)
INSTALL(FILES ${ROOT_DIR}/ChangeLog DESTINATION .)
INSTALL(FILES ${ROOT_DIR}/COPYING DESTINATION .)
INSTALL(FILES ${ROOT_DIR}/INSTALL DESTINATION .)
INSTALL(FILES ${ROOT_DIR}/NEWS DESTINATION .)
INSTALL(FILES ${ROOT_DIR}/README DESTINATION .)

# Setup packaging configuration.
list(APPEND GENERATORS "TGZ" "DEB")
if (APPLE)
    list(APPEND GENERATORS "Bundle")
elseif(NOT UNIX)
    message( SEND_ERROR "Windows is not supported yet" )
endif()

set(CPACK_GENERATOR ${GENERATORS})
SET(CPACK_PACKAGE_DIRECTORY ${ROOT_DIR}/dist)

# Load global setting file.
include(CPack)

