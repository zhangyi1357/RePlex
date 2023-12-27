# this is runtime exeutable for the project with only one cpp file
# create CMakeLists.txt

add_executable(Runtime Main.cpp)

# add dependencies, it depends on RePlex library(header-only)
target_link_libraries(Runtime PUBLIC RePlex)