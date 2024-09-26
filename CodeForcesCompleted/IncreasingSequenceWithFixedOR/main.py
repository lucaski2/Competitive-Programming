
def conv(n):
    return int(n, 2)


for _ in range(int(input())):
    n = list(str(bin(int(input())))[2:])
    # if _ != 1:
    #     continue
    z_f = len(n)
    lst = [n]
    cur = n[::-1]
    cur = cur[::-1]
    spots = []
    for i in range(z_f):
        if cur[i] == '1':
            spots.append(i)

    for i in range(z_f - 1, -1, -1):
        if cur[i] == '1':
            cur[i] = '0'
            available = i
            break

    for i in range(n.count('1')):
        if conv(''.join(cur)) == 0:
            break

        lst.append(cur)

        if spots.index(available) == 0:
            break
        cur = cur.copy()
        cur[available] = '1'
        cur[spots[spots.index(available) - 1]] = '0'
        available = spots[spots.index(available) - 1]
        

    
    lst.reverse()
    # print(lst)
    print(len(lst))
    for i in range(len(lst)):
        print(conv(''.join(lst[i])), end=" ")

    print()
        


        
        


