
for _ in range(int(input())):
    a, b = map(int, input().split())
    a = a + b
    print("Bob" if a % 2 == 0 else "Alice")