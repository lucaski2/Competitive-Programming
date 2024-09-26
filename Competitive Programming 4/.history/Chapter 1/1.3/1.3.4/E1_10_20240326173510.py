inp = input()
alphabet = 'abcdefghijklmnopqrstuvwxyz'
numbers = '0123456789'

for i in range(len(inp) - 2):
    if inp[i] in alphabet and inp[i].lower() == inp[i] && inp[i + 1] in numbers and inp[i + 2] in numbers:
        inp[i] = "*"
        