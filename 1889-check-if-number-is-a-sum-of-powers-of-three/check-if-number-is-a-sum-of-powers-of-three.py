class Solution:
    def checkPowersOfThree(self, n: int) -> bool:
        def dfs(depth, cur_val, n):
            next_val = cur_val + 3 ** depth

            if next_val == n:
                return True
            elif next_val > n:
                return dfs(depth - 1, cur_val, n)
            elif depth == 0:
                return False
        
            return dfs(depth - 1, next_val, n)

        return dfs(15, 0, n)