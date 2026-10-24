# K번째 수 
def solution(array, commands):
    answer = []
    for c in commands:
        answer.append(sorted(array[c[0]-1:c[1]])[c[2]-1])
    return answer


# 가장 큰 수
from functools import cmp_to_key 

def solution(numbers):
    strnums = list(map(str,numbers))
    strnums.sort(key=cmp_to_key(compare))
    answer = ''.join(strnums)
    return "0" if answer[0] =="0" else answer

def compare(a,b):
    if a+b > b+a:
        return -1
    elif b+a > a+b:
        return 1
    else:
        return 0 
