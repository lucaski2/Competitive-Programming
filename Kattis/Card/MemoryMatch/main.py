num_cards = int(input())
N = int(input())

nums = set()
known = dict()
count = 0
for i in range(N):
    inp = input().split(' ')
    inp[0] = int(inp[0])
    inp[1] = int(inp[1])
    nums.add(inp[0])
    nums.add(inp[1])
    if inp[2] in known:
        if known[inp[2]] != -1 and known[inp[2]] != inp[0]:
            count += 1
            known[inp[2]] = -1
    else:
        known[inp[2]] = inp[0]
    
    if inp[3] in known:
        if known[inp[3]] != -1 and known[inp[3]] != inp[1]:
            count += 1

            known[inp[3]] = -1
    else: 
        known[inp[3]] = inp[1]


unknown_cards = num_cards - len(nums)
print(known)
print(unknown_cards)
print(list(known.values()).count(lambda x: x != -1))
if list(known.values()).count(lambda x: x != -1) == unknown_cards:
    count += unknown_cards

if unknown_cards == 2 and list(known.values()).count(lambda x: x != -1) == 0:
    count += 1

print(count)


