# --- CMake configuration --- #
# set minimum required cmake version
cmake_minimum_required(VERSION 3.0.2)

# set project name
project(cyboi)

# set output directory to controller-subdirectory
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/src/controller)

# define the binary to be create by make
add_executable(${PROJECT_NAME} ${PROJECT_SOURCE_DIR}/src/controller/cyboi.c)

# --- CPack Configuration --- #

#set project specific vars
set(CPACK_PACKAGE_NAME "CYBOP")
set(CPACK_PACKAGE_CONTACT "christian.heller@tuxtax.de")
set(CPACK_PACKAGE_DESCRIPTION_FILE "${CMAKE_CURRENT_SOURCE_DIR}/README")
set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "Cybernetics Oriented Programming (CYBOP) <http://www.cybop.org/>")
set(CPACK_RESOURCE_FILE_LICENSE "${CMAKE_CURRENT_SOURCE_DIR}/COPYING")

# set the version information
SET(CPACK_PACKAGE_VERSION_MAJOR "0")
SET(CPACK_PACKAGE_VERSION_MINOR "19")
SET(CPACK_PACKAGE_VERSION_PATCH "0")

# --- CPack Setup the Components --- #

# add the files to the release distributed in specific components
# TODO: cybop defintion (include/exclude) definition is quite obsolote and
# it differs from what got released in the last 0.18.0 cybop zip
# what should be included, what's about all the papers and so on?
# we can include directories using file patterns but need to know the expected result
INSTALL(FILES ${CMAKE_CURRENT_SOURCE_DIR}/src/Controller/cyboi DESTINATION . COMPONENT cybop)
INSTALL(FILES ${CMAKE_CURRENT_SOURCE_DIR}/doc/books/cybol/api.html  DESTINATION doc/books/cybol COMPONENT cybop)
INSTALL(FILES ${CMAKE_CURRENT_SOURCE_DIR}/doc/books/cybol/api.css  DESTINATION doc/books/cybol COMPONENT cybop)
INSTALL(FILES ${CMAKE_CURRENT_SOURCE_DIR}/doc/books/cybol/cybol_2007-07-31.pdf  DESTINATION doc/books/cybol COMPONENT cybop)
INSTALL(FILES ${CMAKE_CURRENT_SOURCE_DIR}/doc/books/cybop/cybop.pdf  DESTINATION doc/books/cybop COMPONENT cybop)
INSTALL(FILES ${CMAKE_CURRENT_SOURCE_DIR}/doc/manual/manual-en.pdf  DESTINATION doc/manual COMPONENT cybop)
INSTALL(FILES ${CMAKE_CURRENT_SOURCE_DIR}/doc/manual/manual-de.pdf  DESTINATION doc/manual COMPONENT cybop)
INSTALL(FILES ${CMAKE_CURRENT_SOURCE_DIR}/doc/lightning_talk/cybop.pdf  DESTINATION doc/lightning_talk COMPONENT cybop)
#INSTALL(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/doc/lightning_talk/ DESTINATION doc/lightning_talk COMPONENT cybop FILES_MATCHING PATTERN "*.pdf")
INSTALL(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/examples/ DESTINATION examples COMPONENT cybop)
INSTALL(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/src/ DESTINATION src COMPONENT cybop)
INSTALL(FILES ${CMAKE_CURRENT_SOURCE_DIR}/AUTHORS DESTINATION . COMPONENT cybop)
INSTALL(FILES ${CMAKE_CURRENT_SOURCE_DIR}/ChangeLog DESTINATION . COMPONENT cybop)
INSTALL(FILES ${CMAKE_CURRENT_SOURCE_DIR}/COPYING DESTINATION . COMPONENT cybop)
INSTALL(FILES ${CMAKE_CURRENT_SOURCE_DIR}/INSTALL DESTINATION . COMPONENT cybop)
INSTALL(FILES ${CMAKE_CURRENT_SOURCE_DIR}/NEWS DESTINATION . COMPONENT cybop)
INSTALL(FILES ${CMAKE_CURRENT_SOURCE_DIR}/README DESTINATION . COMPONENT cybop)

# TODO: cybol defintion (include/exclude) definition is quite obsolote, what should be included, how should the structure look like?
INSTALL(FILES ${CMAKE_CURRENT_SOURCE_DIR}/admin/cybol.5.gz DESTINATION . COMPONENT cybol)
INSTALL(FILES ${CMAKE_CURRENT_SOURCE_DIR}/doc/books/cybol/schema/cybol.dtd DESTINATION doc/books/schema/cybol COMPONENT cybol)
INSTALL(FILES ${CMAKE_CURRENT_SOURCE_DIR}/doc/books/cybol/schema/cybol.ebnf DESTINATION doc/books/schema/cybol COMPONENT cybol)
INSTALL(FILES ${CMAKE_CURRENT_SOURCE_DIR}/doc/books/cybol/schema/cybol_with_types.xsd DESTINATION doc/books/schema/cybol COMPONENT cybol)
INSTALL(FILES ${CMAKE_CURRENT_SOURCE_DIR}/doc/books/cybol/schema/cybol.xsd DESTINATION doc/books/schema/cybol COMPONENT cybol)
INSTALL(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/examples/ DESTINATION examples COMPONENT cybol)

# TODO: cyboi defintion (include/exclude) definition is quite obsolote, what should be included, how should the structure look like?
INSTALL(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/admin/ DESTINATION admin COMPONENT cyboi)
INSTALL(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/src/ DESTINATION src COMPONENT cyboi)


# set the component information
set(CPACK_COMPONENTS_ALL cybop cyboi cybol)

set(CPACK_COMPONENT_CYBOP_DISPLAY_NAME "CYBOP")
set(CPACK_COMPONENT_CYBOP_DESCRIPTION "Cybernetics Oriented Programming")
set(CPACK_COMPONENT_CYBOI_DISPLAY_NAME "CYBOI")
set(CPACK_COMPONENT_CYBOI_DESCRIPTION "XML-based application programming- and knowledge specification language")
set(CPACK_COMPONENT_CYBOL_DISPLAY_NAME "CYBOL")
set(CPACK_COMPONENT_CYBOL_DESCRIPTION "corresponding interpreter, written in C")

# pack it to the dist directory
set(CPACK_GENERATOR "TGZ")
set(CPACK_ARCHIVE_COMPONENT_INSTALL ON)
#set(CPACK_INCLUDE_TOPLEVEL_DIRECTORY OFF)
#set(CPACK_COMPONENT_INCLUDE_TOPLEVEL_DIRECTORY OFF)
#set(CPACK_SET_DESTDIR ON)
#SET(CPACK_TOPLEVEL_TAG ../dist)

# activate CPack
include(CPack)