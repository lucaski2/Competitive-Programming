
for _ in range(int(input())):
    a = list(input())
    alphabet = "abcdefghijklmnopqrstuvwxyz"
    if len(a) == 1:
        print(alphabet[alphabet.index(a[0]) - 1] + a[0])
        continue
    last = a[0]
    for i in range(1, len(a)):
        if last == a[i]:
            a.insert(i, alphabet[alphabet.index(a[i]) - 1])
            print("".join(a))
            break
        last = a[i]
    else:
        a.append(alphabet[alphabet.index(a[-1]) - 1])
        print("".join(a))