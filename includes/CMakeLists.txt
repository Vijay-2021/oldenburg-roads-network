project (includes)

file(GLOB_RECURSE includes_src CONFIGURE_DEPENDS ${CMAKE_SOURCE_DIR}/includes/*.h ${CMAKE_SOURCE_DIR}/includes/*.cpp ${CMAKE_SOURCE_DIR}/includes/*.hpp)
# Add a includesrary with the above sources
add_library(${PROJECT_NAME} SHARED ${includes_src})
