class Solution {
public:
    int maximumJumps(vector<int>& nums, int target) {
      int n = nums.size();
      vector<int> dp(n);
      for(int i = 1;i < n;i++)
      {
        dp[i] = -1;
      }
      for(int i = 0;i < n;i++)
      {
        for(int j = 0;j < i;j++)
        {
          int diff = nums[i] - nums[j];
          if(diff >= -target && diff <= target && dp[j] != -1 && dp[j] + 1 >= dp[i])
          {
            dp[i] = dp[j] + 1;
          }
        }
      }
      return dp[n - 1];
    }
};
