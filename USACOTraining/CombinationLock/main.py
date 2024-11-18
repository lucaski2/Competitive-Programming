"""
ID: lucaski2
LANG: PYTHON3
TASK: combo
"""

def get_nearby_numbers(pos, N):
    """Return a set of positions within 2 steps of `pos` on a circular dial of size `N`."""
    return {(pos + i - 1) % N + 1 for i in range(-2, 3)}

def generate_nearby_combinations(combo, N):
    """Generate all nearby combinations for a given combination on a dial of size `N`."""
    nearby1 = get_nearby_numbers(combo[0], N)
    nearby2 = get_nearby_numbers(combo[1], N)
    nearby3 = get_nearby_numbers(combo[2], N)
    return {(x, y, z) for x in nearby1 for y in nearby2 for z in nearby3}

def count_distinct_open_combinations(N, farmer_combo, master_combo):
    # Generate all nearby combinations for Farmer John's and master combinations
    farmer_nearby = generate_nearby_combinations(farmer_combo, N)
    master_nearby = generate_nearby_combinations(master_combo, N)
    
    # Combine both sets to get unique combinations
    all_nearby_combinations = farmer_nearby | master_nearby
    
    # The result is the number of unique combinations
    return len(all_nearby_combinations)

# Main function to read input and output result
def main():
    # Read input
    with open("combo.in", "r") as fin:
        N = int(fin.readline().strip())
        farmer_combo = tuple(map(int, fin.readline().strip().split()))
        master_combo = tuple(map(int, fin.readline().strip().split()))
    
    # Calculate result
    result = count_distinct_open_combinations(N, farmer_combo, master_combo)
    
    # Write output
    with open("combo.out", "w") as fout:
        fout.write(f"{result}\n")

# Execute the main function if running as a script
if __name__ == "__main__":
    main()
