import datetime

year = int(input())
month = int(input())
day = int(input())

print(datetime.datetime(year, month, day).weekday())