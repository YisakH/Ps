class Solution(object):
    def nextGreatestLetter(self, letters, target):
        for i, l in enumerate(letters):
            if target < l:
                return l
        
        return letters[0]