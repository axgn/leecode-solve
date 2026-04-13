from functools import reduce
import operator
from typing import List

class Solution:
    def xorAfterQueries(self, nums: List[int], queries: List[List[int]]) -> int:
      mod = 10 ** 9 + 7
      for ele in queries:
          l,r,k,v = ele
          for i in range(l,r + 1,k):
              nums[i] = (nums[i] * v) % mod
      return reduce(operator.xor,nums)
          


s = Solution()

s.xorAfterQueries([1,2,3],[[1,2,3,4],[4,5,6,7]])
