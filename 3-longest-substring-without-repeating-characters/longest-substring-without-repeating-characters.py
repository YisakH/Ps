class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        strdict = dict()
        startIdx = 0
        answer = 0
        for i, ch in enumerate(s):
            if ch not in strdict:
                strdict[ch] = i
            else:
                startIdx = max(strdict[ch] + 1, startIdx)
                strdict[ch] = i
            #print(strdict, startIdx)
            answer = max(answer, i - startIdx + 1)
        
        return answer

