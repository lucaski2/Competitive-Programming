line = list(input())

st = []

for i in range(len(line)):
    if line[i] == '<':
        st.pop()
    else:
        st.append(line[i])

print(''.join(st))