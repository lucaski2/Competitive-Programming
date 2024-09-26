num_people = int(input())

birthdays = []

for i in range(num_people):
    inp = input().split(' ')
    inp = list(map(int, inp))
    birthdays.append(inp)
    
print(birthdays.sort(key=lambda x: x[1]);