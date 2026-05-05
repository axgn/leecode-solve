public class Solution
{
  public int MaxPathScore(int[][] grid, int k)
  {
    int m = grid.Length, n = grid[0].Length;
    int[][][] dp = new int[m][][];
    for (int i = 0; i < m; i++)
    {
      dp[m] = new int[n][];
      for (int j = 0; j < n; j++)
      {
        dp[m][n] = new int[k];
      }
    }
    
    return 0;
  }
}
