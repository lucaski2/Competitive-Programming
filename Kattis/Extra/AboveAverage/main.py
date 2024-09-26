test_cases = int(input())

for i in range(test_cases):
    n = list(map(int, input().split()))
    avg = sum(n[1:]) / (len(n) - 1)
    amount = 0
    for i in range(1, len(n)):
        if n[i] > avg:
            amount += 1
    
    print(f"{amount / n[0] * 100:.3f}%")
