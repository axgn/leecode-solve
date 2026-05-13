class Solution {
public:
  vector<int> separateDigits(vector<int> &nums) {
    vector<int> res;
    for(int i = 0;i < nums.size();i++)
    {
      int temp = nums[i];
      vector<int> st_res;
      while(temp != 0)
      {
        st_res.push_back(temp % 10);
        temp /= 10;
      }
      while(st_res.size() != 0)
      {
        res.push_back(st_res.back());
        st_res.pop_back();
      }
    }
    return res;
  }
};
