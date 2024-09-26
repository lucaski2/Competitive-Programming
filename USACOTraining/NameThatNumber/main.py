"""
USER: lucaski2
TASK: namenum
LANG: PYTHON3
"""

inp = open('namenum.in', 'r')
out = open('namenum.out', 'w')
dict_file = open('dict.txt', 'r')
n = inp.readline().strip()

def get_number(letter):
    if letter in 'ABC':
        return '2'
    if letter in 'DEF':
        return '3'
    if letter in 'GHI':
        return '4'
    if letter in 'JKL':
        return '5'
    if letter in 'MNO':
        return '6'
    if letter in 'PRS':
        return '7'
    if letter in 'TUV':
        return '8'
    if letter in 'WXY':
        return '9'
    return '0'


def get_number_name(name):
    return ''.join([get_number(letter) for letter in name])

names = [name.strip() for name in dict_file]

valid_names = [name for name in names if get_number_name(name) == n]

out.write('\n'.join(valid_names) + '\n' if valid_names else 'NONE\n')

