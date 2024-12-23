from bisect import bisect_left, bisect_right

def solve():
    # Read input
    n, x, y = map(int, input().split())
    a = list(map(int, input().split()))

    s = sum(a)
    if s <= x:
        print(0)
        return

    a.sort()
    temp = x
    x = s - y
    y = s - temp

    ans = 0
    for i in range(n):
        # Perform binary search on the range [0, i) without slicing
        l_bound = bisect_left(a, x - a[i], 0, i)
        u_bound = bisect_right(a, y - a[i], 0, i) - 1

        if l_bound <= u_bound:
            ans += (u_bound - l_bound + 1)

    print(ans)

if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        solve()