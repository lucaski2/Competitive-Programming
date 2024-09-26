inp = int(input())

for i in range(2, inp):
    if inp % i == 0:
        print("composite")
        break

print("prime")