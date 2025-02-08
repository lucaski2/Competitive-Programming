import sys
import math

input = sys.stdin.read
output = sys.stdout.write

data = input().split()
t = int(data[0])  # Number of test cases
results = []

for _ in range(t):
    n = int(data[_ + 1])

    for multiplicity in range(3, 60):
        l = 2
        r = int(1e30 ** (1 / multiplicity))

        while l <= r:
            mid = (l + r) // 2
            am = (mid ** multiplicity - 1) // (mid - 1)

            if am == n:
                results.append("YES\n")
                break
            elif am < n:
                l = mid + 1
            else:
                r = mid - 1
        else:
            continue
        break
    else:
        results.append("NO\n")

output(''.join(results))
