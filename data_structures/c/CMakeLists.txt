# CMakeLists.txt

cmake_minimum_required(VERSION 3.10)

project(DataStrcutresProject)

# Add the executable
add_executable(vec vector_impl.c vector.c)
add_executable(stack stack_impl.c stack.c vector.c)
add_executable(ll linkedlist_impl.c linkedlist.c)
add_executable(map unordered_map_impl.c unordered_map.c)
add_executable(bintree binary_tree_impl.c binary_tree.c vector.c)
add_executable(heap heap_impl.c heap.c vector.c)

# Set the output directory for the executable
set_target_properties(vec PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/dist
)
set_target_properties(stack PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/dist
)
set_target_properties(ll PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/dist
)
set_target_properties(map PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/dist
)
set_target_properties(bintree PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/dist
)

set_target_properties(heap PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/dist
)
