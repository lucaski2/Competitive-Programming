inp = open("pails.in", "r")
out = open("pails.out", "w")
x, y, m = map(int, inp.readline().strip().split())
final_list = []
def search(x, y, m, amount_full, last_added):
    if amount_full == m:
        print(m, file=out)
        exit()

    if amount_full + x > m:
        final_list.append(amount_full)   
    else:
        search(x, y, m, amount_full + x, x)
    if amount_full + y > m:
        final_list.append(amount_full)
    else:
        search(x, y, m, amount_full + y, y)


search(x, y, m, 0, 0)
print(max(final_list), file=out)

