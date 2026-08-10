#include "leetcode.h"
#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>
using namespace std;
class Solution {
public:
  void flatten(TreeNode *root) {
    TreeNode *cur = root;
    while (cur) {
      if (cur->left) {
        TreeNode *next = cur->left;
        TreeNode *pre = next;
        while (pre->right) {
          pre = pre->right;
        }
        pre->right = cur->right;
        cur->right = next;
        cur->left = nullptr;
      }
      cur = cur->right;
    }
  }
};
int main() {
  Solution s;
  cout << "" << "\n";
  
  return 0;
}
