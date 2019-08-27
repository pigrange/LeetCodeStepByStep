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
  ListNode* swapPairs(ListNode* head) {
    ListNode *pre = new ListNode(0), *res = pre;
    int count = 0;
    while (pre->next != NULL) {
      if(count %2 == 0){
          ListNode * left = pre->next;
          ListNode * right = pre->next->next;
          if(right != NULL){
              pre->next = right;
              left->next = right->next;
              right->next = left;
          } 
      }
      pre = pre->next;
      count +=1;
    }
    return res->next;
  }
};