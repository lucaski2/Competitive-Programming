r, g, b = map(int, input().split())
color = input()
if color == "Blue":
    print(min(r, g))
elif color == "Red":
    print(min(g, b))
else:
    print(min(r, b))



