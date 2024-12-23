import sys

def transform(cur, a1, a2):
    # reverse the order of the elements between a1 and a2
    cur[a1 - 1:a2] = cur[a1 - 1:a2][::-1]

# Open input and output files
with open('swap.in', 'r') as fin, open('swap.out', 'w') as fout:
    sys.stdin = fin
    sys.stdout = fout

    # Read input
    n, m, k = map(int, input().split())
    start = list(range(1, n + 1))
    a = list(range(1, n + 1))

    changes = [list(map(int, input().split())) for _ in range(m)]
    things = []

    for change in changes:
        transform(start, *change)
    k -= 1
    things.append(start)

    while k > 0 and start != a:
        for change in changes:
            transform(start, *change)
        k -= 1
        things.append(start)

    if k == 0:
        print(*start, sep='\n')
    else:
        print(*things[k % len(things)], sep='\n')

    # Restore defaults
    sys.stdin = sys.__stdin__
    sys.stdout = sys.__stdout__