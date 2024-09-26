
for _ in range(int(input())):
    n = int(input())
    word = list(input())
    consonants = "bcd"
    vowels = "ae"
    ans = 0
    cur = ""
    for i in range(n):
        if len(cur) == 3:
            print('.', end="")
            cur = ""
        if len(cur) == 2 and (i + 1 < n and word[i + 1] not in consonants):
            print(".", end="")
            cur = ""
        
        print(word[i], end="")
        cur += word[i]
    print()


