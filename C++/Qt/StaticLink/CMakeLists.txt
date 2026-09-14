# an example cmake project to link qt libraries statically in msys2
cmake_minimum_required(VERSION 3.20)
project(QtStaticLink CXX)
list(PREPEND CMAKE_FIND_LIBRARY_SUFFIXES .a .lib) # prefer static libraries
find_package(Qt5 REQUIRED Widgets) # use Qt5 since Qt6 cannot be fully statically linked yet in msys2
add_compile_options(-static)
add_link_options(-static)
add_executable(${PROJECT_NAME} main.cpp)
target_link_libraries(${PROJECT_NAME} Qt::Widgets)
# use -DCMAKE_PREFIX_PATH=C:\msys64\mingw64\qt5-static to choose qt5-static
# use ldd or ntldd to check dynamic library dependencies of the executable

# -Os and strip post process can be used to decrease the executable's size
