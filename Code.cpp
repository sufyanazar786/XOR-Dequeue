// DEQUE USING XOR LINKED LIST

#include <bits/stdc++.h>
using namespace std;

// Node structure
struct Node {
  int data;
  Node* nxt;
};

// Global variables for head and tail of the deque
Node* head = NULL;
Node* tail = NULL;
int size = 0;

// Function to create a new node
Node* create(int e) {
  Node* temp = (Node*)malloc(sizeof(Node));
  temp->data = e;
  temp->nxt = NULL;
  return temp;
}

// XOR function to calculate XOR of two node pointers
Node* XOR(Node* a, Node* b) {
  return (Node*)((uintptr_t)(a) ^ (uintptr_t)(b));
}

// Function to push element at the front
void push_front(int k) {
  Node* t = create(k);
  Node* p = NULL;
  if (head == NULL) { // If deque is empty
    t->nxt = XOR(p, head);
    head = t;
    tail = t;
  } else { // If deque is not empty
    t->nxt = XOR(p, head);
    head->nxt = XOR(t, head->nxt);
    head = t;
  }
  size++;
}

// Function to push element at the back
void push_back(int k) {
  Node* t = create(k);
  Node* p = NULL;
  if (head == NULL) { // If deque is empty
    t->nxt = XOR(p, tail);
    head = t;
    tail = t;
  } else { // If deque is not empty
    t->nxt = XOR(tail, p);
    tail->nxt = XOR(t, tail->nxt);
    tail = t;
  }
  size++;
}

// Function to pop element from the front
void pop_front() {
  if (head == NULL) { // If deque is empty
    cout << "EMPTY\n";
  } else {
    Node* p = NULL;
    Node* t = XOR(head->nxt, p);
    if (t == NULL) { // If there is only one element
      free(head);
      head = NULL;
      tail = NULL;
    } else { // If there are more elements
      t->nxt = XOR(head, t->nxt);
      t->nxt = XOR(p, t->nxt);
      free(head);
      head = t;
    }
    size--;
    cout << "Popped\n";
  }
}

// Function to pop element from the back
void pop_back() {
  if (head == NULL) { // If deque is empty
    cout << "EMPTY\n";
  } else {
    Node* p = NULL;
    Node* t = XOR(tail->nxt, p);
    if (t == NULL) { // If there is only one element
      free(tail);
      head = NULL;
      tail = NULL;
    } else { // If there are more elements
      t->nxt = XOR(tail, t->nxt);
      t->nxt = XOR(p, t->nxt);
      free(tail);
      tail = t;
    }
    size--;
    cout << "Popped\n";
  }
}

// Function to get the last element
void get_back() {
  if (head == NULL) // If deque is empty
    cout << "EMPTY\n";
  else
    cout << tail->data << "\n";
}

// Function to get the first element
void get_front() {
  if (head == NULL) // If deque is empty
    cout << "EMPTY\n";
  else
    cout << head->data << "\n";
}

// Function to get the second last element
void get_2nd_back() {
  if (head == NULL) { // If deque is empty
    cout << "EMPTY\n";
  } else if (head == tail) { // If there is only one element
    cout << -1 << "\n";
  } else {
    Node* p = NULL;
    Node* t = XOR(tail->nxt, p);
    cout << t->data << "\n";
  }
}

// Function to get the second first element
void get_2nd_front() {
  if (head == NULL) { // If deque is empty
    cout << "EMPTY\n";
  } else if (head == tail) { // If there is only one element
    cout << -1 << "\n";
  } else {
    Node* p = NULL;
    Node* t = XOR(head->nxt, p);
    cout << t->data << "\n";
  }
}

// Function to get the size of the deque
void get_size() {
  cout << size << "\n";
}

// Function to check if the deque is empty
bool isempty() {
  return head == NULL;
}

// Function to print the deque
void printDeque() {
  Node* prev = NULL;
  Node* curr = head;
  while (curr != NULL) { // Traverse the deque and print each element
    cout << curr->data << " ";
    Node* t = curr;
    curr = XOR(curr->nxt, prev);
    prev = t;
  }
  cout << "\n";
}

int main() {
  int k;
  cout << "1: Push_back\n2:Push_front\n3:Pop_back\n4:Pop_front\n";
  cout << "5:get_back\n6:get_front\n7:get_2nd_back\n";
  cout << "8:get_2nd_front\n9:Size\n10:Empty\n";
  while (1) {
    int a;
    cout << "Enter option: ";
    cin >> k;
    switch (k) {
      case 1:
        cout << "Enter the element: ";
        cin >> a;
        push_back(a);
        break;
      case 2:
        cout << "Enter the element: ";
        cin >> a;
        push_front(a);
        break;
      case 3:
        pop_back();
        break;
      case 4:
        pop_front();
        break;
      case 5:
        get_back();
        break;
      case 6:
        get_front();
        break;
      case 7:
        get_2nd_back();
        break;
      case 8:
        get_2nd_front();
        break;
      case 9:
        get_size();
        break;
      case 10:
        cout << isempty() << "\n";
        break;
    }
    int opt;
    cout << "To continue type:\n1: Yes\n2: No\n";
    cin >> opt;
    if (opt == 2)
      break;
  }
  printDeque();
  return 0;
}
