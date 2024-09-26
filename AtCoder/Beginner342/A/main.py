
st = list(input())
for s in range(len(st)):
    if st.count(st[s]) == 1:
        print(s + 1)
        break