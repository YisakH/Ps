class Solution:
    def constructDistancedSequence(self, n: int) -> List[int]:
        length = 2 * n - 1  # 결과 배열 길이
        answer = [0] * length  # 초기 배열을 0으로 채움
        used = set()  # 사용된 숫자를 추적

        def dfs(index: int) -> bool:
            # 배열이 다 채워졌으면 정답 반환
            if index == length:
                return True
            
            # 이미 숫자가 채워진 경우, 다음으로 진행
            if answer[index] != 0:
                return dfs(index + 1)

            # 큰 숫자부터 배치하여 사전순 최대 보장
            for num in range(n, 1, -1):
                if num not in used and index + num < length and answer[index + num] == 0:
                    answer[index] = answer[index + num] = num
                    used.add(num)

                    if dfs(index + 1):
                        return True  # 정답을 찾으면 바로 종료

                    # 백트래킹: 원상복구
                    answer[index] = answer[index + num] = 0
                    used.remove(num)

            # 숫자 1은 단 한 번만 사용되므로, 따로 처리
            if 1 not in used:
                answer[index] = 1
                used.add(1)

                if dfs(index + 1):
                    return True

                # 백트래킹
                answer[index] = 0
                used.remove(1)

            return False  # 실패 시 False 반환

        dfs(0)
        return answer