#include "leetcode.h"
#include <algorithm>
#include <climits>
#include <iostream>
#include <iterator>
#include <vector>

using namespace std;
class Solution1 {
public:
  ListNode *insertionSortList(ListNode *head) {
    if (!head || !head->next) {
      return head;
    }
    ListNode *dummy = new ListNode(INT_MIN, head);
    ListNode *lastSorted = head;
    ListNode *curr = head->next;
    while (curr != nullptr) {
      if (lastSorted->val <= curr->val) {
        lastSorted = lastSorted->next;
      } else {
        ListNode *prev = dummy;
        while (prev->next->val <= curr->val) {
          prev = prev->next;
        }
        // 必须先删除再插入
        deletenext(lastSorted);
        insertnode(prev, curr);
      }
      curr = lastSorted->next;
    }
    return dummy->next;
  }
  void insertnode(ListNode *node1, ListNode *node2) {
    ListNode *temp = node1->next;
    node1->next = node2;
    node2->next = temp;
  }
  ListNode *deletenext(ListNode *node) {
    ListNode *temp = node->next;
    node->next = node->next->next;
    return temp;
  }
};
class Solution {
public:
  ListNode *insertionSortList(ListNode *head) {
    if (head == nullptr) {
      return head;
    }
    ListNode *dummyHead = new ListNode(0);
    dummyHead->next = head;
    ListNode *lastSorted = head;
    ListNode *curr = head->next;
    while (curr != nullptr) {
      if (lastSorted->val <= curr->val) {
        lastSorted = lastSorted->next;
      } else {
        ListNode *prev = dummyHead;
        while (prev->next->val <= curr->val) {
          prev = prev->next;
        }
        lastSorted->next = curr->next;
        curr->next = prev->next;
        prev->next = curr;
      }
      curr = lastSorted->next;
    }
    return dummyHead->next;
  }
};
int main() {
  Solution s;

  s.insertionSortList(
      new ListNode(4, new ListNode(2, new ListNode(1, new ListNode(3)))));
  cout << "" << "\n";
  return 0;
}
