from math import sqrt

class Solution(object):
    def sumFourDivisors(self, nums):
        answer = 0
        
        for num in nums:
            cnt = set()
            for i in range(1, int(sqrt(num)) + 1):
                if num % i == 0:
                    cnt.add(i)
                
                if len(cnt) > 2:
                    break
            
            if len(cnt) == 2:
                cnt = cnt | {num // j for j in cnt}
            
            if len(cnt) == 4:
                answer += sum(cnt)

        return answer
