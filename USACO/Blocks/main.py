
import itertools


n = int(input())

blocks = [list(input()) for _ in range(4)]

for _ in range(n):
    block = list(input())
    perms = itertools.permutations(range(4), len(block))

    for perm in perms:
        works = True
        for i in range(len(block)):
            if block[i] not in blocks[perm[i]]:
                works = False
                break
        if works:
            print("YES")
            break
    else:
        print("NO")

