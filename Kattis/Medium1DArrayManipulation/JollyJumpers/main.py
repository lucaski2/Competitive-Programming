import math

value_arr = []

try:
    while True:
        value_arr.append(list(map(int,input().split(" "))))
except EOFError:
    pass
current_val = 0

for vals in value_arr:
    vals.pop(0)
    needed_values = set(range(1, len(vals)))
    for i in range(1, len(vals)):
        current_val = abs(vals[i - 1] - vals[i])

        
        if current_val not in needed_values:
            print("Not jolly")
            break


        else:
            needed_values.remove(current_val)
    if not needed_values:
        print("Jolly")
    

