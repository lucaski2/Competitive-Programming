n, m = map(int, input().split())
a = list(map(int, input().split()))

x = [list(map(int, input().split())) for _ in range(n)]

for i in range(m):
    if sum([x[j][i] for j in range(n)]) < a[i]:
        print("No")
        exit()
    

print("Yes")






