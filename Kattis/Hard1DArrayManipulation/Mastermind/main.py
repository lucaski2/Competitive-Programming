length, correct, attempt = input().split()
length = int(length)

r = 0
for i in range(length):
    if attempt[i] == correct[i]:
        r += 1

print(r, end=" ")

s = 0
for letter in set(list(attempt)):
    s += min(attempt.count(letter), correct.count(letter))

print(s - r)