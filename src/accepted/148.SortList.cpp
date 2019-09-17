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
  ListNode* sortList(ListNode* head) {
    if (!head || !head->next) return head;
    ListNode *slow = head, *fast = head->next;
    while (fast && fast->next) {
      slow = slow->next;
      fast = fast->next->next;
    }

    if (slow->next == fast) {
      if (slow->val > fast->val) {
        fast->next = slow;
        slow->next = NULL;
        return fast;
      } else {
        return slow;
      }
    }

    ListNode *r = slow->next, *l = head;
    slow->next = NULL;
    ListNode* newLeft = sortList(l);
    ListNode* newRight = sortList(r);
    return mergeSort(newLeft, newRight);
  }

 private:
  ListNode* mergeSort(ListNode* l, ListNode* r) {
    ListNode* res;
    if (l->val < r->val) {
      res = l;
      l = l->next;
    } else {
      res = r;
      r = r->next;
    }
    ListNode* cur = res;
    while (l && r) {
      if (l->val < r->val) {
        cur->next = l;
        l = l->next;
      } else {
        cur->next = r;
        r = r->next;
      }
      cur = cur->next;
    }
    ListNode* tail = l ? l : r;
    cur->next = tail;
    return res;
  }
};

int main() {
  ListNode* node1 = new ListNode(4);
  ListNode* node2 = new ListNode(2);
  ListNode* node3 = new ListNode(1);
  ListNode* node4 = new ListNode(3);
  node1->next = node2;
  node2->next = node3;
  node3->next = node4;
  Solution sol;
  ListNode* res = sol.sortList(node1);
  return 0;
}