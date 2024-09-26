n = int(input())
arr = list(map(int, input().split()))
s = 0
for i in range(1, n):
    if arr[i] < arr[i-1]:
        s += arr[i-1] - arr[i]
        arr[i] = arr[i-1]
    
print(s)