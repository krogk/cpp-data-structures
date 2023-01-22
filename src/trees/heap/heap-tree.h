/**
 * @brief Heap Tree
 * 
 */

// std::less<T>  - Min Heap
// std::greater<T> - Max Heap
/* 
    // Custom Comparator Blueprint
    struct MyCompare {
    bool operator()(const int& a, const int& b) const {
        return a > b;
    }
    };
*/
template <typename T, typename Compare = std::less<T>>
class Heap {
 public:
  std::vector<T> data;
  Compare comp;

  Heap() {
    comp = Compare();
  }

    size_t size() {
    return data.size();
  }

    bool empty() {
    return data.empty();
  }

    T& top() {
    return data[0];
  }
  const T& top() const {
    return data[0];
  }

    void clear() {
        data.clear();
  }

  void build_heap(std::vector<T> &arr) {
    data = arr;
    int n = data.size();
    for (int i = n / 2 - 1; i >= 0; i--) {
      heapify(i);
    }
  }

  /**
   * @brief 
   * 
   * Used to maintain the heap property  when inserting new elements 
   * or removing the top element from the heap. It takes an index as a 
   * parameter, and compares the element at that  index with its children.
   * If one of the children is smaller (for min heap) or greater (for max heap)
   * than the element at the given index, the function swaps them and calls heapify()
   * recursively on the child. This process is  repeated until the element at 
   * the given index is in its correct position in the heap.
   * 
   * @param i 
   */
  void heapify(int i) {
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    int smallest = i;
    if(left < data.size() && comp(data[left], data[smallest]))
      smallest = left;
    if(right < data.size() && comp(data[right], data[smallest]))
      smallest = right;
    if(smallest != i) {
      std::swap(data[i], data[smallest]);
      heapify(smallest);
    }
  }


  /**
   * @brief 
   * 
   * Used to sort the elements in the heap.
   * It takes two parameters, an index and an integer which represents the 
   * size of the heap, it then compares the element at that index with its 
   * children and, if one of the children is smaller (for min heap) or 
   * greater (for max heap) than the element at the given index, the 
   * function swaps them and calls heapify() recursively on the child.
   * This process is repeated until the element at the given index is in 
   * its correct position in the heap, but this time it will stop when it 
   * reaches the size of the heap.
   * 
   * @param i 
   * @param n 
   */
  void heapify(int i, int n) {
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    int smallest = i;
    if (left < n && comp(data[left], data[smallest]))
      smallest = left;
    if (right < n && comp(data[right], data[smallest]))
      smallest = right;
    if (smallest != i) {
      std::swap(data[i], data[smallest]);
      heapify(smallest, n);
    }
  }

  /**
   * @brief 
   * It's worth noting that the sort function only sorts the elements of 
   * the heap, it doesn't change the heap data structure itself, this 
   * means that the heap property is not maintained after sorting the elements.
   * 
   * It's also important to note that sorting a heap using this method 
   * has a time complexity of O(n log n), where n is the number of 
   * elements in the heap.
   * 
   * The implications of this is that after the sort function has been called, 
   * the heap will no longer have the heap property. This means that the elements 
   * of the heap are no longer organized in a way that guarantees that the parent 
   * node is smaller/greater than its children.
   * 
   * This means that the heap data structure will no longer be useful for 
   * operations that rely on the heap property, such as extracting the 
   * minimum/maximum element in O(1) time.
   * 
   * This also means that if you want to continue using the heap for these 
   * operations, you will need to rebuild the heap by calling the build_heap() 
   * function again, this will restore the heap property and allow you to 
   * continue using the heap as a priority queue.
   * 
   * It's important to note that the sort function is mainly used when you 
   * want to sort the elements of the heap and you no longer need to access 
   * the elements in a specific order, but if you want to maintain the heap 
   * property, you need to use the Heap data structure methods like push(),pop() and build_heap().
   * 
   * It's also worth noting that if you need to maintain the heap property 
   * after sorting the elements, you can use a different data structure that 
   * is both a heap and a sorted data structure, such as a balanced binary search tree.
   * 
   */
  void sort() {
    int n = data.size();
    for (int i = n - 1; i >= 0; i--) {
      std::swap(data[0], data[i]);
      heapify(0, i);
    }
  }

  void push(T value) {
    data.push_back(value);
    int i = data.size() - 1;
    int parent = (i - 1) / 2;
    while (i > 0 && comp(data[i], data[parent])) {
      std::swap(data[i], data[parent]);
      i = parent;
      parent = (i - 1) / 2;
    }
  }

  T pop() {
    T result = data[0];
    data[0] = data.back();
    data.pop_back();
    int i = 0;
    while (true) {
      int left = 2 * i + 1;
      int right = 2 * i + 2;
      if (left >= data.size()) {
        break;
      }
      int smallest = i;
      if (comp(data[left], data[smallest])) {
        smallest = left;
      }
      if (right < data.size() && comp(data[right], data[smallest])) {
        smallest = right;
      }
      if (smallest == i) {
        break;
      }
      std::swap(data[i], data[smallest]);
      i = smallest;
    }
    return result;
  }
};