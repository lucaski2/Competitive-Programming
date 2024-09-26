N = int(input())

for i in range(N):
    n, d, h = map(int, input().split())

    heights = set(map(int, input().split()))
    print(len(heights) * d * h * 0.5)



