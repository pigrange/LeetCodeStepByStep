#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class Solution {
 public:
  int evalRPN(vector<string>& tokens) {
    stack<int> ref;
    for (auto i : tokens) {
      if (i == "+" || i == "-" || i == "*" || i == "/") {
        if (ref.size() < 2) continue;
        int num2 = ref.top();
        ref.pop();
        int num1 = ref.top();
        ref.pop();
        if (i == "+") {
          ref.push(num1 + num2);
        } else if (i == "-") {
          ref.push(num1 - num2);
        } else if (i == "*") {
          ref.push(num1 * num2);
        } else if (i == "/") {
          ref.push(num1 / num2);
        }
        continue;
      }
      ref.push(stoi(i));
    }
    return ref.top();
  }
};

int main() {
  Solution sol;
  vector<string> test = {"10", "6", "9",  "3", "+", "-11", "*",
                         "/",  "*", "17", "+", "5", "+"};
  sol.evalRPN(test);
  return 0;
}