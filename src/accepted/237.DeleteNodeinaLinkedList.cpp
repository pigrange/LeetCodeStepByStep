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
  void deleteNode(ListNode* node) {
    while (node->next) {
      node->val = node->next->val;
      node = node->next;
      if (!node->next->next) {
        node->val = node->next->val;
        node->next = NULL;
      }
    }
  }
};