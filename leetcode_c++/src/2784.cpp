class Solution {
public:
    bool isGood(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> cnt;
        for (size_t i = 0; i < n; i++)
        {
          int v = nums[i];
          if (v >= n || v <= 0)
          {
            return false;
          }
          cnt[v]++;
          if (cnt[v] > 1 && v != n - 1)
          {
            return false;
          }
          if (cnt[v] > 2)
          {
            return false;
          }
        }
        return true;
    }
};
