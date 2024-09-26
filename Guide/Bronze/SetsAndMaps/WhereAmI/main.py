import itertools as it

inp = open("whereami.in", "r")
out = open("whereami.out", "w")
N = int(inp.readline().strip())

colors = inp.readline().strip()

for seq_len in range(1, N + 1):
    cur_seq = []
    for i in range(N - seq_len + 1):
        cur_seq.append(colors[i : i + seq_len])


    if sorted(cur_seq) == sorted(list(set(cur_seq))):
        print(str(seq_len), file=out)
        break


