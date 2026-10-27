cmake_minimum_required(VERSION 3.30)
project(hello_world_better LANGUAGES C)

# Target C23
set(CMAKE_C_STANDARD 23)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

# Target C++23
#set(CMAKE_CXX_STANDARD 23)
#set(CMAKE_CXX_STANDARD_REQUIRED ON)
#set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(${PROJECT_NAME}
    main.c
)

# --- Strict Compiler Warnings ---
if(MSVC)
    # MSVC warning levels (Level 4 is strict, /WX treats warnings as errors)
    target_compile_options(${PROJECT_NAME} PRIVATE 
        /W4 
        /WX
    )
else()
    # GCC and Clang strict warnings
    target_compile_options(${PROJECT_NAME} PRIVATE 
        -Wall 
        -Wextra 
        -Wpedantic 
        -Werror
        -Wshadow
        -Wformat=2
    )
endif()
