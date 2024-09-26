
for _ in range(int(input())):
    
    n = int(input())

    arr = list(map(int, input().split()))

    largest, s = 0, 0
    count = 0

    for i in range(n):
        largest = max(largest, arr[i])
        s += arr[i]

        if s - largest == largest:
            count += 1
    
    print(count)
