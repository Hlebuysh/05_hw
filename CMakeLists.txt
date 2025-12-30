cmake_minimum_required(VERSION 3.10)
project(stack C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

# ===== ахакхнрейю =====
add_library(stack
    stack.c
)

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