
alphabet = "abcdefghijklmnopqrstuvwxyz"
dictionary = []
for i in range(26):
    for j in range(26):
        if i != j:
            dictionary.append(alphabet[i] + alphabet[j])
dictionary.sort(key=lambda x: x[0])

for _ in range(int(input())):
    print(dictionary.index(input()) + 1)

