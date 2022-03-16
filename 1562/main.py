from sympy import N



def func(N):
    arr = [0, 1, 1, 1, 1, 1, 1, 1, 1, 1]
    new_arr = [0 for i in range(10)]

    for i in range(N):
        for i in range(10):

            if i == 0 and arr[i] != 0:
                new_arr[1] += arr[0]
            elif i == 9:
                new_arr[8] += arr[9]
            elif i > 0:
                new_arr[i-1] += arr[i]
                new_arr[i+1] += arr[i]
        
        arr = new_arr[:]
    
    return sum(new_arr)

print(func(10))

result = 0
for i in range(41):
    result += func(i)

print(result)

print(func(10))

