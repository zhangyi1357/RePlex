#pragma once
#include <RePlex.h>

#include <array>

extern "C" {
void foo();
}

extern std::array<const char*, 2> g_exports;

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
    virtual const char* GetPath() const override { return "libTest.so"; }

    virtual std::array<const char*, g_exports.size()>& GetSymbolNames()
        const override {
        return g_exports;
    }
};