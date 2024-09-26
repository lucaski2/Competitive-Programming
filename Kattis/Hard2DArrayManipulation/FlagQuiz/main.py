input()
N = int(input())





answers = [input().split(', ') for _ in range(N)]

def remove_duplicates(lst):
    
    # create an empty list to store unique elements
    unique_lst = []

    # traverse for all elements
    for x in lst:
        # check if exists in unique_lst or not
        if x not in unique_lst:
            unique_lst.append(x)

    return unique_lst

def get_score(answers):
    scores = [0 for _ in range(len(answers))]

    for i in range(len(answers)):
        current_comparison = [0 for _ in range(len(scores))]
        for j in range(len(answers)):
            if i == j:
                continue

            for k in range(len(answers[i])):
                if answers[i][k] != answers[j][k]:
                    current_comparison[j] += 1
        
        scores[i] = max(current_comparison)

    return scores

# answers = remove_duplicates(answers)



final = get_score(answers)
low = min(final)

already_guessed = set()


for ind, i in enumerate(final):
    if i == low:
        var = ", ".join(answers[ind])
        if var not in already_guessed:
            already_guessed.add(var)
            print(var)



