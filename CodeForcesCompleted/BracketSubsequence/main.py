
n, k = map(int, input().split())
s = input()

cur_unclosed = 0
st = ""
pairs = 0
for i in range(n):
    if len(st) + cur_unclosed < k:
        cur = s[i]
        if cur == "(":
            cur_unclosed += 1
            st += cur
        else:
            cur_unclosed -= 1
            st += cur
            pairs += 1


st += ")" * cur_unclosed
print(st)