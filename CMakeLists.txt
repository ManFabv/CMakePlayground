# the CMake version this project is written for: it also selects the policies (theory, part 11.2)
cmake_minimum_required(VERSION 3.25)

# project() detects the C++ compiler: from here on CMAKE_CXX_COMPILER_ID exists
project(CMakePlayground VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# we save the cache defined variable to enable logs in the app
option(PLAYGROUND_ENABLE_LOGS "Print extra messages from the app" ON)

# include the cmake/PlaygroundOptions.cmake file, which defines the playground_set_compile_options() function
include(${CMAKE_CURRENT_SOURCE_DIR}/cmake/PlaygroundOptions.cmake)

# we add the subdirectories for containers which is a library with its own CMakeLists.txt
add_subdirectory(Containers)
# we add the subdirectories for Core which is a library with its own CMakeLists.txt
add_subdirectory(Core)
# we add the subdirectories for App, which is an executable with its own CMakeLists.txt
add_subdirectory(App)