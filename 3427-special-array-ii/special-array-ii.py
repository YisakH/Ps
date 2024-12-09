class Solution:
    def isArraySpecial(self, nums: List[int], queries: List[List[int]]) -> List[bool]:
        parity = [0 for _ in nums]
        p = nums[0] % 2

        for i in range(1,len(nums)):
            if nums[i-1] % 2 == nums[i] % 2:
                parity[i] = parity[i-1] + 1
            else:
                parity[i] = parity[i-1]       

        answer = []
        for start, end in queries:
            if parity[end] == parity[start]:
                answer.append(True)
            else:
                answer.append(False)
        
        return answer

        