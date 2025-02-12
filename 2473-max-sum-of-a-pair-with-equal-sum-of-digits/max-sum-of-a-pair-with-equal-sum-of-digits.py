from collections import defaultdict

class Solution(object):
    def maximumSum(self, nums):
        def getSum(num):
            answer = 0
            while num:
                answer += num % 10
                num //= 10

            return answer

        dic = defaultdict(list)

        for num in nums:
            dic[getSum(num)].append(num)

        answer = -1

        for values in dic.values():
            first, second = -1, -1
            for val in values:
                if val >= first:
                    first, second = val, first
                elif val > second:
                    second = val

            if first > -1 and second > -1:
                answer = max(answer, first + second)


        return answer
        