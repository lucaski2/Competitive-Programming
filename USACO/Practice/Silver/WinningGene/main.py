N = int(input())

gene = input()

num_pairs = [0 for _ in range(N)]

# make all possible tuples
possible_tuples = [(i, j) for i in range(1, N + 1) for j in range(1, N + 1) if i >= j]

for t in possible_tuples:
    kmers = [gene[i:i + t[0]] for i in range(N - t[0] + 1)]
    if len(kmers) == 0:
        continue
    
    positions = set()
    # if t == (4, 2):
    #     print(kmers)
    

    for i in range(N - t[0] + 1):
        # find lowest lexicographical substring
        current_str = t[1]
        for j in range(1, len(gene[i:i + t[0]])):
            if gene[i:i + t[0]][j - 1: j + 1] < gene[i:i + t[0]][current_str - 1 : current_str + 1]:
                current_str = j
        
        positions.add(current_str)

    num_pairs[len(positions) - 1] += 1

for i in range(len(num_pairs)):
    print(num_pairs[i])
    

#         print(current_str)
    
#     print(kmers)

# print(possible_tuples)






