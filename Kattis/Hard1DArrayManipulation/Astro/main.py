from math import gcd
start1 = list(map(int, input().split(":")))
start2 = list(map(int, input().split(":")))
interval1 = list(map(int, input().split(":")))
interval2 = list(map(int, input().split(":")))

# turn into minutes
start1 = start1[0] * 60 + start1[1]
start2 = start2[0] * 60 + start2[1]
interval1 = interval1[0] * 60 + interval1[1]
interval2 = interval2[0] * 60 + interval2[1]

flash1 = start1
flash2 = start2

while flash1 != flash2 and flash1 < 10**6:
    if flash1 > flash2:
        flash2 += interval2
    else:
        flash1 += interval1



if flash1 == flash2:
    indexes = {0:"Saturday", 1:"Sunday", 2:"Monday", 3:"Tuesday", 4:"Wednesday", 5:"Thursday", 6:"Friday"}
    # print day from saturday, hour, and minute
    print(f"{indexes[((flash1 // 60) // 24) % 7]} \n{(flash1 // 60) % 24:02d}:{flash1 % 60:02d}")
else:
    print("Never")






