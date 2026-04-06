#include "leetcode.h"
#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

class Solution {
  void reverseLinkedList(ListNode *head) {
    ListNode *cur = head;
    ListNode *pre = nullptr;
    while (cur != nullptr) {
      ListNode *next = cur->next;
      cur->next = pre;
      pre = cur;
      cur = next;
    }
  }

public:
  ListNode *reverseBetween(ListNode *head, int left, int right) {
    ListNode *dummyNode = new ListNode(-1, head);
    ListNode *pre = dummyNode;
    for (int i = 0; i < left - 1; i++) {
      pre = pre->next;
    }
    ListNode *rightnode = pre;
    for (int i = 0; i < right - left + 1; i++) {
      rightnode = rightnode->next;
    }
    ListNode *temp = rightnode->next;
    ListNode *leftnode = pre->next;

    rightnode->next = nullptr;
    pre->next = nullptr;
    reverseLinkedList(leftnode);

    leftnode->next = temp;
    pre->next = rightnode;
    return dummyNode->next;
  }
};

using namespace std;

int main() {
  Solution s;
  cout << "" << "\n";
  return 0;
}
