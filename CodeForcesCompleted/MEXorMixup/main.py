from operator import xor
 

def findXOR(n):
    mod = n % 4;
 
    if (mod == 0):
        return n;
 
    elif (mod == 1):
        return 1;
 
    elif (mod == 2):
        return n + 1;
 
    elif (mod == 3):
        return 0;

# num = 82736
# asdf = 0
# for i in range(1, num):
#     asdf ^= i
# print(asdf)


for _ in range(int(input())):
    a, b = map(int, input().split())
    val = findXOR(a - 1)
    if val == b:
        print(a)
        continue
    if val ^ b == a:
        print(a + 2)
        continue
    print(a + 1)
    

