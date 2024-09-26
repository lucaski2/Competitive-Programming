
n = int(input())
s = list(input())
possibilities = []

num_zeroes = 0
num_ones = 0
num_twos = 0
nums = 0
for i in range(n):
    if s[i] == "F":
        if i != 0 and i != n - 1 and s[i - 1] == s[i + 1] and s[i - 1] != "F":
            num_zeroes += 1
            num_twos += 1
        elif i == 0 or i == n - 1:
            num_zeroes += 1
            num_ones += 1
        elif i != 0 and i != n - 1 and s[i - 1] == s[i + 1] == "F":
            num_zeroes += 1
            num_twos += 1
            num_ones += 1
        else:
            num_ones += 1
        nums += 1
