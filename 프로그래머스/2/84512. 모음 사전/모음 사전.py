def makeword(target, word, depth, dic):
    if depth == 5 or target in dic:
        return
        
    order = {0:" ", 1:"A", 2:"E", 3:"I", 4:"O", 5:"U"}
    
    if depth == 0:
        for i in range(1, 6):
            word += order[i]
            dic[word] = len(dic) + 1 
            makeword(target, word, depth + 1, dic)
            word = word[:-1]
            
    else:
        for i in range(1, 6):
            word += order[i]
            dic[word] = len(dic) + 1
            makeword(target, word, depth + 1, dic)
            word = word[:-1]
    

def solution(word):
    answer = 0
    dic = {}
    makeword(word, "", 0, dic)

    return dic[word]