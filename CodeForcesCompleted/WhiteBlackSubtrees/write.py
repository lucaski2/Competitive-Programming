
f = open("main.in", "w")
f.write("1\n 100000\n")
for i in range(1, 100001):
    f.write(str(i) + " ")
f.write("\n")
for i in range(100000):
    f.write("B") if i % 2 == 0 else f.write("W")