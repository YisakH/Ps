import heapq

class Solution:
    def continuousSubarrays(self, nums) -> int:
        N = len(nums)
        answer = 0
        l, r = 0, 0
        maxVal = (nums[0], 0)
        minVal = (nums[0], 0)

        while r < N:
            if maxVal[0] - 2 <= nums[r] <= minVal[0] + 2:
                maxVal = (nums[r], r) if maxVal[0] <= nums[r] else maxVal
                minVal = (nums[r], r) if nums[r] <= minVal[0] else minVal
                r += 1
            else:
                length = r - l + 1
                answer += length * (length - 1) // 2
                if nums[r] < maxVal[0] - 2:
                    length = max(0, r - maxVal[1])
                    l, r = maxVal[1] + 1, maxVal[1] + 1
                else:
                    length = max(0, r - minVal[1])
                    l, r = minVal[1] + 1, minVal[1] + 1
                answer -= length * (length - 1) // 2
                maxVal = (nums[l], l)
                minVal = (nums[l], l)
        
        length = r - l + 1
        answer += length * (length - 1) // 2
        return answer


        

