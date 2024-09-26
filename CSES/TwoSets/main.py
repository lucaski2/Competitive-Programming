
# https://cses.fi/problemset/task/1092
# Two Sets

# You have two sets of numbers: {1,2,...,n} and {}. Your task is to divide the numbers 1,2,...,n into two sets so that the sum of the numbers in the first set is as close to the sum of the numbers in the second set as possible.

def two_set():
    n = int(input())
    total = n * (n + 1) // 2
    if total % 2 == 0:
        print("YES")
        first_set = []
        second_set = []
        total //= 2
        while n:
            if total - n >= 0:
                first_set.append(n)
                total -= n
            else:
                second_set.append(n)
            n -= 1
        print(len(first_set))
        print(" ".join(map(str, first_set)))
        print(len(second_set))
        print(" ".join(map(str, second_set)))
    else:
        print("NO")
two_set()
