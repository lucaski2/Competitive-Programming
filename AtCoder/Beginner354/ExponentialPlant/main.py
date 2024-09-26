
n = int(input())
s = 0
am = 0

while n >= s:
    s += pow(2, am)
    am += 1

print(am)

