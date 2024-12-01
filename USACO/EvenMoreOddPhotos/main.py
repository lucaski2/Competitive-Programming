
n = int(input())
a = list(map(int, input().split()))

odd = 0
even = 0

for i in a:

  if i % 2 == 0:
    even += 1
  else:
    odd += 1

ans = 0
while True:
  if ans % 2 == 0:
    if even > 0:
      even -= 1
    elif odd > 1:
      odd -= 2
    else:
      break
  else:
    if odd > 0 and not (odd == 2 and even == 0):
      odd -= 1
    else:
      break
  ans += 1
print(ans)

