import random
import os
import subprocess

def naive_solution(G, N, grazings, alibis):
    def noreach(x1, y1, t1, x2, y2, t2):
        
        return (x1-x2)**2 + (y1-y2)**2 > (t2-t1)**2

    innocent_count = 0

    for cx, cy, ct in alibis:
        guilty = True

        for gx, gy, gt in grazings:
            if noreach(gx, gy, gt, cx, cy, ct):
                guilty = False
                break

        if not guilty:
            innocent_count += 1

    return innocent_count


def generate_test_case(G_min=1, G_max=10, N_min=1, N_max=10, coord_min=-5, coord_max=5, time_min=0, time_max=5):
    G = random.randint(G_min, G_max)
    N = random.randint(N_min, N_max)

    grazings = [
        (
            random.randint(coord_min, coord_max),
            random.randint(coord_min, coord_max),
            random.randint(time_min, time_max)
        ) for _ in range(G)
    ]

    alibis = [
        (
            random.randint(coord_min, coord_max),
            random.randint(coord_min, coord_max),
            random.randint(time_min, time_max)
        ) for _ in range(N)
    ]

    return G, N, grazings, alibis

def write_test_case_to_file(file_path, G, N, grazings, alibis):
    with open(file_path, 'w') as f:
        f.write(f"{G} {N}\n")
        for x, y, t in grazings:
            f.write(f"{x} {y} {t}\n")
        for x, y, t in alibis:
            f.write(f"{x} {y} {t}\n")

def read_output_from_file(file_path):
    with open(file_path, 'r') as f:
        return int(f.read().strip())

def main():
    count = 0
    while True:
      # Generate test case
      G, N, grazings, alibis = generate_test_case(G_min=2, G_max=2, N_min=2, N_max=2)

      # Write test case to input file
      input_file = "main.in"
      output_file = "test_output.txt"
      write_test_case_to_file(input_file, G, N, grazings, alibis)

      # Run the naive solution
      naive_result = naive_solution(G, N, grazings, alibis)

      # Run the main executable and capture its output
      try:
          with open(output_file, 'w') as f:
              subprocess.run(["./main"], stdin=open(input_file, 'r'), stdout=f, check=True)
          main_result = read_output_from_file(output_file)
      except Exception as e:
          print(f"Error running main executable: {e}")
          return

      # Compare results
      if naive_result != main_result:
          print(f"Mismatch found!")
          print(f"Test case:\nG: {G}, N: {N}\nGrazings: {grazings}\nAlibis: {alibis}")
          print(f"Naive result: {naive_result}")
          print(f"Main result: {main_result}")
          break
      else:
          count += 1
          print(count)

if __name__ == "__main__":
    main()
