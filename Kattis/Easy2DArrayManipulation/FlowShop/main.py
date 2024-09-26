
N, M = list(map(int, input().split()))
mobile_times = [[0 for _ in range(M + 1)]]

for i in range(N):
    mobile_times.append([0] + list(map(int, input().split())))



for row in range(1, len(mobile_times)):

    for col in range(1, len(mobile_times[row])):
        mobile_times[row][col] += max(mobile_times[row - 1][col], mobile_times[row][col - 1])

for row in range(1, len(mobile_times)):
    print(mobile_times[row][-1], end=" ")

print()