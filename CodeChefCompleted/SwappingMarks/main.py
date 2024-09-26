
for _ in range(int(input())):
    a, b = input().split()
    a_reversed = a[::-1]
    b_reversed = b[::-1]
    a, b, a_reversed, b_reversed = int(a), int(b), int(a_reversed), int(b_reversed)
    if a > b or a_reversed > b_reversed or a_reversed > b or a > b_reversed:
        
        print('YES')
    else:
        print('NO')