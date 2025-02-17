from collections import Counter

class Solution:
    def numTilePossibilities(self, tiles: str) -> int:
        count = Counter(tiles)
        global answer
        answer = 0

        def dfs(length):
            global answer
            for key, val in count.items():
                if val == 0:
                    continue
                
                count[key] -= 1
                answer += 1
                dfs(length + 1)

                count[key] += 1
        
        dfs(0)
        return answer


