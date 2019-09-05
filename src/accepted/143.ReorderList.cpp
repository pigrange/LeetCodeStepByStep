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
  void reorderList(ListNode *head) {
    ListNode *fast = head, *slow = head;
    while (fast) {
      cout << slow->val;
      fast = fast->next;
      if (fast) fast = fast->next;
      slow = slow->next;
    }
    ListNode *mid = slow, *tail = NULL;
    while (slow) {
      ListNode *pre = slow;
      slow = slow->next;
      pre->next = tail;
      tail = pre;
    }
    while (tail != mid) {
      ListNode *oldTail = tail, *oldHead = head;
      tail = tail->next;
      head = head->next;
      oldTail->next = head;
      oldHead->next = oldTail;
    }
  }
};