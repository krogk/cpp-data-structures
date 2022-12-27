# Locate GTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})
 
# Add unit test executable
add_executable(ut_trie trie-functional.cpp)
# Link ut with required libraries
target_link_libraries(ut_trie 
                    ${GTEST_LIBRARIES}
                    trie_lib
                    --coverage)