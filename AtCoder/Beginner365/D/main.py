n = int(input())
s = list(input())
for i in range(n):
    if s[i] == "R":
        s[i] = 0
    elif s[i] == "P":
        s[i] = 1
    else:
        s[i] = 2
dp = [[0 for _ in range(3)] for _ in range(n + 1)]

for i in range(n):
    for j in range(3):
        if s[i] == j:
            dp[i + 1][j] = 0

        
print(dp)
    


