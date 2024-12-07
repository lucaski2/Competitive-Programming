

def mul(a, b):
    return a * b

ans = 0
n = 6
ok = True
for _ in range(n):
  inp = input()
  for i in range(len(inp) - 3):
      try:
        if inp[i] == "m" and inp[i+1] == "u" and inp[i+2] == "l" and inp[i+3] == "(":
            num = ""
            ind = i + 4
            while inp[ind].isdigit():
              num += inp[ind]
              ind += 1
            
            if inp[ind] == ",":
                num1 = int(num)
                num = ""
                ind += 1
                while inp[ind].isdigit():
                    num += inp[ind]
                    ind += 1
                num2 = int(num)
                if inp[ind] == ")" and ok:
                    ans += mul(num1, num2)
        if inp[i:i+4] == "do()":
          ok = True
        if inp[i:i+7] == "don't()":
          ok = False
          
      except:
          pass
print(ans)

                
            
