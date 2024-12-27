class Solution:
    def maxScoreSightseeingPair(self, values: List[int]) -> int:
        i = 0
        answer = 0

        for j in range(1, len(values)):
            answer = max(answer, values[i] + i + values[j] - j)
            
            if values[j] + j > values[i] + i:
                i = j

        return answer