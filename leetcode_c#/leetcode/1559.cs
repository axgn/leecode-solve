Solution s = new Solution();
s.ContainsCycle([['a', 'a', 'a', 'a'], ['a', 'b', 'b', 'a'], ['a', 'b', 'b', 'a'], ['a', 'a', 'a', 'a']]);

public class Solution
{
  public bool ContainsCycle(char[][] grid)
  {

    int m = grid.Length;
    int n = grid[0].Length;
    bool[][] visited = new bool[m][];
    for (int i = 0; i < m; i++)
    {
      visited[i] = new bool[n];
    }
    Dictionary<int, (int, int)> directions = new Dictionary<int, (int, int)> { { 0, (-1, 0) }, { 1, (0, 1) }, { 2, (1, 0) }, { 3, (0, -1) } };

    bool res = false;
    void dfs(int x, int y, int last_direction)
    {
      foreach (var kv in directions)
      {

        if (kv.Key != last_direction)
        {
          int n_px = x + kv.Value.Item1;
          int n_py = y + kv.Value.Item2;
          if (n_px >= 0 && n_px < m && n_py >= 0 && n_py < n && grid[n_px][n_py] == grid[x][y])
          {
            if (!visited[n_px][n_py])
            {
              visited[n_px][n_py] = true;
              dfs(n_px, n_py, (kv.Key + 2) % 4);
            }
            else
            {
              res = true;
              break;
            }
          }
        }
      }
    }
    for (int i = 0; i < m; i++)
    {
      for (int j = 0; j < n; j++)
      {
        if (!visited[i][j])
        {
          dfs(i, j, -1);
        }
      }
    }
    return res;
  }
}
