
for _ in range(int(input())):

    n = int(input())
    arr = list(map(int, input().split()))

    end_arr = [0] * n

    for i in range(n - 1, -1, -1):
        if i == n - 1:
            end_arr[i] = 1000000000
        else:
            end_arr[i] = end_arr[i + 1] - arr[i]
    
    print(*end_arr)