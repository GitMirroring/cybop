# --- setup project specific vars --- #
set(CPACK_PACKAGE_NAME "CYBOP")
set(CPACK_PACKAGE_CONTACT "christian.heller@tuxtax.de")
set(CPACK_PACKAGE_DESCRIPTION_FILE "${CMAKE_CURRENT_SOURCE_DIR}/README")
set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "Cybernetics Oriented Programming (CYBOP) <http://www.cybop.org/>")
set(CPACK_RESOURCE_FILE_LICENSE "${CMAKE_CURRENT_SOURCE_DIR}/COPYING")

# --- setup project version number --- #
SET(CPACK_PACKAGE_VERSION_MAJOR "0")
SET(CPACK_PACKAGE_VERSION_MINOR "19")
SET(CPACK_PACKAGE_VERSION_PATCH "0")

# --- setup the release content --- #
# TODO: what should be included, what's about all the papers and so on?
# we can include directories using file patterns and so on, the more generic,
# the less adjustments we need to do here later on when the files change
INSTALL(FILES ${CMAKE_CURRENT_SOURCE_DIR}/src/controller/cyboi DESTINATION .)
INSTALL(FILES ${CMAKE_CURRENT_SOURCE_DIR}/doc/books/cybol/api.html DESTINATION doc/books/cybol)
INSTALL(FILES ${CMAKE_CURRENT_SOURCE_DIR}/doc/books/cybol/api.css DESTINATION doc/books/cybol)
INSTALL(FILES ${CMAKE_CURRENT_SOURCE_DIR}/doc/books/cybol/cybol_2007-07-31.pdf DESTINATION doc/books/cybol)
INSTALL(FILES ${CMAKE_CURRENT_SOURCE_DIR}/doc/books/cybop/cybop.pdf DESTINATION doc/books/cybop)
INSTALL(FILES ${CMAKE_CURRENT_SOURCE_DIR}/doc/manual/manual-en.pdf DESTINATION doc/manual)
INSTALL(FILES ${CMAKE_CURRENT_SOURCE_DIR}/doc/manual/manual-de.pdf DESTINATION doc/manual)
INSTALL(FILES ${CMAKE_CURRENT_SOURCE_DIR}/doc/lightning_talk/cybop.pdf DESTINATION doc/lightning_talk)
#INSTALL(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/doc/lightning_talk/ DESTINATION doc/lightning_talk FILES_MATCHING PATTERN "*.pdf")
INSTALL(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/examples/ DESTINATION examples)
INSTALL(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/src/ DESTINATION src)
INSTALL(FILES ${CMAKE_CURRENT_SOURCE_DIR}/AUTHORS DESTINATION .)
INSTALL(FILES ${CMAKE_CURRENT_SOURCE_DIR}/ChangeLog DESTINATION .)
INSTALL(FILES ${CMAKE_CURRENT_SOURCE_DIR}/COPYING DESTINATION .)
INSTALL(FILES ${CMAKE_CURRENT_SOURCE_DIR}/INSTALL DESTINATION .)
INSTALL(FILES ${CMAKE_CURRENT_SOURCE_DIR}/NEWS DESTINATION .)
INSTALL(FILES ${CMAKE_CURRENT_SOURCE_DIR}/README DESTINATION .)

# --- setup packaging configuration --- #
if(UNIX AND NOT APPLE)
    set(CPACK_GENERATOR "TGZ;DEB")
elseif (APPLE)
    set(CPACK_GENERATOR "TGZ")
else()
    message( SEND_ERROR "Windows is not supported yet" )
endif()

# --- load global setting file --- #
include(CPack)
