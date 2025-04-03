class Solution:
    def maximumTripletValue(self, nums: List[int]) -> int:
        max_left = nums.copy()
        max_right = nums.copy()
        answer = 0

        for i in range(1, len(nums)):
            max_left[i] = max(max_left[i-1], max_left[i])

        for i in range(len(nums)-2, -1, -1):
            max_right[i] = max(max_right[i+1], max_right[i])

        for j in range(1, len(nums)-1):
            res = (max_left[j-1] - nums[j]) * max_right[j + 1]
            answer = max(answer, res)

        return answer