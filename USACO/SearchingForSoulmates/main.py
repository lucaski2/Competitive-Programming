
for _ in range(int(input())):
    a, b = map(int, input().split())

    if a == b:
        print(0)
        continue
    m = 1000000000000

    for i in range(64):
        for j in range(2, 6):
            # eval
            cur_a = a
            ans = i
            for k in range(i):
                if cur_a % 2 == 0:
                    cur_a //= 2
                else:
                    cur_a = (cur_a + 1) // 2
                    ans += 1
            if cur_a == b:
                m = min(ans, m)
                continue
            
            cur_a += j
            cur_b = b
            ans += j
            
            while cur_b > cur_a:
                ans += 1
                if cur_b % 2 == 0:
                    cur_b //= 2
                else:
                    cur_b -= 1
            # print(cur_a, cur_b)
            
            if cur_a == cur_b:
                m = min(ans, m)
    print(m)








