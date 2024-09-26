N = int(input())
lst = list(map(int, input().split()))
last = []
while True:

    for i in range(len(lst) - 1):

        if (i >= len(lst) - 1):
            break
        if (lst[i] + lst[i + 1]) % 2 == 0:
            lst.pop(i)
            lst.pop(i)
    if lst == last:
        break
    last = lst.copy()

print(len(lst))

