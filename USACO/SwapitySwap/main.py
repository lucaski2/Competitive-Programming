
def transform(cur, a1, a2, b1, b2):
    # reverse the order of the elements between a1 and a2
    cur[a1 - 1:a2] = cur[a1 - 1:a2][::-1]
    # reverse the order of the elements between b1 and b2
    cur[b1 - 1:b2] = cur[b1 - 1:b2][::-1]


n, k = map(int, input().split())

start = list(range(1, n + 1))
a = list(range(1, n + 1))
a1, a2 = map(int, input().split())
b1, b2 = map(int, input().split())

transform(a, a1, a2, b1, b2)

am = 1

while a != start:
    transform(a, a1, a2, b1, b2)
    am += 1

k %= am

for i in range(k):
    transform(start, a1, a2, b1, b2)
print(*start, sep='\n')



