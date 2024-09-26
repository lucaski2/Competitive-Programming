
st = list(input())
letters = {}
for i in range(len(st)):
    if st[i] in letters:
        letters[st[i]] += 1
    else:
        letters[st[i]] = 1
s = 0
c = 0
for letter, amount in letters.items():
    s += (len(st) - 1 - c) * amount
    if amount > 1:
        s += 1
    c += amount
print(s)