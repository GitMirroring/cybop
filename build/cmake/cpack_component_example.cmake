#
# The project-specific variables.
#
set(CPACK_PACKAGE_NAME "CYBOP")
set(CPACK_PACKAGE_CONTACT "christian.heller@tuxtax.de")
set(CPACK_PACKAGE_DESCRIPTION_FILE "${ROOT_DIR}/README")
set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "Cybernetics Oriented Programming (CYBOP) <http://www.cybop.org/>")
set(CPACK_RESOURCE_FILE_LICENSE "${ROOT_DIR}/COPYING")

#
# The version information.
#
SET(CPACK_PACKAGE_VERSION_MAJOR "0")
SET(CPACK_PACKAGE_VERSION_MINOR "19")
SET(CPACK_PACKAGE_VERSION_PATCH "0")

#
# The components.
#
# The files to be added to the release,
# distributed in specific components.
# One can include directories and files using file patterns.
#

# The cyboi component.
INSTALL(FILES ${ROOT_DIR}/build/manpage/cyboi.1.gz DESTINATION build/manpage COMPONENT cyboi)
INSTALL(DIRECTORY ${ROOT_DIR}/src/ DESTINATION src COMPONENT cyboi)

# The cybol component.
INSTALL(FILES ${ROOT_DIR}/build/manpage/cybol.5.gz DESTINATION build/manpage COMPONENT cybol)
INSTALL(DIRECTORY ${ROOT_DIR}/doc/cybol/api/ DESTINATION doc/cybol/api COMPONENT cybol)
INSTALL(DIRECTORY ${ROOT_DIR}/doc/cybol/schema/ DESTINATION doc/cybol/schema COMPONENT cybol)
INSTALL(DIRECTORY ${ROOT_DIR}/doc/cybol/syntax/ DESTINATION doc/cybol/syntax COMPONENT cybol)
INSTALL(DIRECTORY ${ROOT_DIR}/doc/cybol/api/ DESTINATION doc/cybol/api COMPONENT cybol)
INSTALL(FILES ${ROOT_DIR}/doc/cybol/cybol_2007-07-31.pdf DESTINATION doc/cybol COMPONENT cybol)
INSTALL(DIRECTORY ${ROOT_DIR}/examples/ DESTINATION examples COMPONENT cybol)

# The cybop component.
INSTALL(FILES ${ROOT_DIR}/build/manpage/cybop.7.gz DESTINATION build/manpage COMPONENT cybop)
INSTALL(FILES ${ROOT_DIR}/doc/books/cybop/cybop.pdf DESTINATION doc/books/cybop COMPONENT cybop)
INSTALL(FILES ${ROOT_DIR}/doc/lightning_talk/cybop.pdf DESTINATION doc/lightning_talk COMPONENT cybop)
#INSTALL(DIRECTORY ${ROOT_DIR}/doc/lightning_talk/ DESTINATION doc/lightning_talk COMPONENT cybop FILES_MATCHING PATTERN "*.pdf")
INSTALL(FILES ${ROOT_DIR}/doc/manual/manual-de.pdf DESTINATION doc/manual COMPONENT cybop)
INSTALL(FILES ${ROOT_DIR}/doc/manual/manual-en.pdf DESTINATION doc/manual COMPONENT cybop)
INSTALL(FILES ${ROOT_DIR}/AUTHORS DESTINATION . COMPONENT cybop)
INSTALL(FILES ${ROOT_DIR}/ChangeLog DESTINATION . COMPONENT cybop)
INSTALL(FILES ${ROOT_DIR}/COPYING DESTINATION . COMPONENT cybop)
INSTALL(FILES ${ROOT_DIR}/INSTALL DESTINATION . COMPONENT cybop)
INSTALL(FILES ${ROOT_DIR}/NEWS DESTINATION . COMPONENT cybop)
INSTALL(FILES ${ROOT_DIR}/README DESTINATION . COMPONENT cybop)

# Set component information.
set(CPACK_COMPONENTS_ALL cyboi cybol cybop)
set(CPACK_COMPONENT_CYBOI_DISPLAY_NAME "CYBOI")
set(CPACK_COMPONENT_CYBOI_DESCRIPTION "XML-based application programming- and knowledge specification language")
set(CPACK_COMPONENT_CYBOL_DISPLAY_NAME "CYBOL")
set(CPACK_COMPONENT_CYBOL_DESCRIPTION "corresponding interpreter, written in C")
set(CPACK_COMPONENT_CYBOP_DISPLAY_NAME "CYBOP")
set(CPACK_COMPONENT_CYBOP_DESCRIPTION "Cybernetics Oriented Programming")

# Setup packaging configuration.
set(CPACK_GENERATOR "TGZ")
set(CPACK_ARCHIVE_COMPONENT_INSTALL ON)
#set(CPACK_INCLUDE_TOPLEVEL_DIRECTORY OFF)
#set(CPACK_COMPONENT_INCLUDE_TOPLEVEL_DIRECTORY OFF)
#set(CPACK_SET_DESTDIR ON)
#SET(CPACK_TOPLEVEL_TAG ../dist)
