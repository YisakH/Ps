import re
from functools import cmp_to_key

def compare(a, b):
    a0, b0 = a[0].lower(), b[0].lower()
    a1, b1 = int(a[1]), int(b[1])
    
    if a0 != b0:
        if a0 <= b0:
            return -1
        else:
            return 1
    elif a1 != b1:
        if a1 <= b1:
            return -1
        else:
            return 1
    else:
        return 0

def solution(files):
    answer = []

    for i, file in enumerate(files):
        s = re.split(r'(\D+)(\d+)(.*)', file)
        answer.append([a for a in s if a])
    
    answer.sort(key=cmp_to_key(compare))
    
    return ["".join(i) for i in answer]