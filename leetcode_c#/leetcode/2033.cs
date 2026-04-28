public class Solution
{
  public int MinOperations(int[][] grid, int x)
  {
    int m = grid.Length, n = grid[0].Length;
    int[] nums = new int[m * n];
    for (int i = 0; i < m; i++)
    {
      for (int j = 0; j < n; j++)
      {
        nums[i * n + j] = grid[i][j];
      }
    }
    nums.Sort();
    int target = nums[m * n / 2];
    int sum = 0;
    foreach (var item in nums)
    {
      if (sum == -1)
      {
        break;
      }
      if (item < target)
      {
        int temp = (target - item) / x;
        // sum = temp * x == (target - item) ? sum + temp : -1;
        sum = (target - item) % x == 0 ? sum + temp : -1;
      }
      else
      {
        int temp = (item - target) / x;
        // sum = temp * x == (item - target) ? sum + temp : -1;
      }
    }
    return sum;
  }
}
