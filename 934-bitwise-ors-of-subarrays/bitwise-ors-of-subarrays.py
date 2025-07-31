class Solution:
    def subarrayBitwiseORs(self, arr):
        result = set()   # 최종 distinct OR 값 저장
        prev = set()     # 이전까지의 subarray OR 값 저장

        for num in arr:
            # 현재 num을 추가했을 때 가능한 모든 OR값 갱신
            curr = {num}
            for p in prev:
                curr.add(p | num)

            result.update(curr)
            prev = curr  # 현재 OR 결과를 다음에 넘김

        return len(result)



