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
  ListNode* removeZeroSumSublists(ListNode* head) {
    int val = 0;
    ListNode* res = head;
    if (head->next) head->next = removeZeroSumSublists(head->next);
    while (head) {
      val += head->val;
      if (val == 0) return head->next;
      head = head->next;
    }
    return res;
  }
};