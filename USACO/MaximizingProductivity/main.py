import bisect

def solve():
    # Read input
    N, Q = map(int, input().split())
    closing_times = list(map(int, input().split()))
    travel_times = list(map(int, input().split()))

    # Precompute the maximum wake-up time for each farm
    max_wakeup_times = [closing_times[i] - travel_times[i] for i in range(N)]
    
    # Sort the max wake-up times
    max_wakeup_times.sort()
    
    # Handle each query
    for _ in range(Q):
        V, S = map(int, input().split())
        
        # Find the number of farms Bessie can visit
        index = bisect.bisect_right(max_wakeup_times, S)
        # Number of farms she can visit
        num_farms_she_can_visit = N - index
        
        # Check if she can visit at least V farms
        if num_farms_she_can_visit >= V:
            print("YES")
        else:
            print("NO")

solve()