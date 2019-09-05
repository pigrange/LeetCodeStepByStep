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
  ListNode *insertionSortList(ListNode *head) {
    ListNode *res = new ListNode(-1), *p = res;
    res->next = head;
    while (p->next) {
      // q去寻找p
      ListNode *q = res;
      ListNode *log = res;
      //比p小的一定在P前面
      while (q->next->val < p->next->val) q = q->next;
      //大于等于都做插入
      if (p != q) {
        ListNode *t = p->next;
        p->next = t->next;
        t->next = q->next;
        q->next = t;
        continue;
      }
      p = p->next;
    }
    return res->next;
  }
};