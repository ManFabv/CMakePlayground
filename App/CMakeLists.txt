# we create an executable target called App, which will be built from the main.cpp source file
add_executable(App main.cpp)
# we link the App executable to the Core and Platform libraries, so it can use the Core and Platform libraries' code and include directories.
target_link_libraries(App PRIVATE Playground::Core Playground::Platform)
# we set the compile options for the App executable using the playground_set_compile_options() function defined in cmake/PlaygroundOptions.cmake
playground_set_compile_options(App)

# PLAYGROUND_ENABLE_LOGS was defined in the root: a subdirectory sees a COPY of its parent's variables
if(PLAYGROUND_ENABLE_LOGS)
    target_compile_definitions(App PRIVATE PLAYGROUND_ENABLE_LOGS)
endif()