"""
USER: lucaski2
TASK: palsquare
LANG: PYTHON3
"""

def convert_base(n, base):
    digits = '0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ'
    result = ''
    while n > 0:
        result = digits[n % base] + result
        n //= base
    return result

inp = open('palsquare.in', 'r')
out = open('palsquare.out', 'w')

base = int(inp.readline().strip())

for i in range(1, 301):
    square = convert_base(i ** 2, base)
    if square == square[::-1]:
        out.write(f"{convert_base(i, base)} {square}\n")

out.close()
