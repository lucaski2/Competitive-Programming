
for _ in range(int(input())):
    n = int(input())
    a = list(map(int, input().split()))
    for i in range(n - 1):
        j = i + 1
        if i != j:
            if abs(a[i] - a[j]) != 7 and abs(a[i] - a[j]) != 5:
                print("NO")
                break
    else:
        print("YES")