
def binary_search(arr, x):
    l, r = 0, len(arr) - 2
    while l <= r:
        mid = (l + r) // 2
        if arr[mid] == x:
            return True
        elif arr[mid] < x:
            l = mid + 1
        else:
            r = mid - 1
    return False


for _ in range(int(input())):
    n = int(input())
    a = list(map(int, input().split()))
    pref = [0]
    ans = 0
    for i in range(n):
        pref.append(pref[-1] + a[i])
        if a[i] == 0:
            ans += 1
            pref = [0]
            pref.append(a[i])
            continue
        if binary_search(pref, pref[-1]):
            ans += 1
            pref = [0]
            pref.append(a[i])
    print(ans)