
n, t = map(int, input().split())

scores = [0 for _ in range(n)]
scores_dict = {0: n}



for _ in range(t):
    a, b = map(int, input().split())
    a -= 1
    cur = scores[a]
    scores[a] += b 
    scores_dict[cur] -= 1
    if scores_dict[cur] == 0:
        del scores_dict[cur]
    
    if b + cur in scores_dict:
        scores_dict[b + cur] += 1
    
    else:
        scores_dict[b + cur] = 1
    print(len(scores_dict))




