N = int(input())

def insert(sorted_lst, item, reverse):
    for i in range(len(sorted_lst)):
        if item < sorted_lst[i] and not reverse:
            sorted_lst.insert(i, item)
            return sorted_lst

        if item > sorted_lst[i] and reverse:
            sorted_lst.insert(i, item)
            return sorted_lst

    if not reverse:
        sorted_lst.append(item)
    
    if reverse:
        sorted_lst.append(item)
    return sorted_lst




lst1 = []
lst2 = []
for z in range(N):
    inp = list(map(int, input().split()))
    lst1.append(inp[0])
    lst2.append(inp[1])
    # counting sort
    indexes = [0 for _ in range(101)]
    indexes2 = [0 for _ in range(101)]
    final = [0 for _ in range(len(lst1))]
    final2 = [0 for _ in range(len(lst2))]

    for i in range(len(lst1)):
        indexes[lst1[i]] += 1
        indexes2[lst2[i]] += 1
    

    for i in range(1, 101):
        indexes[i] += indexes[i - 1]
        indexes2[i] += indexes2[i - 1]
    
    for i in range(len(lst1)):
        final[indexes[lst1[i]] - 1] = lst1[i]
        indexes[lst1[i]] -= 1
        final2[indexes2[lst2[i]] - 1] = lst2[i]
        indexes2[lst2[i]] -= 1




    lst1 = final
    lst2 = final2
    # print(final)
    # print(final2)
    
    totals = []
    for i in range(z + 1):
        totals.append(lst1[i] + lst2[-i - 1])

    print(max(totals))




