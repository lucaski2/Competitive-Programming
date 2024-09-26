

def solve(rings):
    # pair of tuples
    pairs = []
    for i, val1 in enumerate(rings):
        for j, val2 in enumerate(rings):
            if i != j:
                # check for overlap
                r1 = val1[2]
                r2 = val2[2]
                if pow(pow(val1[0] - val2[0], 2) + pow(val1[1] - val2[1], 2), 0.5) >= pow(pow(r1 + r2, 2), 0.5):
                    pairs.append((i, j))
    

    lst = set()
    print(pairs)
    for i in range(len(pairs)):
        lst.add(pairs[i][0])
        lst.add(pairs[i][1])
    print(lst)
    if (len(lst) == 0):
        return 1
    

    return len(lst)
    


cur_N = input()
while cur_N != "-1":
    s = solve([list(map(float, input().split())) for _ in range(int(cur_N))])
    print("The largest component contains " + str(s) + (" rings." if s > 1 else " ring."))
    cur_N = input()



