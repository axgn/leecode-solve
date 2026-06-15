#include "leetcode.h"

#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

using namespace std;

class Solution {
public:
  ListNode *findMidNode(ListNode *head) {
    ListNode *slow = head, *fast = head->next->next;
    while (fast && fast->next) {
      slow = slow->next;
      fast = fast->next->next;
    }
    return slow;
  }
  void deleteNextNode(ListNode *head) { head->next = head->next->next; }

  ListNode *deleteMiddle(ListNode *head) {
    if (!head->next) {
      return nullptr;
    }
    ListNode *mid = findMidNode(head);
    deleteNextNode(mid);
    return head;
  }
};

int main() {
  Solution s;
  cout << "" << "\n";
  return 0;
}
