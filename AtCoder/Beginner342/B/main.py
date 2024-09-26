n = int(input())
positions = list(map(int, input().split()))
q = int(input())

for i in range(q):
    a, b = map(int, input().split())
    print(a if positions.index(a) < positions.index(b) else b)
    


