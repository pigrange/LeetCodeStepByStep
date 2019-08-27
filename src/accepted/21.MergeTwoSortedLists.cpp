#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
  int val;
  ListNode* next;
  ListNode(int x) : val(x), next(NULL) {}
};

// class Solution {
//  public:
//   ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
//     ListNode* head = new ListNode(0);
//     ListNode* res = head;
//     while (l1 != NULL && l2 != NULL) {
//       if (l1->val < l2->val) {
//         head->next = l1;
//         l1 = l1->next;
//       } else {
//         head->next = l2;
//         l2 = l2->next;
//       }
//       head = head->next;
//     }
//     if (l1 != NULL) head->next = l1;
//     if (l2 != NULL) head->next = l2;
//     return res->next;
//   }
// };

class Solution {
 public:
  ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    if (l1 == NULL) return l2;
    if (l2 == NULL) return l1;
    // res取小的node,同理,p1是小的指针
    ListNode* res = l1->val < l2->val ? l1 : l2;
    ListNode *p1 = res, *p2 = (p1 == l1) ? l2 : l1;
    while (p1 != NULL && p2 != NULL) {
      if ((p1->val <= p2->val && p1->next != NULL && p2->val < p1->next->val) ||
          (p1->val <= p2->val && p1->next == NULL)) {
        ListNode* temp = p2;
        p2 = p2->next;
        temp->next = p1->next;
        p1->next = temp;
      }
      p1 = p1->next;
    }
    return res;
  }
};


int main() {
  ListNode* p1 = new ListNode(1);
  ListNode* p2 = new ListNode(1);
  ListNode* t1 = p1;
  t1->next = new ListNode(2);
  t1 = t1->next;
  t1->next = new ListNode(4);

  ListNode* t2 = p2;
  t2->next = new ListNode(3);
  t2 = t2->next;
  t2->next = new ListNode(4);

  Solution sol;
  ListNode* res = sol.mergeTwoLists(p1, p2);
  while (res != NULL) {
    cout << res->val << "  ";
    res = res->next;
  }
  return 0;
}