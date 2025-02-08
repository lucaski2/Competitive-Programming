from itertools import combinations
a = list(map(int, input().split()))

scores = []
for i in range(1, 6):
  for comb in combinations(range(0, 5), i):
    st = "ABCDE"
    cur = ""
    s = 0
    for asdf in comb:
      cur += st[asdf]
      s += a[asdf]
    
    scores.append((s, cur))

scores.sort(key=lambda x:-x[0])
for cur in scores:
  print(cur[1], end=' ')
print()


