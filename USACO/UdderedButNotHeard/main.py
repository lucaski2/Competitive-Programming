
s = list(input())
s2 = list(input())

ind = 0
ans = 0
while ind < len(s2):
  cur_ind = 0
  while cur_ind < len(s) and ind < len(s2):
    if s[cur_ind] == s2[ind]:
      ind += 1
    cur_ind += 1
  ans += 1
print(ans)
