# Data Structures implemented in C++ 

[![ci](https://github.com/krogk/cpp-data-structures/actions/workflows/ci.yml/badge.svg)](https://github.com/krogk/cpp-data-structures/actions/workflows/ci.yml)

## About

A definition a data structure: "Data structure is a data organization, management, and storage format that is usually chosen for efficient access to data."

Most of the data structures are implemented by the std(standard library), however there are few data structures that are not, these structures tend to be abstract and suited for some specific set of problems. The following sections explains the data structures implemented in c++, it can be skipped, data structures implemented by source code in this repository are specified in the section 'Which data structures aren't implemented by the C++?'. 

### Data structures in C++ & C++ std

C++ STD(standard library) implements several data structures as containers, the container is defined as "an object used to store other objects and taking care of the management of the memory used by the objects it contains" these implementations have several requirements, and are data type agnostic. Containers are categorized in following fashion:

#### Sequence containers

* [std::array](https://en.cppreference.com/w/cpp/container/array) - Static sized array, allocated on the stack memory
* [std::vector](https://en.cppreference.com/w/cpp/container/vector) - Dynamic sized array, allocated on the heap
* [std::deque](https://en.cppreference.com/w/cpp/container/deque) -  Double ended queue, 
* [std::list](https://en.cppreference.com/w/cpp/container/list) - Provides bidirectional iteration capability while being less space efficient. 
* [std::forward_list](https://en.cppreference.com/w/cpp/container/forward_list) - Provides forward iteration capability while being more space efficient.

#### Associative containers

The std associative containers are:
* [std::set](https://en.cppreference.com/w/cpp/container/set) - Contains a sorted set of unique objects of type Key.
* [std::multiset](https://en.cppreference.com/w/cpp/container/multiset) - Contains a sorted set of objects of type Key. Unlike set, multiple keys with equivalent values are allowed.
* [std::map](https://en.cppreference.com/w/cpp/container/map) - Contains key-value pairs with unique keys.
* [std::multimap](https://en.cppreference.com/w/cpp/container/multimap) Contains key-value pairs with unique keys. while permitting multiple entries with the same key

These containers are further categorized into:
* Ordered associative containers - Containers implementations are based on trees, elements are ordered by the less than operator (<) adding,
deleting, and finding elements run in time complexity of O(log n).
* Unordered associative containers - Containers implementations are based on hash tables, this ensures that adding, deleting and finding elements runs in time complexity of O(1). Unordered container types are prefixed with std::unordered_ i.e. std::unordered_map.
These assos

####  Container adaptors
Container adaptors represent abstract data types.

* std::stack - last in, first out (LIFO)
* std::queue - first in, first out (FIFO)
* std::priority_queue - constant time lookup of the largest (by default) element, at the expense of logarithmic insertion and extraction.

####  Which data structures aren't implemented by the C++?

Hash structures:
* [] Bloom filter
* [x] Dense Hash table/map
* [] Rolling hash
* [x] Trie

Trees:
Although the ordered associative containers are based on tree, there is no template for tree like structures.

Common tree data structures include:
* [x] Binary Tree
* [x] Max Heap
* [x] Min Heap
* [] Abstract syntax tree (AST)

Self-balancing trees:
* [] AVL Tree:
* [] Splay Tree:
* [] B-Tree:
* [] Red-Black Tree:
* [] Scape Goat Tree and Treap:

Graph - A Graph is a non-linear data structure consisting of vertices and edges:
* [] Adjacency list
* [] Adjacency matrix
* [] Graph-structured stack
* [] Hypergraph
* [] Scene graph

## Dependencies

A dockerfile & build script has been provided for your convenience.
Please read the content of the /.devcontainer/dockerfile and build.sh first before executing.

### Minimum: 
* git
* CMake
* Python3
* Conan

### Recommended:
Use dev container manager, docker is required. 

1. Install docker & Setup sudo-less docker
2. Build docker image using container-manager.sh:
```
./container-manager.sh -b
```
3. Run docker image
```
./container-manager.sh -r
```

## Usage

### Building
Invoke build script with -h to determine available build options:
```
./build.sh
```
### Testing
Invoke test script with -a to run all tests, use -h to determine available test options. 

Note: this is the generic test script the author uses across several repositories, executing some options may result in undefined behavior, read the contents of the test script to understand how it works. Use of -a is recommended:
```
./test.sh -a
```