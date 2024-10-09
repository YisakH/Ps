from collections import Counter

def get_multi(str1):
    return sorted([str1[i:i+2].lower() for i in range(len(str1) - 1) if str1[i:i+2].isalpha()])
        
def solution(str1, str2):
    arr1 = get_multi(str1)
    count1 = Counter(arr1)
    
    arr2 = get_multi(str2)
    count2 = Counter(arr2)
    
    val1 = sum((count1 & count2).values())
    val2 = sum((count1 | count2).values())
    if val2 == 0:
        val1, val2 = 1, 1
    
    return int((val1 / val2) * 65536)