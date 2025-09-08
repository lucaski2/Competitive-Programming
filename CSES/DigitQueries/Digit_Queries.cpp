import sys
from typing import Optional

def solve(tc: int):
    n = int(sys.stdin.readline().strip())
    
    if n < 10:
        print(n)
        return
    
    n -= 10
    dig = 0
    
    for i in range(1, 19):
        am = 9 * pow(10, i) * (i + 1)
        dig = i
        if am > n:
            break
        n -= am
    
    num = 10 ** dig + (n // (dig + 1))
    rem = n % (dig + 1)
    print(str(num)[rem])

def main():
    sys.stdin = open(0)
    t = int(sys.stdin.readline().strip())
    for i in range(1, t + 1):
        solve(i)

if __name__ == "__main__":
    main()
