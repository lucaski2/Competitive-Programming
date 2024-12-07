
n = int(input())
a = list(map(int, input().split()))
cur_am = 0
cur_sum = 0
sns = 0
for i in range(n):
  cur_sum += cur_am
  a[i] += cur_sum
  cur_am += -a[i]
  sns += abs(a[i])
  cur_sum +=-a[i]
print(sns)



