inp = int(input())

for i in range(inp):
    input()
    num_teams = int(input())
    
    teams = []
    for i in range(num_teams):
        teams.append(input().split())
    
    for i in range(len(teams)):
        teams[i][1] = int(teams[i][1])

    teams = sorted(teams, key=lambda x: x[1])

    # compute badness
    total = 0
    for i in range(len(teams)):
        total += abs(teams[i][1] - (i + 1))
    print(total)
