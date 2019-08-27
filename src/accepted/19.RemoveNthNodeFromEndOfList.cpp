#include <algorithm>
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
  ListNode* removeNthFromEnd(ListNode* head, int n) {
    if (n == 0) return head;
    ListNode *start = new ListNode(0), *res = start;
    vector<ListNode*> nodes;
    int count = 0;
    start->next = head;
    while (start != NULL) {
      nodes.push_back(start);
      start = start->next;
      count++;
    }
    int pos = count - n;
    cout << "nodes.size() is" << nodes.size() << endl;
    cout << "count is " << count << endl;
    cout << "pos os " << pos << endl;
    nodes[pos - 1]->next = nodes[pos]->next;
    return res->next;
  }
};

class Solution {
 public:
  ListNode* removeNthFromEnd(ListNode* head, int n) {
    if (!head) return nullptr;

    ListNode new_head(-1);
    new_head.next = head;

    ListNode *slow = &new_head, *fast = &new_head;

    for (int i = 0; i < n; i++) fast = fast->next;

    while (fast->next) {
      fast = fast->next;
      slow = slow->next;
    }

    ListNode* to_be_deleted = slow->next;
    slow->next = slow->next->next;

    delete to_be_deleted;

    return new_head.next;
  }
};

int main() {
  ListNode* head = new ListNode(1);
  Solution sol;
  ListNode* res = sol.removeNthFromEnd(head, 1);
  cout << res->val;
  return 0;
}