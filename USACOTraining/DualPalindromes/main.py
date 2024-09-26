"""
USER: lucaski2
TASK: dualpal
LANG: PYTHON3
"""

def convert_base(n, base):
    digits = '0123456789'
    result = ''
    while n > 0:
        result = digits[n % base] + result
        n //= base
    return result

inp = open('dualpal.in', 'r')
out = open('dualpal.out', 'w')

n, s = map(int, inp.readline().strip().split())

count = 0
i = s + 1

while count < n:
    palindromes = 0
    for base in range(2, 11):
        if convert_base(i, base) == convert_base(i, base)[::-1]:
            palindromes += 1
        if palindromes == 2:
            out.write(f"{i}\n")
            count += 1
            break
    i += 1

inp.close()

