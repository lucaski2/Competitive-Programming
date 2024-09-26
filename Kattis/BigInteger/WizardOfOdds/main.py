import math
inp = list(map(int, input().split()))
print("Your wish is granted!" if math.log(inp[0], 2) <= inp[1] else "You will become a flying monkey!")