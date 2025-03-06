class Solution:
    def findMissingAndRepeatedValues(self, grid: List[List[int]]) -> List[int]:
        n = len(grid)
        nums = set([i for i in range(1, n*n + 1)])
        a, b = -1, -1

        for i in range(n):
            for j in range(n):
                if grid[i][j] in nums:
                    nums.remove(grid[i][j])
                else:
                    a = grid[i][j]
        
        b = list(nums)[0]

        return [a, b]

        