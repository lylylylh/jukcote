# 완주하지 못한 선수
from collections import Counter

def solution(participant, completion):

    participant = Counter(participant)
    completion = Counter(completion)
    answer = participant - completion
    answer = list(answer.keys())
    return answer[0]


# pokemon
def solution(nums):
    # nums(N): ~10000 (even), item: ~200000, result: max(types) N/2
    # 3,1,2,3,4,5,4,5,5,5 -> 3:2, 1:1, 2:1, 4:2, 5:4 (hashmap)
    # answer => int hashmap's key num
    N = len(nums) / 2 
    hash_a = {}
    for n in nums:
        hash_a[n] = hash_a.get(n,0) + 1
        
    answer = min(N,len(hash_a))
    return answer

# 전화번호부
# try 1 : tree 형태로 짜기 -> over coding (문제 의도는 hash: 전화번호 길이가 각 20임)
# d_0 ,, d_9 -> d_00 (d_000 ,, d_009) ,, d_09 ,, d_90 ,, d_99
# 1. 각 전화번호를 dict 안에 넣는다.
# 2. d[0] = d_0 = {0:d_00} ~ {9:d_09}
# 3. 119: d[1] -> dict 
def solution(phone_book):
    set_phones = set(phone_book)
    for num in set_phones:
        for i in range(1, len(num)):
            if num[:i] in set_phones:
                return False
    return True

# 의상
def solution(clothes):
    d = {}
    for name, kind in clothes:
        if kind not in d:
            d[kind] = set()
        d[kind].add(name)

    answer = 1
    for k in d.keys():
        answer *= len(d[k])+1
    return answer-1
