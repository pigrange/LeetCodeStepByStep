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
  ListNode *reverseKGroup(ListNode *head, int k) {
    if (k <= 1) return head;
    ListNode *res = new ListNode(0), *pre = res;
    res->next = head;
    int count = 0;
    ListNode *startPtr;
    while (pre->next != NULL) {
      if (count % k == 0) {
        startPtr = pre;
      } else if (count % k == k - 1) {
        reverseLinkedList(startPtr, pre->next->next);
      }
      count++;
      pre = pre->next;
    }
    return res->next;
  }

 private:
  void reverseLinkedList(ListNode *start, ListNode *end) {
    ListNode *pre = start->next, *head = pre;
    ListNode *nxt = pre->next;
    while (nxt != end) {
      pre->next = nxt->next;
      nxt->next = head;
      start->next = nxt;
      head = nxt;
      nxt = pre->next;
    }
  }
};

int main() {
  Solution sol;
  ListNode *node = new ListNode(1);
  node->next = new ListNode(2);
  node = node->next;
  node->next = new ListNode(3);
  node = node->next;
  node->next = new ListNode(4);
  node = node->next;
  node->next = new ListNode(5);
  ListNode *res = sol.reverseKGroup(node, 2);
  while (res != NULL) {
    cout << res->val << " ,";
    res = res->next;
  }
  return 0;
}