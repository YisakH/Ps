class Solution:
    def maxAbsoluteSum(self, nums: List[int]) -> int:
        total_sum = 0
        max_val = -float('inf')
        min_val = float('inf')
        answer = 0

        for i in range(len(nums)):
            total_sum += nums[i]

            if i != 0:
                cur_max = max(
                    abs(total_sum - min_val),
                    abs(total_sum - max_val)
                )
            else:
                cur_max = abs(total_sum)

            answer = max(answer, cur_max)
            answer = max(answer, abs(total_sum))
            max_val = max(max_val, total_sum) 
            min_val = min(min_val, total_sum)
            
        return answer