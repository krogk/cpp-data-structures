# Locate GTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})
 
# Add unit test executable
add_executable(ut_dense_hashmap dense-hashmap-functional.cpp)
# Link ut with required libraries
target_link_libraries(ut_dense_hashmap 
                    ${GTEST_LIBRARIES}
                    dense_hashmap_lib
                    --coverage)