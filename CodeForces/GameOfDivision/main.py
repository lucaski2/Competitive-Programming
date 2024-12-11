
for _ in range(int(input())):
  n, k = map(int, input().split())
  a = list(map(int, input().split()))
  
  for i in range(n):
    found_bad = False
    for j in range(n):
      if i != j and abs(a[i] - a[j]) % k == 0:
        found_bad = True
        break
    if not found_bad:
      print("YES")
      print(i + 1)
      break
  else:
    print("NO")