
n = int(input())

things = [list(map(int, input().split())) + [i + 1] for i in range(n)]

things.sort(key=lambda x: x[0], reverse=True)

min_cost = things[0][1]
max_power = things[0][0]

end_arr = []


for thing in things:
    if thing[1] <= min_cost or thing[0] >= max_power:
        end_arr.append(thing[-1])
    if thing[1] < min_cost:
        min_cost = thing[1]

print(len(end_arr))
print(*list(sorted(end_arr)))


