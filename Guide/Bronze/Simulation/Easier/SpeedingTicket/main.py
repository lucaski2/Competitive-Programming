inp = open("speeding.in", "r")
out = open("speeding.out", "w")
N, M = map(int, inp.readline().strip().split())
road_segments = [list(map(int, inp.readline().strip().split())) for _ in range(N)]
journey_segments = [list(map(int, inp.readline().strip().split())) for _ in range(M)]
highest_speed_over = 0
current_journey = 0
current_road = 0
last_end_journey = 0
last_end_road = 0
for i in range(100):

    if journey_segments[current_journey][0] + last_end_journey <= i:
        last_end_journey += journey_segments[current_journey][0]
        current_journey += 1
    if road_segments[current_road][0] + last_end_road <= i:
        last_end_road += road_segments[current_road][0]
        current_road += 1



    if journey_segments [current_journey][1] - road_segments[current_road][1] > highest_speed_over:
        highest_speed_over = journey_segments[current_journey][1] - road_segments[current_road][1]

print(highest_speed_over, file=out)


