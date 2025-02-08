MOD = 1000000007

def power(a, b, m):
    ans = 1
    while b:
        if b & 1:
            ans = (ans * a) % m
        b //= 2
        a = (a * a) % m
    return ans

def solve():
    a, b, c = map(int, input().split())
    bc_mod = power(b, c, MOD)
    result = power(a, bc_mod, MOD)
    print(result)

if __name__ == "__main__":
    import sys
    input = sys.stdin.read
    data = input().splitlines()
    
    t = int(data[0])  # Read number of test cases
    for i in range(1, t + 1):
        a, b, c = map(int, data[i].split())
        bc_mod = power(b, c, MOD)
        result = power(a, bc_mod, MOD)
        print(result)
