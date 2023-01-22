# Locate GTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})
 
# Set ut name
set(ut_name ut_binary_tree)
 
# Set the sources for the ut target to all .cpp files in the current directory
file(GLOB sources "${CMAKE_CURRENT_LIST_DIR}/*.cpp")

# Add unit test executable
add_executable(${ut_name} ${sources})

# Link ut with required libraries
target_link_libraries(${ut_name} 
                    ${GTEST_LIBRARIES}
                    binary_tree_lib
                    --coverage)