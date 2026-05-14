#include <vector>
#include <array>
#include <queue>
#include <iostream>

using namespace std;

class Solution {
    static constexpr int MAX = 1'000'001;
    vector<vector<int>> table{MAX};
    vector<vector<int>> table_v_pos{MAX};
    void initTable()
    {
        for (size_t i = 2; i < MAX; i++)
        {
            if (table[i].size() == 0)
            {
                for (size_t j = i; j < MAX; j += i)
                {
                    table[j].push_back(i);
                }
            }
        }
    }

    void initTableVPos(vector<int>& nums)
    {
        for (size_t i = 0; i < nums.size(); i++)
        {
            int v = nums[i];
            for (size_t j = 0; j < table[v].size(); j++)
            {
                table_v_pos[table[v][j]].push_back(i);
            }
        }
    }

public:
    int minJumps(vector<int>& nums) {
        initTable();
        initTableVPos(nums);
        int n = nums.size();
        vector<int> vis(n, 0);
        vis[0] = 1;
        int i = 0;
        queue<int> q(deque<int>(1,0));
        int cnt = 0;
        while (i != n - 1)
        {
            auto tmp = q;
            q = queue<int>();
            while (tmp.size() != 0 && i != n - 1)
            {
                i = tmp.front();
                tmp.pop();
                if (vis[i + 1] == 0)
                {
                    q.push(i + 1);
                    vis[i + 1] = 1;
                }
                if (i > 0 && vis[i - 1] == 0)
                {
                    q.push(i - 1);
                    vis[i - 1] = 1;
                }
                for (size_t j = 0; j < table_v_pos[nums[i]].size(); j++)
                {
                    if (vis[table_v_pos[nums[i]][j]] == 0)
                    {
                        q.push(table_v_pos[nums[i]][j]);
                        vis[table_v_pos[nums[i]][j]] = 1;
                    }
                }
            }
            cnt++;
        }
        return cnt;
    }
};

int main() {
    cout << "test" << endl;
    Solution s;
    vector<int> nums = {1,2,4,6};
    s.minJumps(nums);
    return 0;
}
