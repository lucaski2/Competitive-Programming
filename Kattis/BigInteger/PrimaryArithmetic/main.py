inp = input().split()

while inp != ["0", "0"]:

    cur_carry = 0
    carries = 0

    if len(inp[0]) > len(inp[1]):
        inp[1] = "0" * (len(inp[0]) - len(inp[1])) + inp[1]
    elif len(inp[0]) < len(inp[1]):
        inp[0] = "0" * (len(inp[1]) - len(inp[0])) + inp[0]
    
    for i in range(len(inp[0]) - 1, -1, -1):
        cur_sum = int(inp[0][i]) + int(inp[1][i]) + cur_carry
        if cur_sum > 9:
            cur_carry = 1
        else:
            cur_carry = 0
        
        if cur_carry == 1:
            carries += 1
    
    if carries != 0:
        print(carries, "carry operation." if carries == 1 else "carry operations.")
    
    else:
        print("No carry operation.")

        

        


    inp = input().split()

