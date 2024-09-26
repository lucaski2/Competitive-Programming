n, k = map(int, input().split())
a = list(map(int, input().split()))

# psum = [0]
# for i in range(n):
#     psum.append(psum[-1] + a[i])
# # print(psum)
# counts = {}
# ans = 0
# for i in range(n + 1):
#     if psum[i] - k in counts:
#         ans += counts[psum[i] - k]
#         if psum[i] in counts:
#             counts[psum[i]] += 1
#         else:
#             counts[psum[i]] = 1
#     else:
#         counts[psum[i]] = 1 if psum[i] not in counts else counts[psum[i]] + 1

# print(ans)

counts = {}
ans = 0
cur_s = 0

for i in range(n + 1):
    if cur_s - k in counts:
        ans += counts[cur_s - k]
    if cur_s in counts:
        counts[cur_s] += 1
    else:
        counts[cur_s] = 1
    if i != n:
        cur_s += a[i]
print(ans)