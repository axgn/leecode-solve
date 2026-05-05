Solution s = new Solution();
Console.WriteLine(s.MaxPathScore([[0, 1], [2, 0]], 1));
public class Solution
{
  public int MaxPathScore(int[][] grid, int k)
  {
    int m = grid.Length, n = grid[0].Length;
    int[][][] dp = new int[m][][];
    for (int i = 0; i < m; i++)
    {
      dp[i] = new int[n][];
      for (int j = 0; j < n; j++)
      {
        dp[i][j] = new int[k + 1];
      }
    }
    dp[0][0][0] = 0;
    for (int i = 1; i <= k; i++)
    {
      dp[0][0][i] = grid[0][0];
    }
    for (int i = 1; i < m; i++)
    {
      for (int j = 1; j <= k; j++)
      {
        if (grid[i][0] != 0)
        {
          dp[i][0][j] = dp[i - 1][0][j - 1] + grid[i][0];
        }
        else
        {
          dp[i][0][j] = dp[i - 1][0][j];
        }
      }
    }
    for (int i = 1; i < n; i++)
    {
      for (int j = 1; j <= k; j++)
      {
        if (grid[0][i] != 0)
        {
          dp[0][i][j] = dp[0][i - 1][j - 1] + grid[0][i];
        }
        else
        {
          dp[0][i][j] = dp[0][i - 1][j];
        }
      }
    }
    for (int i = 1; i < m; i++)
    {
      for (int j = 1; j < n; j++)
      {
        for (int l = 1; l <= k; l++)
        {
          if (grid[i][j] != 0)
          {
            dp[i][j][l] = Math.Max(dp[i - 1][j][l - 1], dp[i][j - 1][l - 1]) + grid[i][j];
          }
          else
          {
            dp[i][j][l] = Math.Max(dp[i][j - 1][l], dp[i - 1][j][l]);
          }
        }
      }
    }
    return dp[m - 1][n - 1][k];
  }
}
