class Solution:
    def minOperations(self, grid: List[List[int]], x: int) -> int:
        arr = sum(grid, [])
        arr.sort()
        n = len(arr)

        for i in range(len(arr)):
            if (arr[i] - arr[0]) % x:
                return -1
            
        return sum([abs(num - arr[n // 2]) // x for num in arr])