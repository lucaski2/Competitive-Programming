for _ in range(int(input())):
    n = int(input())
    a = list(input())
    print(min(a.count("A"), n) + min(a.count("B"), n) + min(a.count("C"), n) + min(a.count("D"), n))
    