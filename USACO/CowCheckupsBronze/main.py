from typing import Optional, Set, TypeVar
from sys import stdin, stdout

T = TypeVar('T')
MOD = 1_000_000_007

def less_or_equal(s: Set[T], value: T) -> Optional[T]:
    if not s:
        return None
    it = list(filter(lambda x: x <= value, s))
    if not it:
        return None
    return max(it)

def pow_mod(a: int, b: int, m: int) -> int:
    ans = 1
    while b:
        if b & 1:
            ans = (ans * a) % m
        b //= 2
        a = (a * a) % m
    return ans

def solve(tc: int) -> None:
    n = int(stdin.readline())
    a = list(map(int, stdin.readline().split()))
    b = list(map(int, stdin.readline().split()))
    
    ans = [0] * (n + 1)
    
    # Case 1: Check all possible ranges centered at each position
    for i in range(n):
        # Count initial matches
        s = sum(1 for j in range(n) if a[j] == b[j])
        ans[s] += 1
        
        # Expand range from center i
        l, r = i - 1, i + 1
        last = s
        while l >= 0 and r < n:
            # Check difference from switch
            before = (a[l] == b[l]) + (a[r] == b[r])
            after = (a[l] == b[r]) + (a[r] == b[l])
            cur = last + (after - before)
            ans[cur] += 1
            last = cur
            l -= 1
            r += 1
    
    # Case 2: Check all possible ranges centered between adjacent positions
    for i in range(n - 1):
        # Count initial matches excluding the pair we're swapping
        s = sum(1 for j in range(n) if j != i and j != i + 1 and a[j] == b[j])
        
        # Add matches after swapping the adjacent pair
        s += (a[i] == b[i + 1]) + (a[i + 1] == b[i])
        ans[s] += 1
        
        # Expand range from center between i and i+1
        l, r = i - 1, i + 2
        last = s
        while l >= 0 and r < n:
            before = (a[l] == b[l]) + (a[r] == b[r])
            after = (a[l] == b[r]) + (a[r] == b[l])
            am = last + (after - before)
            ans[am] += 1
            last = am
            l -= 1
            r += 1
    
    # Print results
    for i in range(n + 1):
        stdout.write(f"{ans[i]}\n")

def main():
    t = 1
    # t = int(input())  # Uncomment for multiple test cases
    for i in range(1, t + 1):
        solve(i)

if __name__ == "__main__":
    main()