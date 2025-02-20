class Solution:
    def findDifferentBinaryString(self, nums: List[str]) -> str:
        n = len(nums[0])
        visit = set(nums)
        ch_list = ['0', '1']
        answer = ''

        def dfs(idx):
            nonlocal answer
            if idx == n:
                if answer not in visit:
                    return True
                else:
                    return False
            
            for ch in ch_list:
                answer += ch
                if dfs(idx + 1):
                    return True
                answer = answer[:-1]
        
        dfs(0)
        return answer

