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
    ListNode *mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (NULL == l1) return l2;
        else if (NULL == l2) return l1;
        if (l1->val <= l2->val) {
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        }
        else {
            l2->next = mergeTwoLists(l1, l2->next);
            return l2;
        }
    }
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        if (lists.empty()) return NULL;
        int len = lists.size();
        while (len > 1) {
            for (int i = 0; i < len / 2; ++i) {
                lists[i] = mergeTwoLists(lists[i], lists[len - 1 - i]);
            }
            len = (len + 1) / 2;
        }
        
        return lists.front();
    }
};

class Solution {
 public:
  ListNode* mergeKLists(vector<ListNode*>& lists) {
    if (lists.size() == 0) return NULL;
    if (lists.size() == 1) return lists[0];
    ListNode* res = lists[0];
    for (int i = 1; i < lists.size(); i++) {
      res = mergeTwoLists(res, lists[i]);
    }
    return res;
  }

 private:
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
