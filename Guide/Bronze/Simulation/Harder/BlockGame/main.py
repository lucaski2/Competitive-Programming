inp = open("blocks.in", "r")
out = open("blocks.out", "w")
N = int(inp.readline().strip())
word_pairs = [tuple(inp.readline().strip().split()) for _ in range(N)]
letters = [0] * 26
for pair in word_pairs:
    cur_letters1 = [0] * 26
    for letter in pair[0]:
        cur_letters1[ord(letter) - ord('a')] += 1
    cur_letters2 = [0] * 26
    for letter in pair[1]:
        cur_letters2[ord(letter) - ord('a')] += 1
    for i in range(26):
        letters[i] += max(cur_letters1[i], cur_letters2[i])
    
    

for letter in letters:
    out.write(str(letter) + "\n")




