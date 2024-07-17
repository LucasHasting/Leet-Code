from functools import lru_cache

class Solution:
    @lru_cache(maxsize=45)
    def climbStairs(self, n: int) -> int:
        if(n <= 2):
            return n
        else:
            return self.climbStairs(n-1) + self.climbStairs(n-2)
