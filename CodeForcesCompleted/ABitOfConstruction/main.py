
for _ in range(int(input())):
    n, k = map(int, input().split())
    max_length = len(bin(k)) - 2
    num = 0
    nums = []
    ind = 0
    while n > 1 and k > 0:
        cur_num = 0

        while cur_num <= k:
            if cur_num + pow(2, ind) > k or ind >= max_length:
                break
            cur_num += pow(2, ind)
            ind += 1
        
        num |= cur_num
        nums.append(cur_num)
        k -= cur_num
        n -= 1

    nums.append(k)
    n -= 1
    if n > 0:
        nums.extend([0] * n)
    print(*nums)
        

        


        