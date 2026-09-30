# run ./a.out to run fuzzy testing
# `./a.out -help=1` prints the flags
# `gdb --args ./a.out crash-xxx` to load the crash file as input
# libfuzzer doesn't work on Windows yet
a.out:a.c
	clang -fsanitize=address,fuzzer -g a.c
clean:
	rm a.out crash-*
