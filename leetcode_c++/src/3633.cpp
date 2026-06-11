#include <algorithm>
#include <climits>
#include <iostream>
#include <iterator>
#include <vector>

using namespace std;

class Solution {
  int solve(vector<int> &landStartTime, vector<int> &landDuration,
            vector<int> &waterStartTime, vector<int> &waterDuration) {
    int m = landStartTime.size();
    int n = waterStartTime.size();
    int finishFirst = INT_MAX;
    for (int i = 0; i < m; i++) {
      int endTime = landStartTime[i] + landDuration[i];
      if (endTime < finishFirst) {
        finishFirst = endTime;
      }
    }
    int res = INT_MAX;
    for (int i = 0; i < n; i++) {
      int final_time = max(finishFirst, waterStartTime[i]) + waterDuration[i];
      if (final_time < res) {
        res = final_time;
      }
    }
    return res;
  }

public:
  int earliestFinishTime(vector<int> &landStartTime, vector<int> &landDuration,
                         vector<int> &waterStartTime,
                         vector<int> &waterDuration) {
    int land_water =
        solve(landStartTime, landDuration, waterStartTime, waterDuration);
    int water_land =
        solve(waterStartTime, waterDuration, landStartTime, landDuration);
    return min(land_water, water_land);
  }
};

int main() {
  Solution s;
  cout << "" << "\n";
  return 0;
}
