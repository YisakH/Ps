class Solution:
    def smallestNumber(self, pattern: str) -> str:
        used = set()
        answer = []

        def dfs(idx):
            if idx == len(pattern) + 1:
                return True

            for i in range(1, 10):
                if i in used:
                    continue
                
                if idx != 0:
                    if pattern[idx-1] == 'I' and answer[-1] >= i:
                        return False
                    elif pattern[idx-1] == 'D' and answer[-1] <= i:
                        return False


                used.add(i)
                answer.append(i)



                if dfs(idx + 1):
                    return True
                
                answer.pop()
                used.remove(i)
            
            return False
        
        dfs(0)

        return "".join([str(i) for i in answer])
