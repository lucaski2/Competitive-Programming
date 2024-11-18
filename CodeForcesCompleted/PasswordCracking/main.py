
for _ in range(int(input())):
    n = int(input())
    b_str = ""
    end1 = False
    end2 = False
    while len(b_str) < n:
        if end1 == True:
            print("? " + b_str + "0", flush=True)
            a = int(input())
            if a == 1:
                b_str += "0"
            else:
                b_str += "1"
        else:
            print("? 0" + b_str, flush=True)
            a = int(input())
            if a == 1:
                b_str = "0" + b_str
            else:
                print("? 1" + b_str, flush=True)
                a = int(input())
                if a == 1:
                    b_str = "1" + b_str
                else:
                    end1 = True
                    continue
    print("! " + b_str, flush=True)

