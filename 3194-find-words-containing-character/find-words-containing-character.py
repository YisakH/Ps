class Solution:
    def findWordsContaining(self, words: List[str], x: str) -> List[int]:
        answer = []
        for i, w in enumerate(words):
            if x in w:
                answer.append(i)

        return answer