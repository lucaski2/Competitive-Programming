
ans = 0

rest = [] 
for i in range(28):
  if i < 21:
    rest.append(list(map(int, input().split("|"))))
  elif i == 21:
    input()
  else:
    cur = list(map(int, input().split(",")))
    ok = False
    for r in rest:
      if r[0] in cur and r[1] in cur and cur.index(r[0]) >= cur.index(r[1]):
        ok = True
        cur[cur.index(r[0])], cur[cur.index(r[1])] = cur[cur.index(r[1])], cur[cur.index(r[0])]
    if ok:

      ans += cur[len(cur) // 2]
print(ans)