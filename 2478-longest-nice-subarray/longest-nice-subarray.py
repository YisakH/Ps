class Solution:
    def longestNiceSubarray(self, nums: List[int]) -> int:
        nums = [0] + nums
        xor = nums.copy()
        answer = 0

        #print(list(map(bin, nums)))
        for i in range(1, len(nums)):
            xor[i] ^= xor[i-1]
        
        #print(xor)
        #print(list(map(bin, xor)))
        start, end = 1, 1

        while start <= end and end < len(xor):
            while end < len(xor) and (xor[start - 1] ^ xor[end - 1]) & nums[end] == 0:
                end += 1
            answer = max(answer, end - start)
            start += 1
            end = max(end, start)

        return answer
