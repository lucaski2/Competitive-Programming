n, k, x = map(int, input().split())
lst = list(map(int, input().split()))

lst.insert(k, x)
print(*lst)
