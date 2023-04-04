FIND_PACKAGE(Python3 REQUIRED COMPONENTS Interpreter REQUIRED)

add_custom_target(api
        COMMAND ${CMAKE_COMMAND} -E echo api
        COMMENT "generate api data and api website")

add_custom_command(TARGET api
        COMMAND pip3 install -r requirements.txt
        COMMAND python3 apiParser.py
        WORKING_DIRECTORY ${ROOT_DIR}/build/scripts)

add_custom_command(TARGET api
        COMMAND ${ROOT_DIR}/bin/cyboi api-generator/run.cybol
        WORKING_DIRECTORY ${ROOT_DIR}/tools)

add_custom_command(TARGET api
        COMMAND cp api-generator/index.html ${ROOT_DIR}/www/website/documentation/api/index.html
        WORKING_DIRECTORY ${ROOT_DIR}/tools)
