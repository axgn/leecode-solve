namespace leetcode
{
  class UnionFind
  {
    int size;
    private int[] set;

    public UnionFind(int size)
    {
      this.size = size;
      this.set = new int[this.size];
      for (int i = 0; i < this.size; i++)
      {
        this.set[i] = i;
      }
    }

    public int Find(int x)
    {
      return x == set[x] ? x : set[x] = Find(set[x]);
    }

    public void Union(int x, int y)
    {
      this.set[Find(x)] = Find(y);
    }
  }
}
