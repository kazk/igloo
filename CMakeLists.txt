cmake_minimum_required(VERSION 3.22)

project(igloo)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ./bin)

if (MSVC)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W4 /MP ")
else()
  # Assume GCC-style arguments
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wfatal-errors -Wall -W -Werror -Wfloat-equal -Wundef -Wendif-labels -Wshadow -pedantic-errors")
endif()

# Define the library
add_library(igloo INTERFACE)
target_include_directories(igloo INTERFACE "${PROJECT_SOURCE_DIR}")

# Test Code
FILE(GLOB IglooTestSourceFiles tests/*.cpp tests/**/*.cpp)
add_executable(igloo-tests ${IglooTestSourceFiles})
target_include_directories(igloo-tests PRIVATE "${PROJECT_SOURCE_DIR}")

add_custom_command(TARGET igloo-tests
                   POST_BUILD
                   COMMAND igloo-tests
                   WORKING_DIRECTORY ./bin)

install(DIRECTORY ${PROJECT_SOURCE_DIR}/igloo
        DESTINATION include/
        FILES_MATCHING PATTERN "*.h")
