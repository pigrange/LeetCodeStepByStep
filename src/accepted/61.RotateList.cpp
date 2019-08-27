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
  ListNode* rotateRight(ListNode* head, int k) {
    if (head == NULL) return head;
    int len = 1;
    ListNode* tail = head,*res = head;
    //计算node的长度
    while (tail->next != NULL) {
      len++;
      tail = tail->next;
    }
    int pos = len - k % len, count = 1;
    if(pos == 0 || len) return head; 
    //找到断点
    ListNode* current = head;
    while (count < pos) {
      count++;
      current = current->next;
    }
    ListNode* res = current->next;
    tail->next = head;
    current->next = NULL;
    return res;
  }
};