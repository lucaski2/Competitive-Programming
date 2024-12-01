
n = int(input())

heights = list(map(int, input().split()))
stalls = list(map(int, input().split()))
heights.sort(reverse=True)
ans = 1
for i in range(n):
  cur = heights[i]
  loc_ans = 0
  for j in range(n):
    if cur <= stalls[j]:
      loc_ans += 1
  ans *= loc_ans
  stalls[stalls.index(max(stalls))] = -1
print(ans)

