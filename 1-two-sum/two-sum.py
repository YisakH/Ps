class Solution:
    def binSearch(self, nums, target, start):
        l, r = start, len(nums) - 1

        while l <= r:
            m = (l + r) // 2
            if nums[m][0] == target:
                return m
            if nums[m][0] > target:
                r = m - 1
            else:
                l = m + 1
        return -1

    def twoSum(self, nums: List[int], target: int) -> List[int]:
        answer = []
        nums = [[n, i] for i, n in enumerate(nums)]
        nums.sort()

        for l in range(len(nums) - 1):
            r = self.binSearch(nums, target - nums[l][0], l + 1)
            if r >= 0:
                return [nums[l][1], nums[r][1]]
        