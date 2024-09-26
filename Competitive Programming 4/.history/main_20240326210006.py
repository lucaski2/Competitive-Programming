f = open("different.in", 'r')

lines = f.readlines()
for line in lines:
    print(abs(int(line.split(' ')[0]) - int(line.split(' ')[1])))