
var s = new Solution();
var arr = s.Distance([1, 3, 1, 1, 2]);
foreach (var item in arr)
{
  Console.WriteLine(item);
}
public class Solution
{
  public long[] Distance(int[] nums)
  {
    var n = nums.Length;
    var list_set = new Dictionary<int, List<int>>();
    for (int i = 0; i < n; i++)
    {
      if (!list_set.TryGetValue(nums[i], out var list))
      {
        list = new List<int>();
        list_set[nums[i]] = list;
      }
      list.Add(i);
    }
    var res = new long[n];
    foreach (var kv in list_set)
    {
      long front = 0;
      var list_arr = kv.Value.ToArray();
      long total = 0;
      foreach (var i in list_arr)
      {
        total += i;
      }
      int n = list_arr.Length;
      for (int i = 0; i < n; i++)
      {
        var value = (long)list_arr[i];
        res[value] = total - 2 * front + (2 * i - n) * value;
        front += value;
      }
    }
    return res;
  }
}

