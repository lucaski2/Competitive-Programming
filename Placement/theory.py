from itertools import permutations

def sort_array(lst):
    for i in range(1, len(lst)):
        if lst[i - 1] > lst[i]:
            lst[i - 1], lst[i] = lst[i], lst[i - 1]
    
    return lst

perms = permutations([1, 2, 3, 4, 5, 6, 7])
s = 0
for perm in perms:
    if sort_array(list(perm)) == [1, 2, 3, 4, 5, 6, 7]:
        s += 1
print(s)

