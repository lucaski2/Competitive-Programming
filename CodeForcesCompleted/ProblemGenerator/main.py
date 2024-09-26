
for _ in range(int(input())):
    n, m = map(int, input().split())

    problems = input()

    needed = m * list("ABCDEFG")
    
    for i in range(len(problems)):
        if problems[i] in needed:
            needed.remove(problems[i])
    
    print(len(needed))


