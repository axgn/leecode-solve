#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

class Solution {
  bool result = false;

public:
  void deep_search(TreeNode *root, int targetSum) {
    if (root == nullptr || result) {
      return;
    }
    int temp = targetSum - root->val;
    if (temp == 0 && !(root->left) && !(root->right)) {
      result = true;
      return;
    }
    deep_search(root->left, temp);
    deep_search(root->right, temp);
  }
  bool hasPathSum(TreeNode *root, int targetSum) {
    if (root == nullptr) {
      return false;
    }
    deep_search(root, targetSum);
    return result;
  }
};

int main() {
  Solution s;
  cout << "" << endl;
  return 0;
}
