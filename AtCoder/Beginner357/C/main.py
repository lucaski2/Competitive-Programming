


# def carpet(a):
#     if a == 0:
#         print("#")
#     elif a == 1:
#         for i in range(pow(3, a - 1)):
#             print("#" * pow(3, a))

#         for i in range(pow(3, a - 1)):
#             print("#" * pow(3, a - 1), end = "")
#             print("." * pow(3, a - 1), end="")
#             print("#" * pow(3, a - 1))



#         for i in range(pow(3, a - 1)):
#             print("#" * pow(3, a))
#     else:



def sierpinski_carpet(n):
    def carpet(size):
        if size == 1:
            return ['#']
        
        smaller = carpet(size // 3)
        
        top = [row * 3 for row in smaller]
        middle = [row + '.' * (size // 3) + row for row in smaller]
        
        return top + middle + top

    result = carpet(3 ** n)
    for row in result:
        print(row)
        


start = int(input())
sierpinski_carpet(start)


