#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
 public:
  ListNode *detectCycle(ListNode *head) {
    unordered_set<ListNode *> ref;
    while (head) {
      if (ref.count(head)) return head;
      ref.insert(head);
      head = head->next;
    }
    return NULL;
  }
};

class Solution {
 public:
  ListNode *detectCycle(ListNode *head) {
    ListNode *fast = head, *slow = head;
    while (true) {
      if (!fast || !fast->next) return NULL;
      fast = fast->next->next;
      slow = slow->next;
      if (fast == slow) break;
    }
    while (head) {
      head = head->next;
      slow = slow->next;
      if (head == slow) break;
    }
    return head;
  }
};