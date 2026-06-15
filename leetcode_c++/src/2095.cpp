#include "leetcode.h"

#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

using namespace std;

class Solution {
public:
  ListNode *findmidnode(ListNode *head) {
    ListNode *slow = head, *fast = head;
    while (fast && fast->next) {
      slow = slow->next;
      fast = fast->next->next;
    }
    return slow;
  }
  void deletenode(ListNode *head) {
    
  }

  ListNode *deleteMiddle(ListNode *head) {

  }
};

int main() {
  Solution s;
  cout << "" << "\n";
  return 0;
}
