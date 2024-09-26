def solve():
    t = int(input())
    results = []
    
    for _ in range(t):
        n = int(input())
        p = list(map(int, input().split()))
        s = input().strip()
        
        visited = [False] * n
        F = [0] * n
        
        for i in range(n):
            if not visited[i]:
                # Traverse the cycle starting from i
                cycle = []
                x = i
                while not visited[x]:
                    visited[x] = True
                    cycle.append(x)
                    x = p[x] - 1  # move to the next index in the cycle
                
                # Count number of black integers in this cycle
                black_count = sum(1 for idx in cycle if s[idx] == '0')
                
                # Assign this count to all indices in this cycle
                for idx in cycle:
                    F[idx] = black_count
        
        results.append(" ".join(map(str, F)))
    
    # Output all results
    print("\n".join(results))

# Example usage:
solve()
