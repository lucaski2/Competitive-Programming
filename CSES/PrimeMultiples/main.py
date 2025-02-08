def pow_mod(a, b, m):
    ans = 1
    while b:
        if b & 1:
            ans = (ans * a) % m
        b //= 2
        a = (a * a) % m
    return ans

def solve(tc):
    n, k = map(int, input().split())
    a = list(map(int, input().split()))
    
    ans = 0
    
    # Iterate through all subsets using bitmasking
    for i in range(1, 1 << k):  # Start from 1 to exclude the empty set
        cnt = 0
        am = 1
        for j in range(k):
            if (1 << j) & i:
                am *= a[j]
                cnt += 1
                # Avoid overflow or unnecessary large computations
                if am > n:
                    break
        
        if am > n:
            continue
        
        if cnt % 2 == 0:
            ans -= n // am
        else:
            ans += n // am
    
    print(ans)

def main():
    t = 1
    for i in range(1, t + 1):
        solve(i)

if __name__ == "__main__":
    main()
