#include "leetcode.h"
#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

using namespace std;

class Solution {
public:
  ListNode *removeElements(ListNode *head, int val) {
    ListNode *dummy = new ListNode(0, head);
    ListNode *temp = dummy;
    while (dummy->next != nullptr) {
      if (dummy->next->val == val) {
        dummy->next = dummy->next->next;
      } else {
        dummy = dummy->next;
      }
    }
    return temp->next;
  }
};
int main() {
  Solution s;
  cout << "" << "\n";
  return 0;
}
