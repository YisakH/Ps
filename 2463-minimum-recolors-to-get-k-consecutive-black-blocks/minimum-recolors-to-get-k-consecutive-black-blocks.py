class Solution:
    def minimumRecolors(self, blocks: str, k: int) -> int:
        start = 0
        cnt = 0

        for i in range(k):
            if blocks[i] == 'W':
                cnt += 1
        
        answer = cnt

        for end in range(k, len(blocks)):
            if blocks[end] == 'W':
                cnt += 1
            if blocks[start] == 'W':
                cnt -= 1
            
            start += 1
            answer = min(answer, cnt)
        
        return answer

