class Solution {
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
      int m = grid.size();
      int n = grid[0].size();
      int m_temp = m,n_temp = n;
      vector<int> v_size;
      while (m_temp > 0 && n_temp > 0)
      {
        v_size.push_back(m_temp * 2 + n_temp * 2 - 4);
        m_temp -= 2,n_temp -=2;
      }
      for (size_t i = 0; i < v_size.size(); i++)
      {
        int temp = k % v_size[i];
        for (size_t cnt = 0; cnt < temp; cnt++)
        {
          int temp_v = grid[i][i];
          for (size_t j = i; j < n - i - 1; j++)
          {
            grid[i][j] = grid[i][j + 1];
          }
          for (size_t j = i; j < m - i - 1; j++)
          {
            grid[j][n - i - 1] = grid[j + 1][n - i - 1];
          }
          for (size_t j = n - i - 1; j > i; j--)
          {
            grid[m - i - 1][j] = grid[m - i - 1][j - 1];
          }
          for (size_t j = m - i - 1; j > i; j--)
          {
            grid[j][i] = grid[j - 1][i];
          }
          grid[i + 1][i] = temp_v;
        }
      }
      return grid;
    }
};
