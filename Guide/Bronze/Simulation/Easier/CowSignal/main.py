inp = open("cowsignal.in", "r")
out = open("cowsignal.out", "w")
height, width, amplification = map(int, inp.readline().strip().split())
signal = [inp.readline().strip() for _ in range(height)]




for i in range(height):
    for k in range(amplification):

        for j in range(width):
                print(signal[i][j] * amplification, end="", file=out)
        print(file=out)

