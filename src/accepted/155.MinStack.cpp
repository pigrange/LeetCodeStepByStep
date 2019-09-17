#include <iostream>
#include <stack>
#include <vector>
using namespace std;
class MinStack {
 private:
  stack<int> s1;
  stack<int> s2;

 public:
  /** initialize your data structure here. */
  MinStack() {}

  void push(int x) {
    s1.push(x);
    if (s2.empty() || x < getMin()) s2.push(x);
  }

  void pop() {
    if (top() == getMin()) s2.pop();
    s1.pop();
  }

  int top() { return s1.top(); }

  int getMin() { return s2.top(); }
};