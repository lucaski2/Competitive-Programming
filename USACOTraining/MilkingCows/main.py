"""
USER: lucaski2
TASK: milk2
LANG: PYTHON3
"""

def find_longest_intervals(times):
    if not times:
        return 0, 0

    # Sort the intervals by start time
    times.sort(key=lambda x: x[0])

    longest_milking = 0
    longest_idle = 0
    current_start = times[0][0]
    current_end = times[0][1]

    for start, end in times[1:]:
        if start > current_end:
            # Found an idle period
            idle_time = start - current_end
            longest_idle = max(longest_idle, idle_time)
            
            # Update milking time
            milking_time = current_end - current_start
            longest_milking = max(longest_milking, milking_time)
            
            # Start a new milking period
            current_start = start
            current_end = end
        else:
            # Extend the current milking period if necessary
            current_end = max(current_end, end)

    # Check the last milking period
    milking_time = current_end - current_start
    longest_milking = max(longest_milking, milking_time)

    return longest_milking, longest_idle

def main():
    # Read input
    with open('milk2.in', 'r') as f:
        n = int(f.readline().strip())
        times = []
        for _ in range(n):
            start, end = map(int, f.readline().split())
            times.append((start, end))

    # Process the data
    longest_milking, longest_idle = find_longest_intervals(times)

    # Write output
    with open('milk2.out', 'w') as f:
        f.write(f"{longest_milking} {longest_idle}\n")

if __name__ == "__main__":
    main()