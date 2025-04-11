class Solution:
    def countSymmetricIntegers(self, low: int, high: int) -> int:
        cnt = 0

        for num in range(low, high + 1):
            st_num = str(num)

            if len(st_num) % 2:
                continue
            
            left = st_num[:len(st_num) // 2]
            right = st_num[len(st_num)//2:]

            if sum(map(int, left)) == sum(map(int, right)):
                cnt += 1
        
        return cnt