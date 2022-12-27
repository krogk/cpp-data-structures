# Set the name of the library
set(library_name dense_hashmap_lib)

add_library(${library_name} INTERFACE)

# Set the include directories for the library
target_include_directories(${library_name} INTERFACE .)

# Set the include directories for the library
target_include_directories(${library_name} INTERFACE ${CMAKE_CURRENT_LIST_DIR})

# Set the sources for the library to all .h files in the current directory
file(GLOB sources "${CMAKE_CURRENT_LIST_DIR}/*.h")
target_sources(${library_name} INTERFACE ${sources})

# Add unit test
add_subdirectory(ut)