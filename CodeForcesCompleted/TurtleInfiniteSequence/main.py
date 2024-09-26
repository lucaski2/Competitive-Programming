from math import ceil, log2



# lst = range(0, 100)
# print(*list(map(bin, lst))[:15])
# for _ in range(20):
#     new_lst = []
#     for i in range(len(lst)):
#         if i == 0:
#             new_lst.append(lst[i] | lst[i + 1])
#         elif i == len(lst) - 1:
#             new_lst.append(lst[i] | lst[i - 1])
#         else:
#             new_lst.append(lst[i] | lst[i - 1] | lst[i + 1])
#     print(*list(map(bin, new_lst))[:15])
#     lst = new_lst
for _ in range(int(input())):
    n, m = map(int, input().split())
    # if _ != 5:
    #     continue

    # top_bits = int(1 + log2(m)) if m > 0 else 0
    # sequence = "1" * top_bits
    sequence = ""
    for i in range(0, 32):
        # See if the bit i is set in the range [n - m, n + m].

        # Find the largest factor of 2**i that is less than n - m.
        cur = max(0, (n - m)) // (2**i)
        cur *= 2 ** i

        found_in_range = False
        while cur <= n + m:
            if (cur // (2 ** i)) % 2 == 0:
                cur += 2 ** i
                continue

            # Found in range.
            found_in_range = True
            break

        if found_in_range:
            sequence += "1"
        else:
            sequence += "0"

    sequence = sequence[::-1]
    print(n | int(sequence, 2))
