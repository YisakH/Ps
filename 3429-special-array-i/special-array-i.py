class Solution(object):
    def isArraySpecial(self, nums):
        parity = nums[0] % 2

        for num in nums[1:]:
            if parity == num % 2:
                return False
            parity = num % 2
        
        return True
        