#include <iostream>
#include <cstdlib>

using namespace std;

#define SIZE = 10

class Stack {
  int *arr;
  int top;
  int capacity;
 public:
  Stack(int size = SIZE);
  ~Stack();

  void push(int);
  int pop();
  int peek();

  int size();
  bool isEmpty();
  bool isFull();
};

Stack::Stack(int size) {
  arr = new int[size];
  capacity = size;
  top = -1;
}

Stack::~Stack() {
  delete[] arr;
}

void Stack::push(int x) {
  if (isFull()) {
    cout << "Overflow\nProgram Terminated\n";
    exit(EXIT_FAILURE);
  }
  cout << "Inserting " << x << "\n";
  arr[++top] = x;
}

int Stack::pop() {
  if (isEmpty()) {
    cout << "Underflow\n Program Terminated\n";
    exit(EXIT_FAILURE);
  }
  cout << "Removing element" << peek() << "\n";
  return arr[top--];
}

int Stack::peek() {
  if (isEmpty()) {
    exit(EXIT_FAILURE);
  }
  else {
    return arr[top];
  }
}

int Stack::size() {
  return top + 1;
}

bool Stack::isEmpty() {
  return top == -1;
}

bool Stack::isFull() {
  return top == capacity - 1;
}

int main() {
  Stack st;

  int n;
  cin >> n;

  st.push(n);

  cout << st.peek() << "\n";

  st.push(3);

  cout << st.peek() << "\n";

  st.pop();

  cout << st.peek() << "\n";
  return 0;
}