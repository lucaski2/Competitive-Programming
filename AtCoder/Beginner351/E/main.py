
n = int(input())
coords = [tuple(map(int, input().split())) for _ in range(n)]

sum_odd = []
sum_even = []

for i in range(n):
    if sum(coords[i]) % 2 == 0:
        sum_even.append(coords[i])
    
    else:
        sum_odd.append(coords[i])









