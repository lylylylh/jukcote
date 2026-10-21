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