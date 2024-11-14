def getPlayTime(start, end):
    [h1, m1] = map(int,start.split(':'))
    [h2, m2] = map(int,end.split(':'))
    return (h2*60 + m2) - (h1*60 + m1)

def solution(m, musicinfos):
    answer = ''
    
    m = m.replace('C#', 'H')
    m = m.replace('D#', 'I')
    m = m.replace('F#', 'J')
    m = m.replace('G#', 'K')
    m = m.replace('A#', 'L')
    m = m.replace('B#', 'M')
    
    
    for i, musicinfo in enumerate(musicinfos):
        [start, end, musicname, code] = musicinfo.split(',')
        playTime = getPlayTime(start, end)
        code = code.replace('C#', 'H')
        code = code.replace('D#', 'I')
        code = code.replace('F#', 'J')
        code = code.replace('G#', 'K')
        code = code.replace('A#', 'L')
        code = code.replace('B#', 'M')
        
        musicinfos[i] = [playTime, musicname, code]
    
    musicinfos.sort(key=lambda x:x[0], reverse=True)
    
    for playTime, musicname, code in musicinfos:
        n = len(code)
        
        if n > playTime:
            code = code[:playTime]
        elif (n < playTime):
            code *= playTime // n
            code += code[:playTime % n]
        
        if m in code:
            return musicname
    
    return "(None)"