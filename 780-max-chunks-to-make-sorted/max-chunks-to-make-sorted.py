class Solution:
    def checkSorted(self, arr, start, end):
        for i in range(start, end + 1):
            if arr[i] != -1:
                return arr[i]
        return start

    def maxChunksToSorted(self, arr: List[int]) -> int:
        answer = [-1 for _ in arr]
        arr = [(num, i) for i, num in enumerate(arr)]
        arr.sort()
        for to, (val, origin) in enumerate(arr):
            (to, origin) = (to, origin) if to <= origin else (origin, to)
            key = self.checkSorted(answer, to, origin)
            
            for i in range(to, origin + 1):
                answer[i] = key

        return len(set(answer))
