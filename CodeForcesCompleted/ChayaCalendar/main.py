
for _ in range(int(input())):
    n = int(input())
    arr = list(map(int, input().split()))
    time = 0
    ind = 0
    for _ in range(n):
        if time != 0:
            time += arr[ind] - (time % arr[ind])
        else:
            time += arr[ind]
        ind += 1
        ind %= n
    print(time)

