public class Solution
{
  public bool RotateString(string s, string goal)
  {
    return s.Length == goal.Length && new String(s + s).Contains(goal);
  }
}
