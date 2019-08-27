#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;

  ListNode(int x) : val(x), next(NULL) {}
};

void reverseLinkedList(ListNode *start, ListNode *end) {
  ListNode *pre = start->next, *head = pre;
  ListNode *nxt = pre->next, *fi = end->next;
  while (nxt != fi) {
    pre->next = nxt->next;
    nxt->next = head;
    start->next = nxt;
    head = nxt;
    nxt = pre->next;
  }
}

int main() {
  ListNode *node = new ListNode(1), *head = node;

  node->next = new ListNode(2);

  node = node->next;
  node->next = new ListNode(3);
  ListNode *end = node->next;

  node = node->next;

  node->next = new ListNode(4);

  node = node->next;
  node->next = new ListNode(5);

  cout << "end->val is " << end->val << " end next is" << end->next << endl;

  reverseLinkedList(head, end);
  while (head != NULL) {
    cout << head->val << " ,";
    head = head->next;
  }
  return 0;
}