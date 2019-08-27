#include <iostream>
#include <vector>
using namespace std;
class Node {
 public:
  int val;
  Node* left;
  Node* right;
  Node* next;

  Node() {}

  Node(int _val, Node* _left, Node* _right, Node* _next) {
    val = _val;
    left = _left;
    right = _right;
    next = _next;
  }
};
class Solution {
 public:
  Node* connect(Node* root) {
    if (!root || (!root->left) && (!root->right)) return root;
    Node* left = connect(root->left);
    Node* right = connect(root->right);
    Node* leftPre = root;
    while (left && right) {
      Node* temp = left;
      left = left->left ? left->left : left->right ? left->right : left->next;
      while (temp) temp = temp->next;
      temp->next = right;
      right =
          right->left ? right->left : right->right ? right->right : right->next;
    }
    return root;
  }
};

Node* connect(Node* root) {
  Node *now = root, *tail = NULL, *head = NULL;
  while (now) {
    if (now->left)
      if (tail)
        tail = tail->next = now->left;
      else
        head = tail = now->left;
    if (now->right)
      if (tail)
        tail = tail->next = now->right;
      else
        head = tail = now->right;
    if (!(now = now->next)) {
      now = head;
      head = tail = NULL;
    }
  }
  return root;
}

class Solution {
  Node *head, *tail;

 public:
  Node* connect(Node* root) {
    Node* res = root;
    while (root) {
      while (root) {
        if (root->left) {
          if (!head) {
            head = tail = root->left;
          } else {
            tail->next = root->left;
            tail = tail->next;
          }
        }
        if (root->right) {
          if (!head) {
            head = tail = root->right;
          } else {
            tail->next = root->right;
            tail = tail->next;
          }
        }
        root = root->next;
      }
      root = head;
      head = NULL;
    }
    return res;
  }
};