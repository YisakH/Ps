class Solution(object):
    def numberOfSubstrings(self, s):
        N = len(s)
        d = {'a':0, 'b':0, 'c':0}
        start = 0
        answer = 0

        for end in range(N):
            d[s[end]] += 1

            while d['a'] and d['b'] and d['c']:
                answer += N - end
                d[s[start]] -= 1
                start += 1
        
        return answer