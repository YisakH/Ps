class Solution:
    def findScore(self, nums: List[int]) -> int:
        nums = [[n, i] for i, n in enumerate(nums)]
        nums.sort()
        answer = 0
        marked = set()
        i = 0
        while len(marked) < len(nums):
            while i < len(nums) and nums[i][1] in marked:
                i += 1
            answer += nums[i][0]
            marked.add(nums[i][1])
            marked.add(max(nums[i][1] - 1, 0))
            marked.add(min(nums[i][1] + 1, len(nums) - 1))
        
        return answer
