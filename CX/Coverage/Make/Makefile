EXT     := $(if $(filter Windows_NT, $(OS)),.exe,)
SRCS    := $(wildcard *.c) # main.c lib.c
OBJS    := $(patsubst %.c, %.o, $(SRCS)) # main.o lib.o
GCOVS   := $(patsubst %.c, %.c.gcov, $(SRCS)) # main.c.gcov lib.c.gcov
CFLAGS  := --coverage
LDFLAGS := --coverage

.PHONY: report print clean

# usage:
# 1. run `make` to build `main` executable
# 2. run `main` executable to save coverage data to binary .gcda files
# 3. run `make report` to generate .c.gcov files that contain text coverage report
#    in the report, `#####` marks the lines that have not been executed
# 4. run `make print` to print reports to console
# 5. goto step 2

main$(EXT):$(OBJS)
	gcc $(LDFLAGS) $^ -o $@
%.o:%.c # this generates %.o and %.gcno
	gcc $(CFLAGS) -c $<
report:main$(EXT)
	gcov $(SRCS)
print:$(GCOVS)
	cat $(GCOVS)
clean:
	rm -f *.o *.gcno *.gcda *.gcov main$(EXT)
