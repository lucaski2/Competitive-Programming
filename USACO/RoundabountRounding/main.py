
def chain_round(n):
  # use chain rounding
  orig_n = n
  cur = 1
  while cur <= orig_n:
    cur *= 10
    n += norm_round(n, cur) - n
  return n

def norm_round(n, place=0):
  # use normal rounding
  if place == 0:
    # place is the minimum place >= n
    place = 1
    while place < n:
      place *= 10
  if n % place == 0:
    return n
  if n % place < place // 2:
    return n - n % place
  return n + place - n % place


# amounts = [0 for _ in range(10**6+2)]


# for i in range(2, 10**6 + 1):
#   a = chain_round(i)
#   b = norm_round(i)
#   if a != b:
#     amounts[i] += 1
#   amounts[i] += amounts[i-1]


# for _ in range(int(input())):
#   n = int(input())
#   print(amounts[n] - len(str(n)) + 1)

for i in range(int(input())):
  n = int(input())
  m = 1
  ans = 0
  while m < n:
    m *= 10
    cur_m = m
    cur_m = list(str(cur_m))
    for i in range(len(cur_m)):
      cur_m[i] = '4'
    cur_m = int(''.join(cur_m[1:]))
    ans += max(0, min(m // 2 - 1, n) - cur_m)
    # print(cur_m, m)
  print(ans)

