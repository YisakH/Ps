class Solution(object):
    def longestMonotonicSubarray(self, nums):
        increase_cnt, decrease_cnt = 1, 1
        answer = 1

        for i in range(1, len(nums)):
            if nums[i] > nums[i-1]:
                increase_cnt += 1
            else:
                increase_cnt = 1
            
            if nums[i] < nums[i-1]:
                decrease_cnt += 1
            else:
                decrease_cnt = 1
            
            answer = max(answer, decrease_cnt, increase_cnt)
        
        return answer
        