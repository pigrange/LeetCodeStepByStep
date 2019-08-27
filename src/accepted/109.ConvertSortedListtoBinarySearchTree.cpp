#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//快慢指针,找链表的中间节点
class Solution {
 public:
  TreeNode *sortedListToBST(ListNode *head) {
    if (!head) return NULL;
    if (!head->next) return new TreeNode(head->val);
    ListNode *slow = head, *fast = head, *last = slow;
    while (fast->next && fast->next->next) {
      last = slow;
      slow = slow->next;
      fast = fast->next->next;
    }
    fast = slow->next;
    last->next = NULL;
    TreeNode *cur = new TreeNode(slow->val);
    if (head != slow) cur->left = sortedListToBST(head);
    cur->right = sortedListToBST(fast);
    return cur;
  }
};