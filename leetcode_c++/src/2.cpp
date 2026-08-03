#include "leetcode.h"

#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

using namespace std;

class Solution {
public:

  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    ListNode *temp = new ListNode();
    ListNode *l3 = temp;
    bool addone = false;
    while (l1 != nullptr && l2 != nullptr) {
      l3->next = new ListNode();
      l3->next->val = l1->val + l2->val;
      l3->next->val += addone ? (addone = false, 1) : 0;
      if (l3->next->val >= 10) {
        addone = true;
        l3->next->val -= 10;
      }
      l3 = l3->next;
      l1 = l1->next;
      l2 = l2->next;
    }
    while (l1) {
      l3->next = new ListNode();
      l3->next->val = l1->val;
      l3->next->val += addone ? (addone = false, 1) : 0;
      if (l3->next->val >= 10) {
        addone = true;
        l3->next->val -= 10;
      }
      l3 = l3->next;
      l1 = l1->next;
    }
    while (l2) {
      l3->next = new ListNode();
      l3->next->val = l2->val;
      l3->next->val += addone ? (addone = false, 1) : 0;
      if (l3->next->val >= 10) {
        addone = true;
        l3->next->val -= 10;
      }
      l3 = l3->next;
      l2 = l2->next;
    }
    if (addone) {
      l3->next = new ListNode();
      l3->next->val = 1;
    }
    return temp->next;
  }
};

int main() {
  Solution s;
  cout << "" << "\n";
  return 0;
}
