
def count_pairs(s):
    n = len(s)
    counts = 0
    for i in range(n):
        for j in range(i + 1, n):
            if s[i] == s[j]:
                counts += 1
                continue
            for k in range(i, j):
                if s[k] != s[k + 1] and (s[k] != s[i] or s[k + 1] != s[j]):
                    counts += 1
                    break
    return counts


for _ in range(int(input())):
    n = int(input())
    s = list(input())
    counts = {}
    for i in range(n):
        if s[i] not in counts:
            counts[s[i]] = 0
        counts[s[i]] += 1
    counts = list(map(list, counts.items()))
    counts.sort(key=lambda x: x[1], reverse=True)
    point = 2
    pointers = [0, 1]
    while pointers[0] < len(counts) or pointers[1] < len(counts):
        if pointers[1] >= len(counts):
            print(counts[pointers[0]][0] * counts[pointers[0]][1])
            break
        if pointers[0] >= len(counts):
            print(counts[pointers[1]][0] * counts[pointers[1]][1])
            break
        print(counts[pointers[0]][0] + counts[pointers[1]][0], end='')
        counts[pointers[0]][1] -= 1
        counts[pointers[1]][1] -= 1
        if counts[pointers[0]][1] == 0:
            pointers[0] = point
            point += 1
        if counts[pointers[1]][1] == 0:
            pointers[1] = point
            point += 1
    else:
        print()