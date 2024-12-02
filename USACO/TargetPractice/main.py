
t, c = map(int, input().split())

targets = set(map(int, input().split()))

pos_directions = "LFR"
directions = list(input())

ans = 0
for i in range(c):

  for cur in pos_directions:
    cur_targets = targets.copy()
    cur_pos = 0
    loc_ans = 0
    for j in range(c):
      cur_char = directions[j]
      if j == i:
        cur_char = cur
      
      if cur_char == "L":
        cur_pos -= 1
      elif cur_char == "R":
        cur_pos += 1
      
      elif cur_char == "F" and cur_pos in cur_targets:
        cur_targets.remove(cur_pos)
        loc_ans += 1
    ans = max(ans, loc_ans)
print(ans)

  

        
        





