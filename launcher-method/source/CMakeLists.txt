cmake_minimum_required(VERSION 3.27)
project(titanfall2-multiplayer-fix)

set(CMAKE_CXX_STANDARD 17)

if (NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif ()

add_executable(TF2Fix
        main.cpp
        icon.rc
)

# Optimization flags for smaller binary
target_compile_options(TF2Fix PRIVATE -Os)
target_link_options(TF2Fix PRIVATE
        -static
        -s
        -Wl,--gc-sections
)
target_compile_options(TF2Fix PRIVATE -ffunction-sections -fdata-sections)
