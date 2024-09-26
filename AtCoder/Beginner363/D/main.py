def nth_smallest_palindrome(n):
    if n <= 9:
        return n
    
    n -= 1  # Adjust for 1-based indexing
    length = 1
    count = 9
    
    while n >= count:
        n -= count
        length += 1
        count = 9 * 10 ** (length // 2)
    
    if length % 2 == 0:
        left = 10 ** (length // 2 - 1) + n
        return int(str(left) + str(left)[::-1])
    else:
        left = 10 ** (length // 2) + n // 10
        middle = n % 10
        return int(str(left) + str(middle) + str(left)[::-1][1:])


print(nth_smallest_palindrome(int(input())))