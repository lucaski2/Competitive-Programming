from math import ceil
from itertools import permutations

def overlap(start1, end1, start2, end2):
    if start1 <= start2 <= end1 or start1 <= end2 <= end1 or start2 <= start1 <= end2 or start2 <= end1 <= end2:
        return True
    return False


def solve(l1, l2, l3):
    tot = ceil(sum(l1) / 3)
    orders = list(permutations([l1, l2, l3]))
    for order in orders:
        order = list(order)
        lists = [order[0], order[1], order[2]]
        cur = [[0]]
        cur_s = 0
        ind = 0
        for i in range(len(l1)):
            cur_s += lists[ind][i]
            if cur_s >= tot:
                if ind == 2 and i != len(l1) - 1:
                    continue
                cur_s = 0
                ind += 1
                cur[-1].append(i)
                cur.append([i + 1])
                if ind == 3:
                    ret = []
                    ret.append(cur[order.index(l1)])
                    cur.remove(cur[order.index(l1)])
                    order.pop(order.index(l1))
                    ret.append(cur[order.index(l2)])
                    cur.remove(cur[order.index(l2)])
                    order.pop(order.index(l2))
                    ret.append(cur[order.index(l3)])
                    cur.remove(cur[order.index(l3)])
                    order.pop(order.index(l3))


                    return ret
    return [-1]

    
        





for _ in range(int(input())):
    n = int(input())
    a = list(map(int, input().split()))
    b = list(map(int, input().split()))
    c = list(map(int, input().split()))
    s = solve(a, b, c)
    if s == [-1]:
        print(-1)
    else:

        for i in s:
            for j in i:
                print(j + 1, end=' ')
        print()

    
    # for answer in answers:
    #     if answer != -1:
    #         print(*answer)
    #         break
    # else:
    #     print(-1)
