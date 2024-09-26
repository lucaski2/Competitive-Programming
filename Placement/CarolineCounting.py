
# inp = int(input())
# n = inp - 1
# lcm = 21
# if inp % 3 == 0 and inp % 7 != 0:
#     print(-1)
# else:
#     lcm_amount = n // lcm
#     counted = n - n // 3 - lcm_amount
#     counted += n // 7 - lcm_amount
#     if inp % 7 == 0:
#         print(counted + 1, counted + 2)
#     else:
#         print(counted + 1)

n = int(input())
count = 0
for i in range(1, n):
    if i % 21 == 0:
        count += 1
    elif i  % 7 == 0:
        count += 2
    elif i % 3 != 0:
        count += 1
if n % 3 == 0 and n % 7 != 0:
    print(-1)
elif n % 7 == 0:
    print(count + 1, count + 2)
else:
    print(count + 1)


