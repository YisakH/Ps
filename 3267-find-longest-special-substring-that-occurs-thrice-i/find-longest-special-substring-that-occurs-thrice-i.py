class Solution:
    def maximumLength(self, s: str) -> int:
        answer = 0
        #found = set()
        i = 0
        while i < len(s):
            j = i
            while j < len(s):
                if s[j] != s[i]:
                    break
                #if s[i:j+1] in found:
                #    j += 1
                #    continue
                #print(i, j)
                #found.add(s[i:j+1])
                cnt = 0
                findIdx = i
                while True:
                    findIdx = s.find(s[i:j+1], findIdx)
                    if findIdx < 0:
                        break
                    findIdx += 1
                    cnt += 1
                    if cnt >= 3:
                        break
                if cnt >= 3:
                    answer = max(answer, j - i + 1)
                j += 1
            i = max(j, i + 1)
                
        return answer if answer else -1