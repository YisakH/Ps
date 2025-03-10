from bisect import bisect_left
import math

class Solution:
    def countOfSubstrings(self, word: str, k: int) -> int:
        n = len(word)
        vowels = set("aeiou")
        
        # cons_prefix[j]: number of consonants in word[:j] (j=0..n)
        cons_prefix = [0] * (n + 1)
        for i in range(n):
            cons_prefix[i+1] = cons_prefix[i] + (0 if word[i] in vowels else 1)
        
        # Build dictionary: for each prefix value, store indices j (0<=j<=n) where cons_prefix[j] == value.
        pos = {}
        for j, val in enumerate(cons_prefix):
            pos.setdefault(val, []).append(j)
        
        # Precompute vowel_req: for each starting index i in word,
        # vowel_req[i] = smallest ending index j (j is 1-indexed in our substring notation)
        # such that substring word[i:j] (j exclusive) contains every vowel at least once.
        # 만약 i부터 모든 모음이 등장하지 않으면 math.inf로 표시합니다.
        vowel_req = [math.inf] * n
        # last occurrence for each vowel (최소 index 저장; 뒤에서부터 갱신)
        last = {v: math.inf for v in vowels}
        # 뒤에서 앞으로 탐색: i부터 시작할 때 이후에 등장하는 각 모음의 첫 등장 index는 last[v] 입니다.
        # 따라서 vowel_req[i] = max( last[v] for v in vowels ) + 1  (모든 모음이 포함되려면)
        for i in range(n - 1, -1, -1):
            if word[i] in vowels:
                last[word[i]] = i
            # 만약 모든 모음에 대해 last[v]가 math.inf가 아니라면 모두 등장한 것
            req = max(last[v] for v in "aeiou")
            if req != math.inf:
                vowel_req[i] = req + 1  # substring [i: req+1]에 모든 모음 포함됨
        
        ans = 0
        # 각 시작 index i에 대해, substring [i:j]가 유효한지 체크 (j는 cons_prefix 배열의 인덱스, 즉 j는 substring의 길이)
        for i in range(n):
            # 만약 i부터 모든 모음이 등장하지 않으면 break (앞으로도 불가능)
            if vowel_req[i] == math.inf:
                continue
            target = cons_prefix[i] + k  # cons_prefix[j]가 target이어야 substring[i:j]에 자음이 정확히 k개
            if target not in pos:
                continue
            # j는 반드시 i+1 이상이어야 합니다.
            candidate = max(i + 1, vowel_req[i])
            L = pos[target]
            # 이분탐색으로 candidate 이상의 인덱스가 몇 개 있는지 구합니다.
            idx = bisect_left(L, candidate)
            ans += len(L) - idx
        
        return ans