#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
  int val;
  ListNode* next;
  ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
 public:
  ListNode* removeElements(ListNode* head, int val) {
    ListNode *res = new ListNode(-1), *cur = res;
    res->next = head;
    while (cur->next) {
      if (cur->next->val == val) {
        cur->next = cur->next->next;
      }
      cur = cur->next;
    }
    return res->next;
  }
};