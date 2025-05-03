from collections import defaultdict

class Solution:
    def minDominoRotations(self, tops: List[int], bottoms: List[int]) -> int:
        key = set([tops[0], bottoms[0]])
        top_cnt = defaultdict(int)
        bot_cnt = defaultdict(int)

        
        for i, val in enumerate(zip(tops, bottoms)):
            key &= set(val)

            if not key:
                return -1
            
            top, bot = val

            for candidate in key:
                if top != candidate and bot == candidate:
                    top_cnt[bot] += 1
                if bot != candidate and top == candidate:
                    bot_cnt[top] += 1
            
        answer = float('inf')

        for candidate in key:
            min_val = min(top_cnt[candidate], bot_cnt[candidate])
            answer = min(answer, min_val)

        return answer



