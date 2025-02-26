class Solution:
    def maxAbsoluteSum(self, nums: List[int]) -> int:
        total = 0
        max_val = 0  # 초기 누적합 0 포함
        min_val = 0  # 초기 누적합 0 포함
        
        for num in nums:
            total += num
            max_val = max(max_val, total)
            min_val = min(min_val, total)
            
        return max_val - min_val