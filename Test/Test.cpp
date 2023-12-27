#include <array>
#include <cstdio>

extern "C" {
void foo() {
    printf("I can't!\n");
}
}

int bar = 100;