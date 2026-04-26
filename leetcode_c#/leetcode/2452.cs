
public class Solution
{
  public IList<string> TwoEditWords(string[] queries, string[] dictionary)
  {
    IList<string> res = [];
    foreach (var query in queries)
    {
      foreach (var word in dictionary)
      {
        int cnt = 0;
        int n1 = word.Length;
        int n2 = word.Length;
        if (n1 != n2)
        {
          continue;
        }
        for (int i = 0; i < n1; i++)
        {
          if (word[i] != query[i])
          {
            cnt++;
            if (cnt > 2)
            {
              break;
            }
          }
        }
        if (cnt <= 2)
        {
          res.Add(query);
          break;
        }
      }
    }
    return res;
  }
}
