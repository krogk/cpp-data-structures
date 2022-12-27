#include <gtest/gtest.h>
#include "trie.h"

TEST(TrieTest, InsertAndContains)
{
    Trie trie;
    trie.insert("hello");
    trie.insert("world");
    trie.insert("hi");
    trie.insert("there");

    EXPECT_TRUE(trie.contains("hello"));
    EXPECT_TRUE(trie.contains("world"));
    EXPECT_TRUE(trie.contains("hi"));
    EXPECT_TRUE(trie.contains("there"));
    EXPECT_FALSE(trie.contains("he"));
    EXPECT_FALSE(trie.contains("hell"));
    EXPECT_FALSE(trie.contains("helloworld"));
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}