num_people = int(input())

birthdays = []

for i in range(num_people):
    inp = input().split(' ')
    inp = list(map(int, inp))
    birthdays.append(inp)
    
birthdays.sort(key=lambda x: x[1])
print(birthdays)
birthdays.sort(key=lambda x: x[0])
print(birthdays.sort(key=lambda x: x[2], reverse=True))