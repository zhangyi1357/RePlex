#include <array>
#include <cstdio>

extern "C" {
void foo() {
    printf("I can't!\n");
}
}

int bar = 300;

std::array<const char*, 2> g_exports = {"foo", "bar"};