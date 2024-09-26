
n = int(input())
a = list(map(int, input().split()))
a_even = [0] * n + [0]
a_odd = [0] * n + [0]

for i in range(n):
    a_odd[i + 1] = max(a_odd[i + 1], a_even[i] + a[i])
    if i != 0:
        a_even[i + 1] = max(a_even[i + 1], a_odd[i] + a[i] * 2)
    a_even[i + 1] = max(a_even[i + 1], a_even[i])
    a_odd[i + 1] = max(a_odd[i + 1], a_odd[i])
print(max(a_even[n], a_odd[n]))

