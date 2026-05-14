class Solution {
public:
    int minMoves(vector<int>& nums, int limit) {
        vector<int> result(2 * limit + 1);
        int n = nums.size();
        for (size_t i = 0; i < n / 2; i++)
        {
            int sum = nums[i] + nums[n - 1 - i];
            int min_v = min(x,y);
            int max_v = max(x,y);
            result[1] += 2;
            result[min_v] -= 1;
            result[max_v + limit - 1] += 1;
            result[]
        }
        return n / 2 - (*max_pos).second;
    }
};
