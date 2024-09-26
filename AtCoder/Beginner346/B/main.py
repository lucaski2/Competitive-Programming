
s = "wbwbwwbwbwbw" * 100

w, b = map(int, input().split())

for i in range(len(s) - w - b):
    sub = s[i:i + w + b]
    if sub.count("w") == w and sub.count("b") == b:
        print("Yes")
        exit()
print("No")



