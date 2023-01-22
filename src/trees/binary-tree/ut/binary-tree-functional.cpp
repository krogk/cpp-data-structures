#include <gtest/gtest.h>
#include "binary-tree.h"

TEST(BinaryTreeTest, Insert) {
  BinaryTree<int> tree;
  tree.insert(5);
  tree.insert(3);
  tree.insert(7);
  tree.insert(1);
  tree.insert(4);
  tree.insert(6);
  tree.insert(9);

  // Test in-order traversal
  std::stringstream ss;
  std::streambuf* old = std::cout.rdbuf(ss.rdbuf());
  tree.print_in_order();
  std::cout.rdbuf(old);
  std::string expected = "1 3 4 5 6 7 9 ";
  EXPECT_EQ(ss.str(), expected);
}

TEST(BinaryTreeTest, Search) {
  BinaryTree<int> tree;
  tree.insert(5);
  tree.insert(3);
  tree.insert(7);
  tree.insert(1);
  tree.insert(4);
  tree.insert(6);
  tree.insert(9);

  EXPECT_TRUE(tree.search(5));
  EXPECT_TRUE(tree.search(3));
  EXPECT_TRUE(tree.search(7));
  EXPECT_TRUE(tree.search(1));
  EXPECT_TRUE(tree.search(4));
  EXPECT_TRUE(tree.search(6));
  EXPECT_TRUE(tree.search(9));
  EXPECT_FALSE(tree.search(2));
  EXPECT_FALSE(tree.search(8));
  EXPECT_FALSE(tree.search(10));
}

TEST(BinaryTreeTest, Destructor) {
  {
    BinaryTree<int> tree;
    tree.insert(5);
    tree.insert(3);
    tree.insert(7);
    tree.insert(1);
    tree.insert(4);
    tree.insert(6);
    tree.insert(9);
  }
  // Check if memory leak occurs by using valgrind or similar tool
}


int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}