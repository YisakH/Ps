class Solution:
    def constructDistancedSequence(self, n: int) -> List[int]:
        answer = [0 for _ in range(2*n-1)]
        
        used = set() 
        st = [(0, answer)]

        while st:
            curIdx, curanswer = st.pop()
            if curIdx == n * 2 - 1:
                return curanswer
            
            if curanswer[curIdx] != 0:
                st.append((curIdx + 1, curanswer.copy()))
                continue
            
            if 1 not in curanswer:
                curanswer[curIdx] = 1
                st.append((curIdx + 1, curanswer.copy()))
                curanswer[curIdx] = 0
            
            for i in range(2, n+1, 1):
                if i not in curanswer and curIdx + i < 2 * n - 1 and curanswer[curIdx + i] == 0:
                    curanswer[curIdx] = i
                    if i != 1:
                        curanswer[curIdx + i] = i

                    st.append((curIdx + 1, curanswer.copy()))
                    
                    curanswer[curIdx] = 0
                    
                    if i != 1:
                        curanswer[curIdx + i] = 0
