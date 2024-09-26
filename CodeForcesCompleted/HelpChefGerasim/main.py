def detect_juice_pouring(volumes):
    n = len(volumes)
    total = sum(volumes)
    average = total / n
    
    if not average.is_integer():
        return "Unrecoverable configuration."
    
    average = int(average)
    
    below = []
    above = []
    
    for i, volume in enumerate(volumes, 1):
        diff = volume - average
        if diff < 0:
            below.append((i, abs(diff)))
        elif diff > 0:
            above.append((i, diff))
    
    if not below and not above:
        return "Exemplary pages."
    
    if len(below) == 1 and len(above) == 1:
        from_cup, volume = below[0]
        to_cup, _ = above[0]
        if volume == above[0][1]:
            return f"{volume} ml. from cup #{from_cup} to cup #{to_cup}."
    
    return "Unrecoverable configuration."

# Read input
n = int(input())
volumes = [int(input()) for _ in range(n)]

# Detect and print the result
result = detect_juice_pouring(volumes)
print(result)