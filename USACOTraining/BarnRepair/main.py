"""
ID: lucaski2
LANG: PYTHON3
TASK: barn1 
"""


def min_stalls_blocked(M, S, C, occupied_stalls):
    if M >= C:
        # More boards than cows; each cow can have its own board
        return C

    # Sort the list of occupied stalls
    occupied_stalls.sort()

    # Calculate the gaps between consecutive occupied stalls
    gaps = []
    for i in range(1, C):
        gaps.append(occupied_stalls[i] - occupied_stalls[i - 1] - 1)
    
    # Sort gaps in descending order
    gaps.sort(reverse=True)
    
    # We use M-1 largest gaps to separate M boards
    # Sum up the blocked stalls ignoring the largest M-1 gaps
    total_blocked = occupied_stalls[-1] - occupied_stalls[0] + 1 - sum(gaps[:M - 1])
    
    return total_blocked

# Read from input file 'barn1.in' and output to 'barn1.out'
with open("barn1.in", "r") as fin:
    M, S, C = map(int, fin.readline().strip().split())
    occupied_stalls = [int(fin.readline().strip()) for _ in range(C)]

# Calculate the result
result = min_stalls_blocked(M, S, C, occupied_stalls)

# Write the result to the output file
with open("barn1.out", "w") as fout:
    fout.write(f"{result}\n")
