# this is a shared library with one header file and one cpp file
# write the CMakeLists.txt file for the library

add_library(Test SHARED Test.cpp Test.h)

# add deps RePlex
target_link_libraries(Test PUBLIC RePlex)

target_include_directories(Test PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
