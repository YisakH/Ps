def solution(beginning, target):
    R = len(beginning)
    C = len(beginning[0])
    
    # 두 배열의 차이를 XOR로 계산 (0: 같음, 1: 다름)
    diff = [[beginning[i][j] ^ target[i][j] for j in range(C)] for i in range(R)]
    
    def count_flips(standard_row):
        row_flips = 0
        inverse_standard = [1 - x for x in standard_row]
        
        for i in range(R):
            if diff[i] == standard_row:
                continue  # 기준과 같으면 해당 행은 뒤집을 필요 없음
            elif diff[i] == inverse_standard:
                row_flips += 1  # 기준과 정반대면 해당 행을 뒤집어야 함
            else:
                return float('inf')  # 기준과 같지도, 반대도 아니면 불가능한 경우
                
        # (행 뒤집기 횟수) + (열 뒤집기 횟수: standard_row의 1의 개수)
        return row_flips + sum(standard_row)

    # 경우 1: 첫 번째 행을 안 뒤집는다고 가정 (기준: diff[0])
    case_1 = count_flips(diff[0])
    
    # 경우 2: 첫 번째 행을 뒤집는다고 가정 (기준: diff[0]의 반전)
    case_2 = count_flips([1 - x for x in diff[0]])
    
    answer = min(case_1, case_2)
    return answer if answer != float('inf') else -1