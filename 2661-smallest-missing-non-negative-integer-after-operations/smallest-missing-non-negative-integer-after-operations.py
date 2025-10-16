from collections import Counter

class Solution:
    def findSmallestInteger(self, nums: List[int], value: int) -> int:
        for i in range(len(nums)):
            nums[i] = nums[i] % value

        count = Counter(nums)
        MEX = 0

        while True:
            if MEX % value not in count or count[MEX % value] == 0:
                return MEX
            
            count[MEX % value] -= 1
            MEX += 1