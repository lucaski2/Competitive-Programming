
def sum_of_digits(n):
    s = 0
    while n:
        s += n % 10
        n //= 10
    return s

every_100 = 0
for i in range(1, 1000):
    every_100 += sum_of_digits(i)

for _ in range(int(input())):
    n = int(input())
    ans = 0
    cur_num = 0
    while n >= 1000:
        ans += every_100
        ans += sum_of_digits(cur_num) * 999
        ans += sum_of_digits(cur_num + 1)
        n -= 1000
        cur_num += 1

    # print("cur", cur_num)
    for i in range(cur_num * 1000 + 1, cur_num * 1000 + n + 1):
        ans += sum_of_digits(i)
    
    print(ans)


