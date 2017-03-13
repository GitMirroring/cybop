# --- clang-format target --- #
add_custom_target(
        codecoverage
        COMMAND lcov 
        -directory . 
        -capture 
        -output-file coverage.result
)

add_custom_target(
        generatehtml
        COMMAND genhtml 
        -o coverage.info coverage.result
)