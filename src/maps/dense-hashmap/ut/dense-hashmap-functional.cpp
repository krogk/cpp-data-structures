#include <gtest/gtest.h>
#include "dense-hashmap.h"

TEST(DenseHashMapTest, InsertAndFind)
{
    DenseHashMap<int, std::string> map;

    map.insert(1, "one");
    map.insert(2, "two");
    map.insert(3, "three");

    EXPECT_EQ(*map.find(1), "one");
    EXPECT_EQ(*map.find(2), "two");
    EXPECT_EQ(*map.find(3), "three");
    EXPECT_EQ(map.find(4), nullptr);
}

TEST(DenseHashMapTest, InsertAndOverwrite)
{
    DenseHashMap<int, std::string> map;

    map.insert(1, "one");
    map.insert(2, "two");
    map.insert(3, "three");
    map.insert(2, "TWO");

    EXPECT_EQ(*map.find(1), "one");
    EXPECT_EQ(*map.find(2), "TWO");
    EXPECT_EQ(*map.find(3), "three");
    EXPECT_EQ(map.find(4), nullptr);
}


int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}