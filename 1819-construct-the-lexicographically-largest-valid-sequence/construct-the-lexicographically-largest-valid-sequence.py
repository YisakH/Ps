class Solution:
    def constructDistancedSequence(self, n: int) -> List[int]:
        answer = [0 for _ in range(2*n-1)]
        
        def dfs(idx, visited):
            if idx == 2 * n - 1:
                return answer

            if answer[idx] != 0:
                return dfs(idx + 1, visited)

            for i in range(n, 1, -1):
                if answer[idx] == 0 and idx + i < 2 * n - 1 and answer[idx + i] == 0 and i not in visited:
                    answer[idx] = i
                    answer[idx + i] = i
                    result = dfs(idx + 1, visited | {(i)})
                    if result:
                        return result

                    answer[idx] = 0
                    answer[idx + i] = 0

            if 1 not in visited:
                answer[idx] = 1
                result = dfs(idx + 1, visited | {(1)})
                if result:
                    return result  # 정답을 찾으면 즉시 반환
                answer[idx] = 0


        return dfs(0, set())
