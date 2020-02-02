#if defined(__linux__) || defined(__unix__) || defined(__APPLE__) || defined(__HAIKU__)
#pragma message "is unix-y"
#include <unistd.h>
#endif

#if defined(_POSIX_VERSION) && !defined(__CYGWIN__)
#pragma message "is posix-y"
#include <dlfcn.h>
#endif

#if defined(_WIN32) || defined(__CYGWIN__)
#pragma message "is windows-y"
#include <windows.h>
#endif

// c++17
#if __has_include(<unistd.h>)
#pragma message "is unix-y"
#include <unistd.h>
#endif

#if __has_include(<dlfcn.h>)
#pragma message "is posix-y"
#include <dlfcn.h>
#endif

#if __has_include(<windows.h>)
#pragma message "is windows-y"
#include <windows.h>
#endif

int main()
{
}