class Solution:
    def kthCharacter(self, k: int) -> str:
        init = [0]

        while len(init) < k:
            added = []

            for num in init:
                added.append((num + 1) % 26)
            init += added
            
        return chr(init[k - 1] + ord('a'))