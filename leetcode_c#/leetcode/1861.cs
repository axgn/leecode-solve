var s = new Solution();
Console.WriteLine(s.RotateTheBox([['#', '.', '#']]));

public class Solution
{
  public char[][] RotateTheBox(char[][] boxGrid)
  {
    int m = boxGrid.Length;
    int n = boxGrid[0].Length;
    char[][] res = new char[n][];
    for (int i = 0; i < n; i++)
    {
      res[i] = new char[m];
      for (int j = 0; j < m; j++)
      {
        res[i][j] = '.';
      }
    }
    for (int i = 0; i < m; i++)
    {
      int cnt = 0;
      for (int j = 0; j < n; j++)
      {
        if (boxGrid[i][j] == '#')
        {
          cnt++;
        }
        if (boxGrid[i][j] == '*')
        {
          res[j][m - 1 - i] = '*';
          for (int k = 1; k <= cnt; k++)
          {
            res[j - k][m - 1 - i] = '#';
          }
          cnt = 0;
        }
        else if (j == n - 1)
        {
          for (int k = 0; k < cnt; k++)
          {
            res[j - k][m - 1 - i] = '#';
          }
          cnt = 0;
        }
      }
    }
    return res;
  }
}
