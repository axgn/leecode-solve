Solution s = new Solution();
Console.WriteLine(s.HasValidPath([[2, 4, 3], [6, 5, 2]]));


public class Solution
{
  public bool HasValidPath(int[][] grid)
  {
    Dictionary<(int, int), HashSet<int>> dict = new Dictionary<(int, int), HashSet<int>> {
      { (1, 0), [] }, { (1, 1),[1,3,5]}, { (1, 2),[]}, { (1, 3),[1,4,6]},
      { (2, 0), [2,3,4] }, { (2, 1),[]}, { (2, 2),[2,5,6]}, { (2, 3),[]},
      { (3, 0), [] }, { (3, 1),[]}, { (3, 2),[2,5,6]}, { (3, 3),[1,4,6]},
      { (4, 0), [] }, { (4, 1),[1,3,5]}, { (4, 2),[2,5,6]}, { (4, 3),[]},
      { (5, 0), [2,3,4] }, { (5, 1),[]}, { (5, 2),[]}, { (5, 3),[1,4,6]},
      { (6, 0), [2,3,4] }, { (6, 1),[1,3,5]}, { (6, 2),[]}, { (6, 3),[]},
    };
    Dictionary<int, (int, int)> directions = new Dictionary<int, (int, int)> { { 0, (-1, 0) }, { 1, (0, 1) }, { 2, (1, 0) }, { 3, (0, -1) } };
    int m = grid.Length, n = grid[0].Length;
    bool[][] visted = new bool[m][];
    for (int i = 0; i < m; i++)
    {
      visted[i] = new bool[n];
    }
    if (m == 1 && n == 1)
    {
      return true;
    }
    int x = 0, y = 0;
    int last_direction = -1;
    while (true)
    {
      bool flag = false;
      for (int i = 0; i < 4; i++)
      {
        if (last_direction < 0 || i != (last_direction + 2) % 4)
        {
          foreach (var item in dict[(grid[x][y], i)])
          {
            x += directions[i].Item1;
            y += directions[i].Item2;
            if (x >= 0 && x < m && y >= 0 && y < n && !visted[x][y] && item == grid[x][y])
            {
              flag = true;
              visted[x][y] = true;
              last_direction = i;
              if (x == m - 1 && y == n - 1)
              {
                return true;
              }
              break;
            }
            else
            {
              x -= directions[i].Item1;
              y -= directions[i].Item2;
            }
          }
        }
        if (flag)
        {
          break;
        }
      }
      if (!flag)
      {
        if (grid[0][0] == 4)
        {
          break;
        }
        return false;
      }
    }
    for (int i = 0; i < m; i++)
    {
      visted[i] = new bool[n];
    }
    if (grid[0][0] == 4)
    {
      x = 0;
      y = 0;
      last_direction = 3;
      while (true)
      {
        bool flag = false;
        for (int i = 0; i < 4; i++)
        {
          if (last_direction < 0 || i != (last_direction + 2) % 4)
          {
            foreach (var item in dict[(grid[x][y], i)])
            {
              x += directions[i].Item1;
              y += directions[i].Item2;
              if (x >= 0 && x < m && y >= 0 && y < n && !visted[x][y] && item == grid[x][y])
              {
                flag = true;
                last_direction = i;
                visted[x][y] = true;
                if (x == m - 1 && y == n - 1)
                {
                  return true;
                }
                break;
              }
              else
              {
                x -= directions[i].Item1;
                y -= directions[i].Item2;
              }
            }
          }
          if (flag)
          {
            break;
          }
        }
        if (!flag)
        {
          return false;
        }
      }
    }
    return false;
  }
}
