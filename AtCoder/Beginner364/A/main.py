
n = int(input())
last = ""
for _ in range(n - 1):
    cur = input()
    if last == cur == "sweet":
        print("No")
        exit()
    last = cur
print("Yes")