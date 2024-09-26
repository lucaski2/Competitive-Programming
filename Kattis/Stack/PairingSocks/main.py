N = int(input())
original_pile = list(map(int, input().split()))
aux_pile = []
count = 0
while len(original_pile) != 0:
    if len(aux_pile) != 0 and aux_pile[-1] == original_pile[-1]:
        aux_pile.pop()
        original_pile.pop()
        count += 1
    
    elif len(original_pile) != 0:
        aux_pile.append(original_pile.pop())
        count += 1
    
    
if len(aux_pile) != 0:
    print("impossible")
else:
    print(count)
