import itertools

s = input()
p = itertools.permutations(s)
p = sorted(set(p))
print(len(p))
for i in p:
    print(''.join(i))