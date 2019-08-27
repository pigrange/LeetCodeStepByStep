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
  ListNode* reverseBetween(ListNode* head, int m, int n) {
    ListNode *res = new ListNode(0), *tail = res;
    res->next = head;
    int count = 1;
    while (count < m) {
      tail = tail->next;
      count++;
    }
    ListNode* cur = tail->next;
    while (count < n) {
      ListNode* nxt = cur->next;
      cur->next = nxt->next;
      nxt->next = tail->next;
      tail->next = nxt;
      count++;
    }
    return res->next;
  }
};