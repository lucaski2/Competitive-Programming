inp = int(input())

print("+" + inp * "-" + "+")

print(("|" + " " * inp + "|" + "\n") * (inp - 1), end='')
if inp != 0:
    print(("|" + " " * inp + "|" + "\n"), end='')
print("+" + "-" * inp + "+")