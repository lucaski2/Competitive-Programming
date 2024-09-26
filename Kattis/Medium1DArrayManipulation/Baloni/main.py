num_balloons = int(input())

heights = list(map(int, input().split(' ')))

arrows = [0 for _ in range(1000001)]

count = 0

for i in range(num_balloons):
    if arrows[heights[i]] == 0:
        if heights[i] != 1:
            arrows[heights[i] - 1] += 1
        count += 1
    
    if arrows[heights[i]] >= 1:
        arrows[heights[i]] -= 1
        if heights[i] != 1:
            arrows[heights[i] - 1] += 1
    

print(count)
    








