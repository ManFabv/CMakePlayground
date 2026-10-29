# we create a static library target called Platform, which will be built from the Platform.hpp header file 
# and the platform-specific source files (Platform_Win32.cpp or Platform_Posix.cpp)
add_library(Platform STATIC Platform.hpp)
# we add an alias for the Platform library, so that other targets can link to it using the Playground::Platform name
add_library(Playground::Platform ALIAS Platform)

# we check if we are on Windows or not, and we add the appropriate source file to the Platform library
if(WIN32)
    # we add the Platform_Win32.cpp source file to the Platform library, which implements the platform-specific functions for Windows
    target_sources(Platform PRIVATE Platform_Win32.cpp)
    # PRIVATE: only Platform_Win32.cpp includes windows.h
    # we define some macros to reduce the amount of stuff included by windows.h and to avoid conflicts with std::min and std::max
    target_compile_definitions(Platform PRIVATE WIN32_LEAN_AND_MEAN NOMINMAX)
    # we set the platform_backend variable to "Win32" to indicate that we are using the Windows backend
    set(platform_backend "Win32")
else()
    # we add the Platform_Posix.cpp source file to the Platform library, which implements the platform-specific functions for POSIX systems
    # (Linux, macOS, etc.)
    target_sources(Platform PRIVATE Platform_Posix.cpp)
    # we set the platform_backend variable to "Posix" to indicate that we are using the POSIX backend
    set(platform_backend "Posix")
endif()
# we print a message to the console indicating which platform backend we are using
message(STATUS "Platform backend: ${platform_backend}")

# we add the include directories for the Platform library, so that other targets that link to it can find the header files
target_include_directories(Platform PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
# we set the compile options for the Platform library using the playground_set_compile_options() function defined in cmake/PlaygroundOptions.cmake
playground_set_compile_options(Platform)