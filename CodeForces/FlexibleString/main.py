import sys
import itertools

def pow_mod(a, b, m):
    ans = 1
    while b:
        if b & 1:
            ans = (ans * a) % m
        b //= 2
        a = (a * a) % m
    return ans

def solve(tc):
    n, k = map(int, sys.stdin.readline().split())
    temp1 = sys.stdin.readline().strip()
    temp2 = sys.stdin.readline().strip()
    
    a = [ord(c) - ord('a') for c in temp1]
    b = [ord(c) - ord('a') for c in temp2]
    
    if tc != 1:
        return
    
    s = set(a[:k])
    chars = list(s)
    
    combs = list(itertools.combinations(chars, min(k, len(chars))))
    
    ans = 0
    for comb in combs:
        is_true = [False] * 26
        for el in comb:
            is_true[el] = True
        
        am = 0
        cur_am = 0
        for i in range(n):
            if a[i] == b[i] or is_true[a[i]]:
                cur_am += 1
            else:
                am += (cur_am * (cur_am + 1)) // 2
                cur_am = 0
        
        if cur_am > 0:
            am += (cur_am * (cur_am + 1)) // 2
        
        ans = max(ans, am)
    
    print(len(combs))
    print(ans)

def main():
    sys.stdin = open(0)  # Use standard input
    t = int(sys.stdin.readline())
    for i in range(1, t + 1):
        solve(i)

if __name__ == "__main__":
    main()
