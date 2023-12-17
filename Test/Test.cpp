#include "Test.h"

#include <array>
#include <cstdio>

std::array<const char*, 2> g_exports = {"foo", "bar"};

void foo() {
    printf("I can't!\n");
}

// int bar = 200;