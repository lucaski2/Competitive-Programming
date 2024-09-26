
def climbRedSteps(n, k, red_steps):
    dp = [0 for _ in range(n + 1)]
    dp[0] = 1

    for i in range(1, n + 1):
        s = 0
        for j in range(1, k + 1):
            if i - j >= 0:
                s += dp[i - j]
            else:
                break
        
        dp[i] = s if i not in red_steps else 0
        
    
    return dp[-1]


print(climbRedSteps(7, 3, [1, 3, 4]))

