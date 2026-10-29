# we add Containers as an INTERFACE library, which is a library that does not compile any source code,
# but it can be used to propagate include directories and compile options to other targets that link to it. 
# This is useful for header-only libraries or for libraries that only provide include directories and compile options
add_library(Containers INTERFACE)
# we add an alias for the Containers library, so that other targets can link to it using the Playground::Containers name
add_library(Playground::Containers ALIAS Containers)
# we add the include directories for the Containers library, so that other targets that link to it can find the header files
target_include_directories(Containers INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})