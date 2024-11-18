
n = int(input())

if_zero = [0] * 10
if_one = [1] * 10

for _ in range(n):
    a, b = input().split()
    b = bin(int(b))[2:].zfill(10)
    if a == '|':
        for i in range(10):
            if b[i] == '1':
                if_zero[i] = 1
                if_one[i] = 1
    elif a == '&':
        for i in range(10):
            if b[i] == '0':
                if_zero[i] = 0
                if_one[i] = 0
    else:
        for i in range(10):
            if b[i] == '1':
                if_zero[i] = 1 - if_zero[i]
                if_one[i] = 1 - if_one[i]

# print(if_zero)
# print(if_one)

ans = [0] * 10

for i in range(10):
    if if_zero[i] == if_one[i] == 1:
        ans[i] = 0
    elif if_zero[i] == if_one[i] == 0:
        ans[i] = 1
    elif if_zero[i] == 1 and if_one[i] == 0:
        ans[i] = 2
    else:
        ans[i] = 3
    
ors = [0] * 10
ands = [1] * 10
xors = [0] * 10
for i in range(10):
    if ans[i] == 0:
        ors[i] = 1
    elif ans[i] == 1:
        ands[i] = 0
    elif ans[i] == 2:
        xors[i] = 1
print(3)
print("|", int(''.join(map(str, ors)), 2))
print("&", int(''.join(map(str, ands)), 2))
print("^", int(''.join(map(str, xors)), 2))

    


