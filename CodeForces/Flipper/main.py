def solve():
    n = int(input())
    p = list(map(int, input().split()))

    r = 0
    for i in range(n):
        if p[min(n-1, r+1)] <= p[min(n-1, i+1)]:
            r = i

    ans = []
    for i in range(r + 1, n):
        ans.append(p[i])
    ans.append(p[r])

    for i in range(r - 1, -1, -1):
        if p[i] > p[0]:
            ans.append(p[i])
        else:
            for j in range(i + 1):
                ans.append(p[j])
            break

    print(' '.join(map(str, ans)))

def main():
    t = int(input())
    for _ in range(t):
        solve()

if __name__ == "__main__":
    main()