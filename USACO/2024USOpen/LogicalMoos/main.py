
n, q = map(int, input().split())

exp = input().split()

nums = []
for i in range(n):
    if exp[i] == "true":
        nums.append(1)
    elif exp[i] == "false":
        nums.append(0)
    elif exp[i] == "or":
        nums.append(2)
    elif exp[i] == "and":
        nums.append(3)

pref_sums = []
cur = [0]
indexes = [0]
for i in range(n):
    if nums[i] == 0:
        cur.append(cur[-1] + 1)
        indexes.append((len(cur) - 1, len(pref_sums)))
        continue
    elif nums[i] == 2:
        pref_sums.append(cur)
        cur = [0]

    cur.append(cur[-1])
    indexes.append((len(cur) - 1, len(pref_sums)))

pref_sums.append(cur)

eval_pref = []
for i in range(len(pref_sums)):
    if i == 0:
        eval_pref.append(1 if pref_sums[i][-1] == 0 else 0)
    if pref_sums[i][-1] == 0:
        eval_pref.append(eval_pref[-1] + 1)
    else:
        eval_pref.append(eval_pref[-1])

# print(eval_pref)
# print(pref_sums)

for _ in range(q):
    a, b, c = input().split()
    a = int(a)
    b = int(b)
    # if _ != 2:
    #     continue

    if c == "true":
        num_trues = eval_pref[indexes[a][1]]
        if indexes[b][1] != len(eval_pref) - 1:
            num_trues += eval_pref[-1] - eval_pref[indexes[b][1] + 1]
        
        if num_trues > 0:
            print("Y", end='')
            continue

        num_false = pref_sums[indexes[a][1]][indexes[a][0] - 1]
        if indexes[b][0] != len(pref_sums[indexes[b][1]]) - 1:
            num_false += pref_sums[indexes[b][1]][-1] - pref_sums[indexes[b][1]][indexes[b][0] + 1]
        if num_false == 0:
            print("Y", end='')
            continue
        print("N", end='')
    else:
        num_trues = eval_pref[indexes[a][1]]
        if indexes[b][1] != len(eval_pref) - 1:
            num_trues += eval_pref[-1] - eval_pref[indexes[b][1] + 1]
        # print(indexes[a][1])
        if num_trues == 0:
            print("Y", end='')
        else:
            print("N", end='')
print()
