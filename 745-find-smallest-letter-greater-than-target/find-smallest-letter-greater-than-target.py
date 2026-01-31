class Solution(object):
    def nextGreatestLetter(self, letters, target):
        for i, k in enumerate(letters):
            if target < k:
                return k
        
        return letters[0]