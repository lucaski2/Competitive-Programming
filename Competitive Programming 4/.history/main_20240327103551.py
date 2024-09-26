test_cases = int(input())
letters = list("ABCDEFGH")
numbers = list("12345678")

for i in range(test_cases):
    coordinates = input().split(' ')
    if (letters.index(coordinates[0]) + numbers.index(coordinates[1])) % 2 !=  (letters.index(coordinates[2]) + numbers.index(coordinates[3])) % 2:
        print("Impossible")
    
        
    