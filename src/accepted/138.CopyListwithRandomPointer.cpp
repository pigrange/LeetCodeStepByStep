#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Node {
 public:
  int val;
  Node* next;
  Node* random;

  Node() {}

  Node(int _val, Node* _next, Node* _random) {
    val = _val;
    next = _next;
    random = _random;
  }
};
class Solution {
 public:
  Node* copyRandomList(Node* head) {
    unordered_map<Node*, Node*> ref;
    Node *res = new Node(), *cur = res, *copy = head;
    while (head) {
      Node* temp = new Node();
      temp->val = head->val;
      ref[head] = temp;
      cur->next = temp;
      cur = cur->next;
      head = head->next;
    }
    head = copy;
    cur = res;
    while (head) {
      cur->next->random = ref[head->random];
      cur = cur->next;
      head = head->next;
    }
    return res->next;
  }
};


class Solution {
 public:
  Node* copyRandomList(Node* head) {
    Node *res = new Node(0, NULL, NULL), *cur = res;
    Node* originHead = head;
    //创建镜像节点
    while (head) {
      cur->next = new Node(head->val, head->next,NULL);
      cur = cur->next;
      head = head->next;
    }
    head = originHead;
    cur = res->next;
    //将origin和镜像连接
    while (head) {
      Node* preHead = head;
      Node* preCur = cur;
      head = head->next;
      cur = cur->next;
      preHead->next = preCur;
      preCur->next = head;
    }
    //连接random节点，并且还原原来的链表
    head = originHead;
    while (head) {
      Node* mirror = head->next;
      //复制random 节点
      if(head->random)mirror->random = head->random->next;
      
      //还原原来的节点
      head->next = mirror->next;
      if (mirror->next) mirror->next = head->next->next;
      mirror = mirror->next;
      head = head->next;
    }
    return res->next;
  }
};