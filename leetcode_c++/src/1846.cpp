#include <algorithm>
#include <climits>
#include <iostream>
#include <iterator>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution2 {
public:
  int maximumElementAfterDecrementingAndRearranging(vector<int> &arr) {
    int n = arr.size();
    vector<int> cnt(n + 1);
    for (auto v : arr) {
      if (v > n) {
        v = n;
      }
      cnt[v]++;
    }
    int ans = 1;
    for (int i = 2; i <= n; i++) {
      ans = min(ans + cnt[i], i);
    }
    return ans;
  }
};

class Solution {
public:
  int maximumElementAfterDecrementingAndRearranging(vector<int> &arr) {
    int n = arr.size();
    sort(arr.begin(), arr.end());
    if (arr[0] != 1) {
      arr[0] = 1;
    }
    for (int i = 1; i < n; i++) {
      if (arr[i] > arr[i - 1] + 1) {
        arr[i] = arr[i - 1] + 1;
      }
    }
    return arr[n - 1];
  }
};

int main() {
  Solution s;
  cout << "" << "\n";
  return 0;
}
