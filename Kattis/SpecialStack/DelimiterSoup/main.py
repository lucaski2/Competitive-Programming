
def opposite(x):
    if x == "(":
        return ")"
    elif x == "[":
        return "]"
    elif x == "{":
        return "}"
    else:
        print("error")
        exit(1)



N = int(input())

inp = input()


open_par = []
open_brack = []
open_curly = []
next_closed = []


for i in range(N):
    if inp[i] not in "[](){}":
        continue


    if len(next_closed) > 0 and inp[i] != opposite(next_closed[-1]) and inp[i] in "]})":
        print(inp[i], i)
        exit()


    if inp[i] == "(":
        open_par.append(i)
        next_closed.append(inp[i])
    

    elif inp[i] == ")":
        if len(open_par) == 0:
            print(")", i)
            exit()
        open_par.pop()
        next_closed.pop()
    
    elif inp[i] == "[":
        open_brack.append(i)
        next_closed.append(inp[i])
    
    elif inp[i] == "]":
        if len(open_brack) == 0:
            print("]", i)
            exit()
        open_brack.pop()
        next_closed.pop()

    elif inp[i] == "{":
        open_curly.append(i)
        next_closed.append(inp[i])
    
    elif inp[i] == "}":
        if len(open_curly) == 0:
            print("}", i)
            exit()
        next_closed.pop()
        open_curly.pop()
    
    


print("ok so far")
