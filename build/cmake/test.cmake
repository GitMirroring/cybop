FIND_PACKAGE(Python3 REQUIRED COMPONENTS Interpreter REQUIRED)

add_custom_target(test
        COMMAND python3.9 ${ROOT_DIR}/build/scripts/integrationTester.py
        COMMENT "execute all examples and collect results about success")