class Solution:
    def maximumCandies(self, candies: List[int], k: int) -> int:
        
        candies.sort(reverse = True)

        def getAnswer(c, k):
            summ = 0
            for candy in candies:
                child = candy // c

                if child == 0:
                    break
                
                summ += child

                if summ >= k:
                    return True
            
            return False
        
        l , r = 1, candies[0]
        max_answer = 0

        while l <= r:
            m = (l + r) // 2
            
            if getAnswer(m, k):
                l = m + 1
                max_answer = max(max_answer, m)
            else:
                r = m - 1
        
        return max_answer
