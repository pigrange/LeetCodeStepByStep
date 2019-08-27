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
  ListNode* deleteDuplicates(ListNode* head) {
    ListNode *start = new ListNode(-1), *pre = start, *p;
    pre->next = head;
    while (head != NULL) {
      if (head->next != NULL && head->next->val == head->val) {
        while (head->next != NULL && head->next->val == head->val)
          head = head->next;
        pre->next = head->next;
        head = head->next;
        continue;
      }
      head = head->next;
      pre = pre->next;
    }
    return start->next;
  }
};