n = int(input())
a = list(map(int, input().split()))

for i in range(n):
    cur = [False] * n
    cur_thing = i
    while True:
        if cur[cur_thing]:
            print(cur_thing + 1, end=' ')
            break
        cur[cur_thing] = True
        cur_thing = a[cur_thing] - 1

print()
