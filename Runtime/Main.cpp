#include <RePlex.h>

#include <iostream>

std::array<const char*, 2> g_exports = {"foo", "bar"};

class TestModule : public RePlexModule<TestModule, g_exports.size()> {
   public:
    static void Foo() {
        // Execute might throw, but we don't bother catching the exception here
        // for brevity
        GetInstance().Execute<void>("foo");
    }

    static int GetBar() {
        // decltype is a relatively new operator. decltype(bar) resolves to int
        // Note that this function does not protect against retrieving nullptr
        return *GetInstance().GetVar<int>("bar");
    }

   protected:
    virtual const char* GetPath() const override { return "libRePlexTest.so"; }

    virtual std::array<const char*, g_exports.size()>& GetSymbolNames()
        const override {
        return g_exports;
    }
};

int main() {
    TestModule::LoadLibrary();
    TestModule::Foo();
    std::cout << "bar == " << TestModule::GetBar() << std::endl;

    std::cout << "Make some changes, recompile, and press enter." << std::flush;
    while (std::cin.get() != '\n') {
    }

    TestModule::ReloadLibrary();
    TestModule::Foo();
    std::cout << "bar == " << TestModule::GetBar() << std::endl;
    return 0;
}