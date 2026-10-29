# we add Core as a STATIC library, which is a library that compiles source code into an object file that can be linked to other targets
add_library(Core STATIC Math.cpp Math.hpp)
# we add an alias for the Core library, so that other targets can link to it using the Playground::Core name
add_library(Playground::Core ALIAS Core)
# we add the include directories for the Core library, so that other targets that link to it can find the header files
target_include_directories(Core PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
# we link the Core library to the Containers library, so it can use the Containers library's code and include directories. 
# The PUBLIC keyword means that the include directories of Containers will also be added to the include directories 
# of any target that links to Core.
target_link_libraries(Core PUBLIC Playground::Containers)
# we set the compile options for the Core library using the playground_set_compile_options() function defined in cmake/PlaygroundOptions.cmake
playground_set_compile_options(Core)