class Solution:
    def countDays(self, days: int, meetings: List[List[int]]) -> int:
        
        meetings.sort()
        before = 0
        answer = 0

        for s, e in meetings:
            if before + 1 < s:
                answer += s - before - 1
            
            before = max(before, e)
        
        answer += days - before

        return answer