cmake_minimum_required(VERSION 3.20)
project(gcov)
add_compile_options(--coverage -g)
add_link_options(--coverage)
add_executable(main
	main.c
	lib.c
)
# gcovr is a python package, use uv/pip to install
# run the executable to generate/update coverage data
# in the build directory, run `gcovr -r .. . --html-details coverage.html` to generate/update coverage report
