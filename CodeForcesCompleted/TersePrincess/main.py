
n, a, b = map(int, input().split())

seq = []
if b != 0 or a == 0:
    for i in range(n):
        if i == 0:
            seq.append(1)
        elif b > 0:
            seq.append(seq[-1] * 2)
            b -= 1
        elif a > 0:
            seq.append(seq[-1] + 1)
            a -= 1
        else:
            seq.append(seq[-1])

    if max(seq) > 50000:
        print(-1)
    else:
        print(*seq)
else:
    if a == n - 1:
        print(-1)
    else:
        seq = [1, 1]
        s = 2
        m = 1
        for i in range(2, n):
            if b > 0:
                seq.append(s + 1)
                m = s + 1
                s += m
                b -= 1
            elif a > 0:
                seq.append(m + 1)
                m += 1
                s += m
                a -= 1
            else:
                seq.append(1)
        print(*seq)

# n, ohs, wows = map(int, input().split())

# if ohs == n - 1:
#     print(-1)
# elif ohs != 0 and wows == 0:
#     ans = [1, 1]
#     m = 1
#     s = 2
#     for i in range(2, n):
#         if wows > 0:
#             wows -= 1
#             ans.append(s + 1)
#             m = s + 1
#             s += s + 1
#         elif ohs > 0:
#             ohs -= 1
#             ans.append(m + 1)
#             m += 1
#             s += m
#         else:
#             ans.append(1)
#             s += 1
#     print(*ans)




