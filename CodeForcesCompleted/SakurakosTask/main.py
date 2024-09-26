def find_mex_k(n, k, arr):
    arr = sorted(set(arr))
    mex = 0
    missing_count = 0
    
    for num in arr:
        if num == mex:
            mex += 1
        else:
            while mex < num:
                missing_count += 1
                if missing_count == k:
                    return mex
                mex += 1
    
    # If we've checked all elements and haven't found mex_k yet
    while missing_count < k:
        missing_count += 1
        mex += 1
    
    return mex

# Read number of test cases
t = int(input().strip())
results = []

# Process each test case
for _ in range(t):
    n, k = map(int, input().strip().split())
    arr = list(map(int, input().strip().split()))
    results.append(find_mex_k(n, k, arr))

# Output the results for all test cases
for result in results:
    print(result)
