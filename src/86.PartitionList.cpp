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
  ListNode *partition(ListNode *head, int x) {
    ListNode *small = new ListNode(0), *big = new ListNode(0);
    ListNode *sPtr = small, *bPtr = big;
    while (head != NULL) {
      if (head->val < x) {
        sPtr->next = head;
        sPtr = sPtr->next;
      } else {
        bPtr->next = head;
        bPtr = bPtr->next;
      }
      head = head->next;
    }
    bPtr->next = NULL;
    sPtr->next = big->next;
    return small->next;
  }
};

int main() {
  Solution sol;
  ListNode *node = new ListNode(1), *head = node;
  node->next = new ListNode(4);
  node = node->next;
  node->next = new ListNode(3);
  node = node->next;
  node->next = new ListNode(2);
  node = node->next;
  node->next = new ListNode(5);
  node = node->next;
  node->next = new ListNode(2);
  node = node->next;

  ListNode *res = sol.partition(head, 3);
  while (res != NULL) {
    cout << res->val << " ";
    res = res->next;
  }
  return 0;
}