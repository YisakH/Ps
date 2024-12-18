class Solution:
    def finalPrices(self, prices: List[int]) -> List[int]:
        st = []
        answer = prices.copy()

        for i in reversed(range(len(prices))):
            while st and prices[i] < st[-1]:
                st.pop()
            if st:
                answer[i] -= st[-1]
            st.append(prices[i])

        return answer


        