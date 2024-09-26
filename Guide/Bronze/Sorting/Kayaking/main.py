import itertools as it
N = int(input())
weights = sorted(list(map(int, input().split())))

kayaks = list(it.permutations(range(len(weights)), 2))

nums = []

for removals in kayaks:
    cur_weights = weights.copy()
    weights_removed = weights[removals[0]], weights[removals[1]]
    cur_weights.remove(weights_removed[0])
    cur_weights.remove(weights_removed[1])
    s = 0
    for i in range(0, 2 * N - 2, 2):
        s += cur_weights[i + 1] - cur_weights[i]
    nums.append(s)

print(min(nums))



