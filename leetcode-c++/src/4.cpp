#include <bits/stdc++.h>
#include <vector>

using namespace std;

class Solution {
private:
  double solve11(vector<int> nums, int left, int right, int other) {
    int mid = (left + right) / 2;
    if ((left + right) % 2) {
      if (nums[mid] > other) {
        return nums[mid];
      } else {
        if (nums[mid + 1] > other) {
          return other;
        } else {
          return nums[mid + 1];
        }
      }
    } else {
      if (nums[mid] > other) {
        if (nums[mid - 1] < other) {
          return (other + nums[mid]) / 2;
        } else {
          return (nums[mid - 1] + nums[mid]) / 2;
        }
      } else {
        if (nums[mid + 1] > other) {
          return (other + nums[mid]) / 2;
        } else {
          return (nums[mid + 1] + nums[mid]) / 2;
        }
      }
    }
  }
  double solve1(vector<int> &nums1, vector<int> &nums2, int left1, int left2,
                int right1, int right2) {
    if (left1 == right1) {
      return solve11(nums2, left2, right2, nums1[left1]);
    } else {
      return solve11(nums1, left1, right1, nums2[left2]);
    }
  }

  double solve2(vector<int> &nums1, vector<int> &nums2, int left1, int left2,
                int right1, int right2) {
    if (right1 - left1 == 1) {
      return solve22(nums2, left2, right2, nums1[left1], nums1[right1]);
    } else {
      return solve22(nums1, left1, right1, nums2[left2], nums2[right2]);
    }
  }

  double solve22(vector<int> nums, int left, int right, int other_l,
                 int other_r) {
    int mid = (left + right) / 2;
    if ((left + right) % 2) {
      return 0;
    } else {
      if (nums[mid] < other_l) {
        if (nums[mid + 1] > other_l) {
          return other_l;
        } else {
          return nums[mid + 1];
        }
      } else if (nums[mid] > other_r) {
        if (nums[mid - 1] < other_r) {
          return other_r;
        } else {
          return nums[mid - 1];
        }
      } else {
        return nums[mid];
      }
    }
  }

public:
  double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
    int left1 = 0, left2 = 0;
    int right1 = nums1.size(), right2 = nums2.size();
    int mid1 = (left1 + right1) / 2, mid2 = (left2 + right2) / 2;
    if (nums1[mid1] >= nums2[mid2]) {
      left2 = mid2;
      right1 = mid1;
    } else if (nums1[mid1] < nums2[mid2]) {
      left1 = mid1;
      right2 = mid2;
    }
    return 0;
  }
};

int main() {
  Solution s;
  vector<int> v1 = {1, 2, 3, 4};
  vector<int> v2 = {5, 6, 7, 8};
  cout << s.findMedianSortedArrays(v1, v2) << endl;
  return 0;
}
