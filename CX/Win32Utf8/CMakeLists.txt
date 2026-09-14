cmake_minimum_required(VERSION 3.20)
project(Win32Utf8)
add_library(Win32Utf8 OBJECT Win32Utf8.cpp Win32Utf8.rc)
# linking against Win32Utf8 makes most Win32 -A APIs use UTF-8 encoding
