class Solution(object):
    def minimizeXor(self, num1, num2):
        # XOR => 다르면 1, 같으면 0
        cnt = 0
        print(bin(num1))
        print(bin(num2))
        while num2:
            if num2 % 2:
                cnt += 1
            num2 //= 2
        
        x = 0
        seat = 2 ** (len(str(bin(num1))) - 3)

        while seat and cnt:
            if num1 & seat:
                x += seat
                cnt -= 1
            
            seat //= 2
        
        seat = 0
        while cnt:
            if x & (2**seat) == 0:
                x += 2 ** seat
                cnt -= 1
            seat += 1 
        print(bin(x))
        return x
        