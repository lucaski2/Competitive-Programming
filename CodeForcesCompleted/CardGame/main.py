def count_suneet_wins(a1, a2, b1, b2):
    suneet_cards = [a1, a2]
    slavic_cards = [b1, b2]
    total_wins = 0

    for first_round in [(0, 0), (0, 1), (1, 0), (1, 1)]:
        for second_round in [(0, 0), (0, 1), (1, 0), (1, 1)]:
            suneet_score = 0
            slavic_score = 0

            # First round
            if suneet_cards[first_round[0]] > slavic_cards[first_round[1]]:
                suneet_score += 1
            elif suneet_cards[first_round[0]] < slavic_cards[first_round[1]]:
                slavic_score += 1

            # Second round
            if suneet_cards[1 - first_round[0]] > slavic_cards[1 - first_round[1]]:
                suneet_score += 1
            elif suneet_cards[1 - first_round[0]] < slavic_cards[1 - first_round[1]]:
                slavic_score += 1

            # Check if Suneet wins
            if suneet_score > slavic_score:
                total_wins += 1

    return total_wins

def process_test_cases(t, test_cases):
    results = []
    for case in test_cases:
        a1, a2, b1, b2 = case
        results.append(count_suneet_wins(a1, a2, b1, b2))
    return results

# Input processing
t = int(input())
test_cases = []
for _ in range(t):
    test_cases.append(list(map(int, input().split())))

# Calculate and output results
results = process_test_cases(t, test_cases)
for result in results:
    print(result // 4)