CC = gcc
CFLAGS = -Wall -Wextra -Werror -g -O0
SAN_CFLAGS = -fsanitize=address,undefined -fno-omit-frame-pointer -g

SRC = stack.c
OBJ = $(SRC:.c=.o)

.PHONY: all build test bench clean sanitize static coverage

all: build

build: $(SRC)
	$(CC) $(CFLAGS) -o main main.c $(SRC)

test: $(SRC) tests/test_stack.c
	$(CC) $(CFLAGS) -o test_stack tests/test_stack.c $(SRC)
	./test_stack

bench: $(SRC) benchmarks/bench_stack.c
	$(CC) $(CFLAGS) -O2 -o bench benchmarks/bench_stack.c $(SRC)
	./bench

sanitize-test:
	$(CC) $(CFLAGS) $(SAN_CFLAGS) -o test_stack_san tests/test_stack.c $(SRC)
	./test_stack_san

static:
	# cppcheck
	cppcheck --enable=all --inconclusive --std=c11 --suppress=missingIncludeSystem .
	# clang-tidy (if available) - requires compilation db for full power; simple check:
	clang-tidy --version || true

coverage:
	$(CC) -fprofile-arcs -ftest-coverage -g -O0 -o test_cov tests/test_stack.c $(SRC)
	./test_cov
	lcov --capture --directory . --output-file coverage.info
	lcov --remove coverage.info '/usr/*' --output-file coverage.info.cleaned
	genhtml coverage.info.cleaned --output-directory coverage-report
	@echo "Open coverage-report/index.html"

clean:
	rm -f *.o main test_stack bench test_stack_san test_cov *.gcno *.gcda coverage.info coverage.info.cleaned
	rm -rf coverage-report
