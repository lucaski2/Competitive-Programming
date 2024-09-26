inp = open("sleepy.in", "r")
out = open("sleepy.out", "w")

n = int(inp.readline().strip())
lst = list(map(int, inp.readline().strip().split()))

cnt = 0
while lst != sorted(lst):
    lst.pop(0)
    cnt += 1

print(cnt, file=out)

