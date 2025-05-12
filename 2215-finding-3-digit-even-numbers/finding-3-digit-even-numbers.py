from itertools import permutations

class Solution:
    def findEvenNumbers(self, digits: List[int]) -> List[int]:
        nums = list({
            a * 100 + b * 10 + c
            for a, b, c in permutations(digits, 3)
            if a != 0 and c % 2 != 1
        })

        nums.sort()
        return nums