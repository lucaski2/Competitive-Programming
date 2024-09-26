
def large_int(n):
    # check if all digits are greater than 5
    if all(int(i) > 5 for i in str(n)):
        return True
    return False

def get_next_large_int(n):
    n = list(str(n))

    for i in range(len(n) - 1, -1, -1):
        if int(n[i]) < 5:
            n[i] = '5'
        else:
            break

        
    return int("".join(n))




for _ in range(int(input())):

    n = int(input())

    if n % 10 == 9:
        print("NO")
        continue
    n //= 10
    
    while n > 9:
        if n % 10 == 0:
            print("NO")
            break
        n //= 10
    
    else:
        if n == 1:
            print("YES")
        else:
            print("NO")
