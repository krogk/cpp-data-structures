/**
 * @brief Binary Tree
 * Each node in a binary tree has at most two children, a left child and a right child.
 * 
 * The BinaryTree class is used to manage the overall tree structure. The tree starts out 
 * with a null root pointer, which is initially set to nullptr. The class includes methods 
 * for inserting new nodes into the tree, searching for a specific value, and printing the 
 * tree's elements in order.
 * 
 * The insert() method is used to add new nodes to the tree. If the tree is currently empty, 
 * the new node becomes the root. If the tree is not empty, the insertHelper() method is 
 * called, which recursively traverses the tree to find the correct position for the new node. 
 * The new node is added as a left child if the data is less than or equal to the current node's 
 * data, and as a right child if the data is greater than the current node's data.
 * 
 * The search() method is used to determine if a specific value is present in the tree. It calls 
 * the search_helper() method, which recursively traverses the tree, comparing the data of each 
 * node to the search value. If a node with matching data is found, the method returns true. 
 * If the entire tree is traversed without finding a match, the method returns false.
 * 
 * The print_in_order() method is used to print the tree's elements in order. It calls the
 * print_in_order_helper() method, which recursively traverses the tree in-order 
 * (left subtree, current node, right subtree) and prints the data of each node as it is visited.
 */

#include <iostream>
#include <memory>

/**
 * @brief Node class
 * Represents a single node in the tree.
 * Each node has a T data value, 
 * as well as pointers to its left and right children.
 * 
 * @tparam T 
 */
template <typename T>
class Node {
public:
    // Data
    T data;
    // Children
    std::unique_ptr<Node<T>> left;
    std::unique_ptr<Node<T>> right;
    // ctor
    Node(T data) : data(data) {}
};


template <typename T>
class BinaryTree {
public:

    // ctor 
    BinaryTree() {}

    void insert(T data) {
        // Insert root if tree is empty
        if (!root) {
            root = std::make_unique<Node<T>>(data);
        } 
        // Otherwise use insert helper
        else {
            insert_helper(root.get(), data);
        }
    }

    void insert_helper(Node<T>* current, T data) {
        // If data's (to be inserted) value is less or equal to the 
        // current node
        if (data <= current->data) {
            // Insert if left child is empty
            if (!current->left) {
                current->left = std::make_unique<Node<T>>(data);
            } 
            // Otherwise 
            else {
                // Repeat the process in the right child node
                insert_helper(current->left.get(), data); // recursion
            }
        } 
        else {
            // Insert if right child is empty
            if(!current->right) {
                current->right = std::make_unique<Node<T>>(data);
            }
            // Otherwise 
            else {
                // Repeat the process in the right child node
                insert_helper(current->right.get(), data); // recursion
            }
        }
    }

    bool search(T data) {
        return search_helper(root.get(), data);
    }

    bool search_helper(Node<T>* current, T data) {
        // Return if tree is empty 
        if (!current) {
            return false;
        } 
        // Check if the node contains  data searched for
        else if (current->data == data) {
            // return on successful match 
            return true;
        } 
        // Otherwise 
        else {
            // Check if the value is less than or equal to target
            // as to step to 
            if (data <= current->data) {
                // the left
                return search_helper(current->left.get(), data);
            } 
            // or step to 
            else {
                // the right
                return search_helper(current->right.get(), data);
            }
        }
    }

    void print_in_order() {
        print_in_order_helper(root.get());
    }

    void print_in_order_helper(Node<T>* current) {
        // Return if tree is empty
        if(!current) {
            return;
        }
        print_in_order_helper(current->left.get());
        std::cout << current->data << " ";
        print_in_order_helper(current->right.get());
    }

    void print_pre_order() {
        print_pre_order_helper(root.get());
    }

    void print_pre_order_helper(Node<T>* current) {
      // Return if tree is empty
      if(!current) {
          return;
      }
      std::cout << current->data << " ";
      print_pre_order_helper(current->left.get());
      print_pre_order_helper(current->right.get());
    }

    void print_post_order() {
        print_post_order_helper(root.get());
    }

    void print_post_order_helper(Node<T>* current) {
      // Return if tree is empty
      if(!current) {
          return;
      }
      print_post_order_helper(current->left.get());
      print_post_order_helper(current->right.get());
      std::cout << current->data << " ";
    }    

    // Root node
    std::unique_ptr<Node<T>> root;
};