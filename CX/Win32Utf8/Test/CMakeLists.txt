cmake_minimum_required(VERSION 3.20)
project(TestWin32Utf8)
# Win32Utf8 directory is external to this CMakeLists, so an explicit binary dir is used
add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/.." ${CMAKE_BINARY_DIR}/Win32Utf8)
add_executable(Test Test.c)
target_link_libraries(Test PRIVATE Win32Utf8)
