class Solution:
    def smallestEquivalentString(self, s1: str, s2: str, baseStr: str) -> str:
        parent = [i for i in range(26)]

        def find(n):
            if parent[n] == n:
                return parent[n]
            
            parent[n] = find(parent[n])
            return parent[n]
        
        def union(n1, n2):
            r1 = find(n1)
            r2 = find(n2)

            if r1 <= r2:
                parent[r2] = r1
            else:
                parent[r1] = r2

        for ch1, ch2 in zip(s1, s2):
            ch1 = ord(ch1) - ord('a')
            ch2 = ord(ch2) - ord('a')

            union(ch1, ch2)
        
        ans = [chr(find(ord(ch) - ord('a')) + ord('a')) for ch in baseStr]
        return "".join(ans)
