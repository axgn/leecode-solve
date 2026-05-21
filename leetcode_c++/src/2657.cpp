#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <iterator>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> findThePrefixCommonArray(vector<int> &A, vector<int> &B) {
    unordered_map<int, int> cnt;
    int n = A.size();
    vector<int> res(n);
    for (int i = 0; i < n; i++) {
      cnt[A[i]]++;
      cnt[B[i]]--;
      int sum = 0;
      for (auto kv : cnt) {
        sum += abs(kv.second);
      }
      res[i] = (2 * (i + 1) - sum) / 2;
    }
    return res;
  }
};

int main() {
  Solution s;
  cout << "" << "\n";
  return 0;
}
