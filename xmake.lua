set_languages("c99", "c++14")

add_rules("plugin.compile_commands.autoupdate", {outputdir = "build"})
add_rules("mode.debug", "mode.release")

target("RePlex")
    set_kind("headeronly")
    add_includedirs("RePlex", {interface = true})

target("RePlexTest")
    set_kind("shared")
    add_files("Test/Test.cpp")
    add_includedirs("Test", {interface = true})
    add_deps("RePlex")

target("RePlexRuntime")
    set_kind("binary")
    add_files("Runtime/Main.cpp")
    add_deps("RePlexTest")
