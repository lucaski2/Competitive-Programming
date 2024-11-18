
for _ in range(int(input())):
    n = int(input())
    arr = [1]
    for i in range(1, n):
        arr.append(arr[-1] * 3)
        if arr[-1] > 10**9:
            print("NO")
            break
    else:
        print("YES")
        print(*arr)