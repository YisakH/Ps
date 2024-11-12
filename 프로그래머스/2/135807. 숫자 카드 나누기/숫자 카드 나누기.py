def gcd(a, b):
    a, b = (a, b) if a >= b else (b, a)
    if b == 0:
        return 0
    while (b != 0):
        a, b = b, a%b
    return a if a != 1 else 0

def getAllgcd(array):
    g = array[0]
    for i in range(1, len(array)):
        g = gcd(g, array[i])
    
    return g

def solution(arrayA, arrayB):
    answer = 0
    
    gA = getAllgcd(arrayA)
    gB = getAllgcd(arrayB)
    print(gA, gB)
    
    if gA != 0:
        for b in arrayB:
            if b % gA == 0:
                gA = 0
                break
    
    if gB != 0:
        for a in arrayA:
            if a % gB == 0:
                gB = 0
                break
    
    return max(gA, gB)