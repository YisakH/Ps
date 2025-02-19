class Solution:
    def getHappyString(self, n: int, k: int) -> str:
        # 나올 수 있는 경우의 수 = 3 * 2^(n-1)
        answer = ""
        val = (2 ** (n-1))

        if k <= val:
            answer += 'a'
        elif k <= val * 2:
            answer += 'b'
            k -= val
        elif k <= val * 3:
            answer += 'c'
            k -= 2 * val
        else:
            return answer
        
        while val > 1:
            ch_list = list({'a', 'b', 'c'} - set(answer[-1]))
            ch_list.sort()

            if k <= val // 2:
                answer += ch_list[0]
                val //= 2
            else:
                answer += ch_list[1]
                k -= val // 2
                val //= 2

        return answer
        