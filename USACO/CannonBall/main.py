n, s = map(int, input().split())
locations = []

targets_broken = set()
for i in range(n):
    locations.append(tuple(map(int, input().split())))


cur_location = s - 1

power = 1
direction = 1

counter = 0
while counter < 500000 and cur_location < n and cur_location >= 0:
    if locations[cur_location][0] == 1:
        if locations[cur_location][1] <= power:
            targets_broken.add(cur_location)
    else:
        direction *= -1
        power += locations[cur_location][1]
    counter += 1
    cur_location += direction * power

print(len(targets_broken))