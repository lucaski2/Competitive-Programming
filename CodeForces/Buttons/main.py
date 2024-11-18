
for _ in range(int(input())):
    a, b, c = map(int, input().split())
    turn = c % 2
    if a > b:
        print("First")
    elif a == b:
        if turn == 0:
            print("Second")
        else:
            print("First")
    else:
        print("Second")