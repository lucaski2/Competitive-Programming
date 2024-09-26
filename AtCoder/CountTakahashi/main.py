n = int(input())
cnt = 0
for i in range(n):
    s = input()
    if s[0] == "T":
        cnt += 1

print(cnt)