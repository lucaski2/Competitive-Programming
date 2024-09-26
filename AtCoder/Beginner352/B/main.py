a = list(input())
b = list(input())

ind = 0
for i in range(len(b)):

    if b[i] == a[ind]:
        print(i + 1, end=' ')
        ind += 1

print()