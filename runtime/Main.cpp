#include <RePlex.h>

#include <iostream>

#ifdef DEBUG
const char* g_libPath = "bin/Debug/libRePlexTest.so";
#else
const char* g_libPath = "bin/Release/libRePlexTest.so";
#endif

void (*foo)();

int main() {
    void* handle = Load(g_libPath);
    if (handle) {
        // Set the memory address of the function foo from the library to our
        // foo.
        foo = reinterpret_cast<void (*)()>(LoadSymbol(handle, "foo"));
        // Call foo
        foo();

        // Read the data from the global variable bar in the test library
        int bar = *reinterpret_cast<int*>(LoadSymbol(handle, "bar"));
        std::cout << "bar == " << bar << std::endl;

        // Wait for input to give us a chance to recompile the library
        std::cout << "Make some changes, recompile, and press enter."
                  << std::flush;
        while (std::cin.get() != '\n') {
        }

        // Reload the library!
        Reload(handle, g_libPath);

        // We need to refetch the symbol because it's location in memory may
        // have changed
        foo = reinterpret_cast<void (*)()>(LoadSymbol(handle, "foo"));
        foo();

        // Do the same for bar
        bar = *reinterpret_cast<int*>(LoadSymbol(handle, "bar"));
        std::cout << "bar == " << bar << std::endl;
    } else {
        PrintError();
    }
    return 0;
}