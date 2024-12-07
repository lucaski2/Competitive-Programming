def P_to_H(P):
    H = []
    while len(P) > 1:
        if P[0] > P[-1]:
            H.append(P[1])
            P = P[1:]
        else:
            H.append(P[-2])
            P = P[:-1]
    return H
 
 
import itertools
 
 
def solve():
    N = int(input())
    H = list(map(int, input().split()))
    for P in itertools.permutations(range(1, N + 1)):
        if P_to_H(P) == H:
            print(" ".join(map(str, P)))
            return
    print(-1)
 
 
T = int(input())
for _ in range(T):
    solve()
