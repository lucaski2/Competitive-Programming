import itertools

inp = sorted(list(map(int, input().split())))


combos = itertools.combinations(inp, 3)

for combo in combos:
    combo_lst = [combo[0], combo[1], combo[2], combo[0] + combo[1] + combo[2], combo[0] + combo[1], combo[1] + combo[2], combo[0] + combo[2]]
    if sorted(combo_lst) == inp:
        print(combo[0], combo[1], combo[2])





