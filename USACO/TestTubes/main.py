
for _ in range(int(input())):
  n, p = map(int, input().split())
  tube1 = list(map(int, list(input())))
  tube2 = list(map(int, list(input())))
  tube1.reverse()
  tube2.reverse()

  # create groupings for tube1 and tube2
  tube1_groupings = []
  tube2_groupings = []

  last = None
  count = 0
  for i in range(n):
    if tube1[i] != last:
      if last != None:
        tube1_groupings.append(last)
      last = tube1[i]
      count = 1
    else:
      count += 1
  
  tube1_groupings.append(last)

  last = None
  count = 0
  for i in range(n):
    if tube2[i] != last:
      if last != None:
        tube2_groupings.append(last)
      last = tube2[i]
      count = 1
    else:
      count += 1
  
  tube2_groupings.append(last)
  tube_groupings = [tube1_groupings, tube2_groupings]
  



  min_steps = 10**9
  min_reconstruction = None

  for start_tube in [0, 1]:
    for target_liquid in [1, 2]:
      tubes = [tube1_groupings.copy(), tube2_groupings.copy()]
      
      reconstruction = []
      beaker_used = False
      other_used = False
      for ind, group in enumerate(tubes[start_tube]):
        if group == target_liquid:
          # move to beaker
          reconstruction.append((start_tube + 1, 3))
          beaker_used = True
        elif (ind != len(tubes[start_tube]) - 1):
          # move to other tube
          reconstruction.append((start_tube + 1, 1 - start_tube + 1))
          other_used = True
      if other_used:
        # append non target liquid to other tube
        tubes[1 - start_tube].insert(0, 3 - target_liquid)
      
      for ind, group in enumerate(tubes[1 - start_tube]):
        if group == target_liquid and ind != len(tubes[1 - start_tube]) - 1:
          # move to beaker
          reconstruction.append((2 - start_tube, 3))
          beaker_used = True
        else:
          # move to other tube
          reconstruction.append((2 - start_tube, start_tube + 1))
          other_used = True
      
      reconstruction.append((3, 2 - start_tube))
      if len(reconstruction) < min_steps:
        min_steps = len(reconstruction)
        min_reconstruction = reconstruction
  
  print(min_steps)
  print(*reconstruction, sep='\n')
      

      
      
        
        
      


      
      


