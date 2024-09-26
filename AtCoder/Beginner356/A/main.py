n, l, r = map(int, input().split())
l -= 1
r -= 1
a = list(range(1,n+1))
try:
    print(*(a[:l] + a[l:r+1][::-1] + a[r+1:]))
except:
    print(*(a[:l] + a[l:r+1][::-1]))
