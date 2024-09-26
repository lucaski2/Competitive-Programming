


def solve(heights):
    count = 0

    # insertion sort

    for k in range(len(heights)):
        i = k - 1
        key = heights[k]

        while i >= 0 and heights[i] > key:
            heights[i + 1] = heights[i]
            i -= 1
            count += 1

        heights[i + 1] = key

    print(count)


N = int(input())

for i in range(N):
    a = input().split()
    print(a[0], end=' ')

    heights = list(map(int, a[1:]))

    solve(heights)    