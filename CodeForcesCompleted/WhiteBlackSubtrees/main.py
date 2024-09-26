
for _ in range(int(input())):
    n = int(input())
    graph = [[] for _ in range(n)]
    a = list(map(int, input().split()))
    s = input()
    
    for i in range(n-1):
        graph[a[i]-1].append(i + 1)
        
    ans = 0
    stack = [(0, 0)]  # (current node, 0 = first visit, 1 = process after children)
    white_black_counts = [[0, 0] for _ in range(n)]  # Stores (white_count, black_count) for each node
    
    # Iterative DFS using stack
    while stack:
        node, state = stack.pop()

        if state == 0:  # First visit
            stack.append((node, 1))  # Push the node back to process after children
            # Add all children to the stack for processing
            for neighbor in graph[node]:
                stack.append((neighbor, 0))
        else:  # Process after children have been visited
            cur_white = white_black_counts[node][0]
            cur_black = white_black_counts[node][1]
            
            if s[node] == 'W':
                cur_white += 1
            else:
                cur_black += 1

            if cur_white == cur_black:
                ans += 1

            if node != 0:  # Update the parent's white and black counts
                parent = a[node-1] - 1  # The parent is indexed by the node's parent in the input
                white_black_counts[parent][0] += cur_white
                white_black_counts[parent][1] += cur_black

            white_black_counts[node] = [cur_white, cur_black]

    print(ans)
