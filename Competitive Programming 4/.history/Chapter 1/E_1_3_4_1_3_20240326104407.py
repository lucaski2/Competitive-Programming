import datetime

year = int(input())
month = int(input())
day = int(input())

weekdays = []

datetime.datetime(year, month, day).weekday()
