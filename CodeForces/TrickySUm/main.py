
for _ in range(int(input())):
    n = int(input())
    max_power_of_2 = 0
    while 2 ** (max_power_of_2 + 1) <= n:
        max_power_of_2 += 1
    
    print((n * (n + 1)) // 2 - 2 * (2 ** (max_power_of_2 + 1) - 1))