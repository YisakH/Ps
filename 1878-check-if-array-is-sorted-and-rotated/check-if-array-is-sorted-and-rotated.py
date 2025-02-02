class Solution(object):
    def check(self, nums):
        start_val = min(nums)
        start_idx = nums.index(start_val)

        if start_idx == 0:
            for i in range(1, len(nums)):
                if nums[(start_idx - 1) % len(nums)] != start_val:
                    break
                
                start_idx = (start_idx - 1) % len(nums)

        for i in range(len(nums) - 1):
            idx = (start_idx + i) % len(nums)
            next_idx = (start_idx + i + 1) % len(nums)

            if nums[idx] > nums[next_idx]:
                return False
            
        return True

        