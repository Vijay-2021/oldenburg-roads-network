cmake_minimum_required(VERSION 3.10)

set(CMAKE_C_COMPILER "/usr/bin/clang")
set(CMAKE_CXX_COMPILER "/usr/bin/clang++")
set(CMAKE_LINKER "/usr/bin/clang++")

project(oldenburg_roads)

# Specify C++ Standard.
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Specify warnings for all builds.
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pedantic -Wall -Werror -Wfatal-errors -Wextra -Wno-unused-parameter -Wno-unused-variable -Wno-unused-function")

# Specify debug symbols and no optimizations for Debug builds.
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -D_GLIBCXX_DEBUG -O0 -gdwarf-4")

find_package(Catch2 REQUIRED)

list(APPEND CMAKE_MODULE_PATH ${catch2_SOURCE_DIR}/extras)

add_executable(main ../entry/main.cpp)

target_include_directories(main
    PUBLIC ${PROJECT_SOURCE_DIR}/lib
)

target_include_directories(main
    PUBLIC ${PROJECT_SOURCE_DIR}/includes
)

file(GLOB_RECURSE tests CONFIGURE_DEPENDS ${CMAKE_SOURCE_DIR}/tests/*.cpp)
add_executable(tests ${tests})

target_include_directories(tests
    PUBLIC ${PROJECT_SOURCE_DIR}/includes
)

target_include_directories(tests
    PUBLIC ${PROJECT_SOURCE_DIR}/lib
)

list(APPEND CMAKE_MODULE_PATH ${catch2_SOURCE_DIR}/extras)
add_subdirectory(${PROJECT_SOURCE_DIR}/includes)
add_subdirectory(${PROJECT_SOURCE_DIR}/lib)
target_link_libraries(tests PRIVATE Catch2::Catch2WithMain includes lib)
target_link_libraries(main PRIVATE includes lib)
