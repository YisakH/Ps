class Solution:
    def candy(self, ratings: List[int]) -> int:
        N = len(ratings)
        answer = [1 for _ in range(N)]
        for i in range(1, N):
            if ratings[i-1] < ratings[i]:
                answer[i] = answer[i-1] + 1

        for i in range(N-2, -1, -1):
            if ratings[i] > ratings[i+1]:
                answer[i] = max(answer[i], answer[i+1] + 1) 

        return sum(answer)
        
