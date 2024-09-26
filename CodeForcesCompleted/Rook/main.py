letters = "abcdefgh"
numbers = "12345678"

for _ in range(int(input())):
    pos = list(input())
    for l in letters:
        print(l + pos[1]) if l != pos[0] else None
    for n in numbers:
        print(pos[0] + n) if n != pos[1] else None
        

