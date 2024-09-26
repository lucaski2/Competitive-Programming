

# for asdf in range(int(input())):

#     a = list(input())
#     b = list(input())
#     answers = []

#     for start_num in range(100):
#         cur_amount = 0
#         before = []
#         after = []
#         middle = a.copy()

#         after_only = False
#         in_middle = False
#         middle_index = -1
        
#         for i in range(len(b)):
#             try:
#                 if b[i] in middle and not after_only and middle.index(b[i]) >= middle_index:
#                     if cur_amount >= start_num:
#                         ind = middle.index(b[i])
#                         middle.pop(ind)
#                         in_middle = True
#                         middle_index = ind
#                     else:
#                         cur_amount += 1
#                         before.append(b[i])
#                 elif (b[i] not in middle or not middle.index(b[i]) >= middle_index) and in_middle:
#                     after_only = True
#                     after.append(b[i])
#                     in_middle = False

#                 elif after_only:
#                     after.append(b[i])
#                 else:
#                     before.append(b[i])
#             except:
#                 if after_only:
#                     after.append(b[i])
#                 else:
#                     before.append(b[i])
#         answers.append(len(before) + len(after) + len(a))



#         # elif after_only:
#         #     after.append(b[i])
#         # else:
#         #     before.append(b[i])
    
#     print(min(answers))
#     # break
        




for _ in range(int(input())):
    a = input()
    b = input()

    ans = len(a) + len(b)

    for i in range(len(b)):
        cur = i
        for j in range(len(a)):
            if cur < len(b) and b[cur] == a[j]:
                cur += 1
            
            ans = min(ans, len(a) + len(b) - cur + i)
    
    print(ans)














