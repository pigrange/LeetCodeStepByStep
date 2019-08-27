#include <iostream>
#include <set>
#include <stack>
#include <vector>
using namespace std;

class DinnerPlates {
 private:
  int capacity = 0;

  set<int> pushable, popable;
  vector<stack<int>> stacks;
 public:
  DinnerPlates(int capacity) { this->capacity = capacity; }

  void push(int val) {
    if (pushable.empty()) {
      pushable.insert(stacks.size());
      stacks.push_back(stack<int>());
    }
    int i = *pushable.begin();
    stack<int>& s = stacks[i];
    s.push(val);
    popable.insert(i);
    if (s.size() == capacity) pushable.erase(i);
  }

  int pop() {
    if (!popable.size()) return -1;
    int i = *popable.end();
    return popAtStack(i);
  }

  int popAtStack(int index) {
    if (!popable.count(index)) return -1;
    stack<int>& s = stacks[index];
    int res = s.top();
    s.pop();
    pushable.insert(index);
    if (s.size() == 0) popable.erase(index);
    return res;
  }
};

int main() {
  DinnerPlates D = DinnerPlates(2);  // 初始化，栈最大容量 capacity = 2
  D.push(1);
  D.push(2);
  D.push(3);
  D.push(4);
  D.push(5);
  cout << D.popAtStack(0) << endl;
  D.push(20);
  D.push(21);

  return 0;
}