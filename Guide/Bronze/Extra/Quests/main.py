N = int(input())

for _ in range(N):
    if _ != 1:
        continue
    n, k = map(int, input().split())


    first_completions = list(map(int, input().split()))
    
    later_completions = list(map(int, input().split()))
    
    cur_quest = 0

    amount_completed = 0

    xp_points = first_completions[0]


    for __ in range(k - 1):

        if cur_quest == n - 1 and amount_completed == len(later_completions) - 1:
            break

        elif cur_quest == n - 1:
            xp_points += later_completions[amount_completed]
            amount_completed += 1
        
        elif (cur_quest < n - 1 and later_completions[amount_completed] < first_completions[cur_quest + 1]) or amount_completed == len(later_completions) - 1:
            xp_points += first_completions[cur_quest + 1]
            cur_quest += 1
            amount_completed = 0

        elif cur_quest < n - 1 and later_completions[amount_completed] >= first_completions[cur_quest + 1]:
            xp_points += later_completions[amount_completed]
            amount_completed += 1
        print(xp_points)    



    # break
    