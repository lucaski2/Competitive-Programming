import sys
input = sys.stdin.read

def max_possible_rating(t, test_cases):
    results = []
    
    for n, a in test_cases:
        x = 0
        gains = []
        for i in range(n):
            if a[i] > x:
                gains.append(1)
                x += 1
            elif a[i] < x:
                gains.append(-1)
                x -= 1
            else:
                gains.append(0)

        base_rating = x

        inverted_gains = [-gain for gain in gains]
        
        max_skip_sum = -float('inf')
        current_sum = 0
        for value in inverted_gains:
            current_sum = max(value, current_sum + value)
            max_skip_sum = max(max_skip_sum, current_sum)

        max_possible = base_rating + max_skip_sum
        results.append(max_possible)
    
    return "\n".join(map(str, results))

data = input().strip().split()
t = int(data[0])
test_cases = []
index = 1
for _ in range(t):
    n = int(data[index])
    a = list(map(int, data[index + 1: index + 1 + n]))
    test_cases.append((n, a))
    index += 1 + n

print(max_possible_rating(t, test_cases))
