function(playground_set_compile_options target_name)
    # target_name is a local variable holding the string "App", "Core", ...
    if(NOT TARGET ${target_name})
        message(FATAL_ERROR "playground_set_compile_options: '${target_name}' is not a target")
    endif()

    # MSVC is true for cl.exe and clang-cl: it asks which flag SYNTAX the compiler understands
    if(MSVC)
        target_compile_options(${target_name} PRIVATE /W4 /EHs-c- /GR-)
        # MSVC's own STL also needs to know exceptions are off
        target_compile_definitions(${target_name} PRIVATE _HAS_EXCEPTIONS=0)
    else()
        target_compile_options(${target_name} PRIVATE -Wall -Wextra -fno-exceptions -fno-rtti)
    endif()
endfunction()