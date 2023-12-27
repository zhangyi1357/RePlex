#include "Test.h"

#include <array>
#include <cstdio>

std::array<const char*, 2> g_exports = {"foo", "bar"};

void foo() {
    printf("I can't!\n");
}

<<<<<<< HEAD
// int bar = 200;
=======
int bar = 300;

std::array<const char*, 2> g_exports = {"foo", "bar"};
>>>>>>> 318ad72 (CMake)
