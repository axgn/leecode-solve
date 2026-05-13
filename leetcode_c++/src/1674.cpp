class Solution {
public:
    int minMoves(vector<int>& nums, int limit) {
        unordered_map<int,int> sum_cnt;
        int n = nums.size();
        for (size_t i = 0; i < n / 2; i++)
        {
          int sum = nums[i] + nums[n - 1 - i];
          sum_cnt[sum]++;
        }
        auto max_pos = std::max_element(std::begin(sum_cnt), std::end(sum_cnt),[](auto& a,auto&b){return a.second < b.second;});
        return n / 2 - (*max_pos).second;
    }
};
