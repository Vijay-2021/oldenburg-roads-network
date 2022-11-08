project (lib)

file(GLOB_RECURSE lib_src CONFIGURE_DEPENDS ${CMAKE_SOURCE_DIR}/lib/*.cpp ${CMAKE_SOURCE_DIR}/lib/*.hpp)
# Add a library with the above sources
add_library(${PROJECT_NAME} ${lib_src})
