#include "leetcode.h"
#include <algorithm>
#include <climits>
#include <iostream>
#include <iterator>
#include <vector>

using namespace std;
class Solution {
public:
  ListNode *insertionSortList(ListNode *head) {
    if (!head->next) {
      return head;
    }
    ListNode *dummy = new ListNode(INT_MIN, head);
    ListNode *p = dummy;
    while (p) {
      ListNode *temp = deletenode(p);
      int val = temp->val;
      ListNode *q = dummy;
      while (q != p && q->next->val < val) {
        q = q->next;
      }
      insertnode(q, temp);
      if (q == p) {
        p = p->next;
      }
    }
    return dummy->next;
  }
  void insertnode(ListNode *node1, ListNode *node2) {
    ListNode *temp = node1->next;
    node1->next = node2;
    node2->next = temp;
  }
  ListNode *deletenode(ListNode *node) {
    ListNode *temp = node->next;
    node->next = node->next->next;
    return temp;
  }
};
int main() {
  Solution s;

  s.insertionSortList(
      new ListNode(4, new ListNode(2, new ListNode(1, new ListNode(3)))));
  cout << "" << "\n";
  return 0;
}
