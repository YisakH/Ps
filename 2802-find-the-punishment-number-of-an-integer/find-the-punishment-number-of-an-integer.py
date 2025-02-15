class Solution(object):
    def punishmentNumber(self, n):
        def check(number, string):
            if number == int(string):
                return True

            for i in range(1, len(string)):
                leftNum = int(string[:i])
                if check(number - leftNum, string[i:]):
                    return True
            
            return False

        answer = 0

        for i in range(1, n+1):
            square = i*i
            if check(i, str(square)):
                answer += square
            
        return answer
            
