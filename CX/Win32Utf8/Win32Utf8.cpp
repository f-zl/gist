#include <windows.h>
namespace {
struct Win32Utf8 {
  Win32Utf8() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
  }
};
static Win32Utf8 i;
} // namespace
