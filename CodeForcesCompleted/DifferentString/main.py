
for _ in range(int(input())):
    st = input()
    if len(set(list(st))) == 1:
        print("NO")
    else:
        
        for i in range(len(st)):
            if st[i] != st[-1]:
                print("YES")
                st = list(st)
                cur = st[i]
                st.pop(i)
                st = "".join(st) + cur
                print(st)
                break