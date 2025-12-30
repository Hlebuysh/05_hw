cmake_minimum_required(VERSION 3.10)
project(stack C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

# ===== ахакхнрейю =====
add_library(stack
    stack.c
)

target_compile_options(stack PRIVATE "-fprofile-arcs" "-ftest-coverage")
target_link_options(stack PRIVATE "-fprofile-arcs" "-ftest-coverage")

target_compile_options(main PRIVATE "-fprofile-arcs" "-ftest-coverage")
target_link_options(main PRIVATE "-fprofile-arcs" "-ftest-coverage")

target_compile_options(test_stack PRIVATE "-fprofile-arcs" "-ftest-coverage")
target_link_options(test_stack PRIVATE "-fprofile-arcs" "-ftest-coverage")

target_compile_options(bench PRIVATE "-fprofile-arcs" "-ftest-coverage")
target_link_options(bench PRIVATE "-fprofile-arcs" "-ftest-coverage")


target_include_directories(stack PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)

# ===== нямнбмюъ опнцпюллю =====
add_executable(main
    main.c
)

target_link_libraries(main PRIVATE stack)

# ===== реярш =====
add_executable(test_stack
    tests/test_stack.c
)

target_link_libraries(test_stack PRIVATE stack)

# ===== аемвлюпй =====
add_executable(bench
    benchmarks/bench_stack.c
)

target_link_libraries(bench PRIVATE stack)

add_custom_target(coverage
    COMMAND lcov --capture --directory ${CMAKE_BINARY_DIR} --output-file coverage.info
    COMMAND lcov --remove coverage.info '/usr/*' --output-file coverage.info
    COMMAND genhtml coverage.info --output-directory coverage-report
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
    COMMENT "Generating code coverage report"
)