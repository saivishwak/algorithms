# CMakeLists.txt

cmake_minimum_required(VERSION 3.10)

project(DataStrcutresProject)

# Add the executable
# Sorting Algorithms
add_executable(bubble ./sorting/bubble.c)
add_executable(selection ./sorting/selection.c)
add_executable(insertion ./sorting/insertion.c)
add_executable(merge ./sorting/merge.c)

# Set the output directory for the executable
set_target_properties(bubble PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/dist
)
set_target_properties(selection PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/dist
)
set_target_properties(insertion PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/dist
)
set_target_properties(merge PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/dist
)
