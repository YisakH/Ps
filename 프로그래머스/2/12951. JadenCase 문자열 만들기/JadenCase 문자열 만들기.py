def solution(s):
    s = s[0].upper() + s[1:]
    
    for i in range(1, len(s)):
        if s[i-1] == " ":
            s = s[:i] + s[i].upper() + s[i+1:len(s)]
        else:
            s = s[:i] + s[i].lower() + s[i+1:len(s)]
    
    return s