import math

for _ in range(int(input())):
  n = int(input())
  if n == 1:
    print(1)
  elif n <= 4:
    print(2)

  else:
    cur_am = 4
    ans = 2
    while cur_am < n:
      ans += 1
      cur_am += cur_am + 2

    print(ans)


