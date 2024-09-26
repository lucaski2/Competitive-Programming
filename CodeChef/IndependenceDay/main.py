for _ in range(int(input())):
    ls = list(map(int, input().split()))
    ls.sort()
    if ls[-1] > ls[0] + ls[1] + 1:
        print("No")
    else:
        print("YES")