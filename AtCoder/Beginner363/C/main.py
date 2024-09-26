from itertools import permutations
from collections import Counter
import math

def count_non_palindrome_perms(s, k):
    n = len(s)
    char_count = Counter(s)
    
    def can_form_palindrome(substring):
        return sum(count % 2 for count in Counter(substring).values()) <= 1

    def dfs(current, remaining):
        if len(current) == n:
            for i in range(n - k + 1):
                if can_form_palindrome(current[i:i+k]):
                    return 0
            return 1

        count = 0
        for char in set(remaining):
            new_current = current + char
            new_remaining = remaining - Counter({char: 1})
            count += dfs(new_current, new_remaining)
        
        return count

    return dfs('', char_count)

n, k = map(int, input().split())
s = input().strip()
if len(set(s)) == len(s):
    print(math.factorial(len(s)))
else:
    print(count_non_palindrome_perms(s, k))