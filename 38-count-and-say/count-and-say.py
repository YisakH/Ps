class Solution:
    def countAndSay(self, n: int) -> str:
        
        def dfs(n):
            if n == 1:
                return '1'
            elif n == 2:
                return '11'
            
            res = dfs(n-1)
            ans = ''
            cnt = 1
            for i in range(1, len(res)):
                if res[i-1] == res[i]:
                    cnt += 1
                else:
                    ans += str(cnt) + str(res[i-1])
                    cnt = 1
            
            ans += str(cnt) + str(res[-1])
            
            return ans
        
        return dfs(n)