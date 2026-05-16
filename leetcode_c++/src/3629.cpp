#include <vector>
#include <array>
#include <queue>
#include <iostream>

using namespace std;

const int MX = 1'000'001;
vector<int> prime_factors[MX];

int init = [] {
    for (int i = 2; i < MX; i++) {
        if (prime_factors[i].empty()) {
            for (int j = i; j < MX; j += i) {
                prime_factors[j].push_back(i);
            }
        }
    }
    return 0;
}();

class Solution {
public:
    int minJumps(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, vector<int>> groups;
        for (int i = 0; i < n; i++) {
            for (int p : prime_factors[nums[i]]) {
                groups[p].push_back(i);
            }
        }

        vector<int8_t> vis(n);
        vis[0] = true;
        vector<int> q = {0};
        int ans = 0;
        for (; ; ans++) {
            auto tmp = q;
            q.clear();
            for (int i : tmp) {
                if (i == n - 1) {
                    return ans;
                }
                auto& idx = groups[nums[i]];
                idx.push_back(i + 1);
                if (i > 0) {
                    idx.push_back(i - 1);
                }
                for (int j : idx) {
                    if (!vis[j]) {
                        vis[j] = true;
                        q.push_back(j);
                    }
                }
                idx.clear();
            }
        }
        return ans;
    }
};

int main() {
    cout << "test" << endl;
    Solution s;
    vector<int> nums = {1,2,4,6};
    s.minJumps(nums);
    return 0;
}
