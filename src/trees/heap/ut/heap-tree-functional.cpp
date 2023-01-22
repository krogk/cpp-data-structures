#include <gtest/gtest.h>
#include "heap-tree.h"

//TODO: Add tests for max_heap

TEST(HeapTest, Size) {
    Heap<int> min_heap;
    min_heap.push(5);
    min_heap.push(3);
    min_heap.push(7);
    min_heap.push(1);
    EXPECT_EQ(min_heap.size(), 4);
}

TEST(HeapTest, Empty) {
    Heap<int> min_heap;
    EXPECT_TRUE(min_heap.empty());
    min_heap.push(5);
    EXPECT_FALSE(min_heap.empty());
}

TEST(HeapTest, Top) {
    Heap<int> min_heap;
    min_heap.push(5);
    min_heap.push(3);
    min_heap.push(7);
    min_heap.push(1);
    EXPECT_EQ(min_heap.top(), 1);
}

TEST(HeapTest, Clear) {
    Heap<int> min_heap;
    min_heap.push(5);
    min_heap.push(3);
    min_heap.push(7);
    min_heap.push(1);
    min_heap.clear();
    EXPECT_EQ(min_heap.size(), 0);
}

TEST(HeapTest, BuildHeap) {
    std::vector<int> arr = {5, 3, 7, 1};
    Heap<int> min_heap;
    min_heap.build_heap(arr);
    EXPECT_EQ(min_heap.top(), 1);
}

TEST(HeapTest, Sort) {
    Heap<int> min_heap;
    min_heap.push(5);
    min_heap.push(3);
    min_heap.push(7);
    min_heap.push(1);
    min_heap.sort();
    std::sort(min_heap.data.begin(), min_heap.data.end());
    std::vector<int> expected = {1, 3, 5, 7};
    EXPECT_EQ(min_heap.data, expected);
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}