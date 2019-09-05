#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
 public:
  bool hasCycle(ListNode *head) {
    ListNode *fast, *slow;
    while (fast && slow) {
      //这个时候fast已经到最后了
      if (!fast->next) {
        break;
      }
      fast = fast->next->next;
      slow = slow->next;
      if (fast == slow) return false;
    }
    return true;
  }
};