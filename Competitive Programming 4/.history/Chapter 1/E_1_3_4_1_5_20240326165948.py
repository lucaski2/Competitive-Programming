num_people = int(input())

birthdays = []

for i in range(num_people):
    inp = input().split(' ')
    map(int, inp)
    birthdays.append(inp)
    
print(birthdays)