#include "leetcode.h"
#include <algorithm>
#include <iostream>
#include <iterator>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution1 {
  unordered_map<int, int> pos;

public:
  TreeNode *buildBfs(vector<int> &preorder, vector<int> &inorder, int leftPre,
                     int rightPre, int leftIn, int rightIn) {
    if (leftPre > rightPre) {
      return nullptr;
    }
    int rootV = preorder[leftPre];
    TreeNode *root = new TreeNode(rootV);
    int mid = pos[rootV];
    int length = mid - leftIn;
    root->left = buildBfs(preorder, inorder, leftPre + 1, leftPre + length,
                          leftIn, mid - 1);
    root->right = buildBfs(preorder, inorder, leftPre + length + 1, rightPre,
                           mid + 1, rightIn);

    return root;
  }
  TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
    int n = preorder.size();
    for (int i = 0; i < n; i++) {
      pos[inorder[i]] = i;
    }
    return buildBfs(preorder, inorder, 0, n - 1, 0, n - 1);
  }
};

class Solution {
  unordered_map<int, int> pos;

public:
  TreeNode *buildBfs(vector<int> &postorder, vector<int> &inorder, int leftPost,
                     int rightPost, int leftIn, int rightIn) {
    if (leftPost > rightPost) {
      return nullptr;
    }
    int rootV = postorder[rightPost];
    TreeNode *root = new TreeNode(rootV);
    int mid = pos[rootV];
    int length = mid - leftIn;
    root->left = buildBfs(postorder, inorder, leftPost, leftPost + length - 1,
                          leftIn, mid - 1);
    root->right = buildBfs(postorder, inorder, leftPost + length, rightPost - 1,
                           mid + 1, rightIn);

    return root;
  }
  TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
    int n = postorder.size();
    for (int i = 0; i < n; i++) {
      pos[inorder[i]] = i;
    }
    return buildBfs(postorder, inorder, 0, n - 1, 0, n - 1);
  }
};

int main() {
  Solution s;
  cout << "" << "\n";
  return 0;
}
