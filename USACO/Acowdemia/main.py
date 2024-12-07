def max_h_index(n, l, citations):
    # Sort citations in descending order
    citations.sort(reverse=True)
    
    # Step 1: Calculate the current h-index
    h = 0
    for i in range(n):
        if citations[i] >= i + 1:
            h += 1
        else:
            break
    
    # Step 2: Check if h+1 can be achieved
    for i in range(h, -1, -1):
      if l <= 0:
        break
      l -= 1
      citations[i] += 1
    citations.sort(reverse=True)
    h = 0
    for i in range(n):
        if citations[i] >= h + 1:
            h += 1
        else:
            break
    return h
  


n, l = map(int, input().split())

citations = list(map(int, input().split()))
print(max_h_index(n, l, citations))
