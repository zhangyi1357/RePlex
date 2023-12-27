# this is a header-only library with only one header file
# write the CMakeLists.txt file for the library

# create a target for the library
add_library(${PROJECT_NAME} INTERFACE)

# add the include directory to the target
target_include_directories(${PROJECT_NAME} INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})

# add the required C++ standard to the target
target_compile_features(${PROJECT_NAME} INTERFACE cxx_std_17)

# add the required compiler flags to the target
target_compile_options(${PROJECT_NAME} INTERFACE -Wall -Wextra -Wpedantic -Werror)