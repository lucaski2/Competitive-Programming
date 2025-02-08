for _ in range(int(input())):
  n, k = map(int, input().split())
  a = list(map(int, input().split()))

  costs = [a[i] - (n - i - 1) for i in range(n)]

  costs.sort(reverse=True)
  ans = sum(a) - k * (k - 1) // 2
  print(ans - sum(costs[:k]))