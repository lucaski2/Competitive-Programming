N = 3
A = [list(map(int, input().split())) for _ in range(N)]
a = sum(A, [])
INF = 10**18
line = [
    [0, 1, 2],
    [3, 4, 5],
    [6, 7, 8],
    [0, 3, 6],
    [1, 4, 7],
    [2, 5, 8],
    [0, 4, 8],
    [2, 4, 6],
]


def f(turn, s):
    for l in line:
        if s[l[0]] == s[l[1]] == s[l[2]] == 1:
            return INF
        if s[l[0]] == s[l[1]] == s[l[2]] == 2:
            return -INF
    if turn == N * N:
        s1, s2 = 0, 0
        for i in range(N * N):
            if s[i] == 1:
                s1 += a[i]
            else:
                s2 += a[i]
        return s1 - s2
    if turn % 2 == 0:
        ret = -INF
        for i in range(N * N):
            if s[i] == 0:
                t = s[:]
                t[i] = 1
                ret = max(ret, f(turn + 1, t))
        return ret
    else:
        ret = INF
        for i in range(N * N):
            if s[i] == 0:
                t = s[:]
                t[i] = 2
                ret = min(ret, f(turn + 1, t))
        return ret
    

print('Takahashi' if f(0, [0] * (N * N)) > 0 else 'Aoki')