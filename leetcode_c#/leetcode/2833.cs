Solution s = new Solution();
s.FurthestDistanceFromOrigin("123");

public class Solution
{
  public int FurthestDistanceFromOrigin(string moves)
  {
    int n = moves.Length;
    Dictionary<char, int> dict = new Dictionary<char, int> { { 'L', 0 }, { 'R', 0 }, { '_', 0 } };
    int max = 0;
    for (int i = 0; i < n; i++)
    {
      char s = moves[i];
      // if (i != 0 && s != moves[i - 1])
      // {
      //   max = Math.Max(max, Math.Max(dict['L'], dict['R']) - Math.Min(dict['L'], dict['R']) + dict['_']);
      // }
      dict[s]++;
    }
    max = Math.Max(max, Math.Max(dict['L'], dict['R']) - Math.Min(dict['L'], dict['R']) + dict['_']);
    return max;
  }
}
