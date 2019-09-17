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
  ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    ListNode *curA = headA, *curB = headB;
    int count1 = 1, count2 = 1;
    while (curA->next) {
      curA = curA->next;
      count1++;
    }
    while (curB->next) {
      curB = curB->next;
      count2++;
    }
    if (curA->val != curB->val) {
      return NULL;
    }
    ListNode *longNode, *shortNode;
    int dis = abs(count1 - count2);
    if (count1 > count2) {
      longNode = headA;
      shortNode = headB;
    } else {
      longNode = headB;
      shortNode = headA;
    }
    //让长的先走几步
    while (dis > 0) {
      longNode = longNode->next;
      dis--;
    }
    while (shortNode) {
      if (longNode == shortNode) return shortNode;
      longNode = longNode->next;
      shortNode = shortNode->next;
    }
    return NULL;
  }
};