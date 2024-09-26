import random
out = open("main.in", 'w')
print("".join([random.choice([">", "<"]) for _ in range(200000)]), file=out)
print("".join([random.choice([">", "<"]) for _ in range(200000)]), file=out)
