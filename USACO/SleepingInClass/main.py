
for _ in range(int(input())):
    n = int(input())
    a = list(map(int, input().split()))
    s = sum(a)
    for i in range(n, 0, -1):
        if s % i == 0:
            # print(i)
            cur_s = 0
            for j in range(n):
                cur_s += a[j]
                if cur_s == s // i:
                    cur_s = 0
                elif cur_s > s // i:
                    break
            else:
                print(n - i)
                break
    
