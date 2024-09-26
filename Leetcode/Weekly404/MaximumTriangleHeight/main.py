def maxHeightOfTriangle(red: int, blue: int) -> int:
    cur_blue = True
    amount = 0
    
    while True:
        if cur_blue:
            if blue < amount + 1:
                return amount
            blue -= amount
        else:
            if red < amount + 1:
                return amount
            red -= amount

        amount += 1

        cur_blue = not cur_blue
        

print(maxHeightOfTriangle(10, 1))
