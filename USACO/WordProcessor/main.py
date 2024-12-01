
n, k = map(int, input().split())

words = list(input().split())
cur = []
for i in range(n):
  if sum([len(word) for word in cur]) + len(words[i]) <= k:
    cur.append(words[i])
  else:
    print(' '.join(cur))
    cur = [words[i]]
print(' '.join(cur))

