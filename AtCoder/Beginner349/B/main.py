word = list(input())
letters = {}

for i in range(len(word)):
    if word[i] not in letters:
        letters[word[i]] = 1
    else:
        letters[word[i]] += 1

letters_count = {}

for i in letters:
    if letters[i] not in letters_count:
        letters_count[letters[i]] = 1
    else:
        letters_count[letters[i]] += 1

for ind, it in enumerate(list(sorted(letters_count.items(), key=lambda x: x[1]))):
    if it[1] != 2:
        print("No")
        break
else:
    print("Yes")

