a = list(input())
strings = set()

for i in range(len(a)):

    for j in range(len(a) - i):
        strings.add(''.join(a[j:j+i+1]))
    
print(len(strings))
