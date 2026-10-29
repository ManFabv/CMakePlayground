# the CMake version this project is written for: it also selects the policies (theory, part 11.2)
cmake_minimum_required(VERSION 3.25)

# project() detects the C++ compiler: from here on CMAKE_CXX_COMPILER_ID exists
project(CMakePlayground VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

option(PLAYGROUND_ENABLE_LOGS "Enable logging" ON)

# we include the PlaygroundOptions.cmake file to use the playground_set_compile_options() function
include(${CMAKE_CURRENT_SOURCE_DIR}/cmake/PlaygroundOptions.cmake)

# we create an INTERFACE library called Containers, which will contain the ArrayCount.hpp file
add_library(Containers INTERFACE)
# we set the include directories for the Containers target to be the current source directory, 
# so that the ArrayCount.hpp file can be found by the compiler
target_include_directories(Containers INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/Containers)

# we create a static library called Core, which will contain the Math.cpp and Math.hpp files
add_library(Core STATIC Math.cpp Math.hpp)

# we set the include directories for the Core target to be the current source directory, so that the Math.hpp 
# file can be found by the compiler
target_include_directories(Core PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
# we link the Containers library to the Core library, so that the Core can use the ArrayCount() function
target_link_libraries(Core PUBLIC Containers)
# we define a preprocessor macro called CORE_HAS_FAST_MATH for the Core target, 
# which can be used in the code to enable fast math optimizations
target_compile_definitions(Core PRIVATE CORE_HAS_FAST_MATH)
# we set the compile options for the Core target using the playground_set_compile_options() function
playground_set_compile_options(Core)

# we create an executable called App, which will contain the main.cpp file
add_executable(App main.cpp)

# we link the Core library to the App executable, so that the App can use the Math functions
target_link_libraries(App PRIVATE Core)
# we set the compile options for the App target using the playground_set_compile_options() function
playground_set_compile_options(App)