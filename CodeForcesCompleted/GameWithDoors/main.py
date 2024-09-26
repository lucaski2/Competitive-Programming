
def overlap(start1, end1, start2, end2) -> int:
    return max(0, min(end1, end2) - max(start1, start2))

for _ in range(int(input())):
    pa = list(map(int, input().split()))
    pb = list(map(int, input().split()))
    
    
