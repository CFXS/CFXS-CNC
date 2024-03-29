set(CMAKE_UNITY_BUILD true)
set(CMAKE_UNITY_BUILD_BATCH_SIZE 16)

file(GLOB_RECURSE sources CONFIGURE_DEPENDS
  "${CMAKE_CURRENT_SOURCE_DIR}/src/*.c"
  "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp"
)

file(GLOB_RECURSE headers CONFIGURE_DEPENDS
  "${CMAKE_CURRENT_SOURCE_DIR}/include/*.h"
  "${CMAKE_CURRENT_SOURCE_DIR}/include/*.hpp"
)

set_source_files_properties(${sources} PROPERTIES LANGUAGE CXX)
set_source_files_properties(${headers} PROPERTIES LANGUAGE CXX)

add_library(CFXS_CNC ${sources})
target_include_directories(CFXS_CNC PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_include_directories(CFXS_CNC PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src)

target_precompile_headers(
  CFXS_CNC
  PUBLIC
  <stddef.h>
  <stdint.h>
  <stdbool.h>
  <string.h>
)