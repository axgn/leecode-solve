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
        else if (boxGrid[i][j] == '*')
        {
          res[j][m - i] = '*';
          cnt = 0;
        }
      }
    }
    return res;
  }
}
