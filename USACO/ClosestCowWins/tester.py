import os
import random
k = 3
n = 2
m = 2
max_coord = 8

n_tests = 0
while True:
  # 3. Generate test
  f = open('main.in', 'w')
  f.write(f'{k} {m} {n}\n')
  coordinates = list(range(1, max_coord + 1))
  random.shuffle(coordinates)
  for i in range(k):
    p = coordinates[i]
    t = random.randint(1, 10)
    f.write(f'{p} {t}\n')
  for i in range(m):
    fi = coordinates[i + k]
    f.write(f'{fi}\n')
  f.close()
  # 2. Run solutions
  os.system('./main < main.in > output.txt')
  os.system('./naive < main.in > answer.txt')
  # 3. Compare results
  # check if last line of output.txt is equal to last line of answer.txt
  f = open('output.txt', 'r')
  lines = f.readlines()
  f.close()
  f = open('answer.txt', 'r')
  answer_lines = f.readlines()
  f.close()

  if lines[-1] != answer_lines[-1]:
    print("FOUND BUG!")
    print(lines[-1].strip(), answer_lines[-1].strip())
    break


  n_tests += 1
  if n_tests % 100 == 0:
    print(f'OK: {n_tests} tests')