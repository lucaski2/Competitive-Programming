cases = int(input())

for _ in range(cases):
    n = int(input())
    names = {}
    for _ in range(n):
        name, number = input().split(": ")
        var = number.split()[0].split('-')
        for i in range(len(var)):
            if var[i] == "upper":
                var[i] = "c"
            elif var[i] == "middle":
                var[i] = "b"
            else:
                var[i] = "a"
        
        var.insert(0, "b" * (10 - len(var)))
            
        names[name] = "".join(var)[::-1]


    
    final = list(names.items())
    
    for i in range(len(final)):
        for j in range(len(final) - 1 - i):
            if final[j][1] < final[j + 1][1]:
                final[j], final[j + 1] = final[j + 1], final[j]
            if final[j][1] == final[j + 1][1]:
                if final[j][0] > final[j + 1][0]:
                    final[j], final[j + 1] = final[j + 1], final[j]
                
    


    for t in final:
        print(t[0])
    print("=" * 30)
    