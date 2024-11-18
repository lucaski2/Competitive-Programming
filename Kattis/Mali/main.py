
n = int(input())
a = [0] * 101
b  = [0] * 101
for i in range(n):
    x, y = map(int, input().split())
    a[x] += 1
    b[y] += 1

    ptr1 = 0
    ptr2 = 100

    ans = 0
    cur_a = a.copy()
    cur_b = b.copy()

    while ptr1 < 101 and ptr2 >= 0:
        if cur_a[ptr1] == 0:
            ptr1 += 1
        elif cur_b[ptr2] == 0:
            ptr2 -= 1
        else:
            ans = max(ans, ptr1 + ptr2)
            am = min(cur_a[ptr1], cur_b[ptr2])
            cur_a[ptr1] -= am
            cur_b[ptr2] -= am
    
    print(ans)




