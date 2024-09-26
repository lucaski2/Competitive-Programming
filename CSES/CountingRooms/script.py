
f = open("main.in", 'w')
f.write("1000 1000\n")
for i in range(1000):
    f.write('.' * 1000 + '\n')
f.close()
