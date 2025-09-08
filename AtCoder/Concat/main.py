import itertools

n, k, x = map(int, input().split())

strs = [input() for _ in range(n)]

lex = []

for ele in itertools.permutations(strs, k):
  s = ""
  for a in ele:
    s += a
  lex.append(s)

lex.sort()
print(lex)
print(lex[x - 1])




