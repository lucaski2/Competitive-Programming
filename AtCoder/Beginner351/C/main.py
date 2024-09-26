
n = int(input())
a = list(map(int, input().split()))

s = []
for i in range(n):
    s.append(a[i])
    while len(s) > 1:
        if s[-1] == s[-2]:
            s.pop()
            s[-1] += 1
        else:
            break
        




print(len(s))