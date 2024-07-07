Overview
This project demonstrates the implementation of a memory-efficient Dequeue (Double-Ended Queue) using an XOR linked list in C++. 
An XOR linked list is a memory-optimized version of a doubly linked list, where each node stores the XOR of the addresses of the previous and next nodes. 
This approach significantly reduces memory usage while maintaining O(1) time complexity for insertion and deletion operations at both ends of the Dequeue.

Key Features
  Memory Efficiency: Utilizes XOR operations to store a single pointer in each node, reducing the overall memory footprint.
  O(1) Operations: Ensures constant time complexity for insertion and deletion at both the front and back of the Dequeue.
  Comprehensive Functionality: Supports a range of operations including insertion, deletion, and retrieval of elements from both ends of the Dequeue.

Implementation Details
  Data Structures
  Node: Represents an element in the Dequeue with data and a single XOR-ed pointer to manage both previous and next node addresses.
  Deque: Manages the head and tail pointers, along with the size of the Dequeue, and provides methods for various operations.

Operations:
  
  Insertion
    push_front(int k): Inserts an element at the front of the Dequeue.
    push_back(int k): Inserts an element at the back of the Dequeue.
  
  Deletion
    pop_front(): Removes an element from the front of the Dequeue.
    pop_back(): Removes an element from the back of the Dequeue.
  
  Retrieval
    get_front(): Retrieves the element at the front of the Dequeue.
    get_back(): Retrieves the element at the back of the Dequeue.
    get_2nd_front(): Retrieves the second element from the front of the Dequeue.
    get_2nd_back(): Retrieves the second element from the back of the Dequeue.
  
  Utility
    get_size(): Returns the current size of the Dequeue.
    isempty(): Checks if the Dequeue is empty.
    printDeque(): Prints all elements in the Dequeue.
    

Skills and Technologies Used

  Data Structures: XOR Linked List, Dequeue
  Programming Languages: C++
  Algorithm Design: Memory optimization, O(1) operations
  Problem Solving: Efficient data manipulation techniques
