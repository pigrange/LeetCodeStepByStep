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
  ListNode* reverseList(ListNode* head) {
    ListNode* res = NULL;
    while (head) {
      ListNode* nex = head->next;
      head->next = res;
      res = head;
      head = nex;
    }
    return res;
  }
};