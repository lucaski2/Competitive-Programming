from __future__ import print_function


def print_sequence(n):
    # print("cur", n)
    if n == 1:
        print(1, end=' ')
    elif n < 1:
        pass
    else:
        if n%2 == 0:
            x = int(n/2)
        else:
            x = int(n / 2 + 0.5)
        print(x, end=' ')
        print_sequence(n-2)
        print(x, end=' ')

print_sequence(5)
print()