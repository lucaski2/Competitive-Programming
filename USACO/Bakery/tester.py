import random
import os
import subprocess
import math

def naive_solution(T, test_cases):
    results = []

    for t in range(T):
        N, t_c, t_m = test_cases[t]["N"], test_cases[t]["t_c"], test_cases[t]["t_m"]
        orders = test_cases[t]["orders"]

        def can_satisfy(upgrades_c, upgrades_m):
            new_t_c = t_c - upgrades_c
            new_t_m = t_m - upgrades_m

            if new_t_c <= 0 or new_t_m <= 0:
                return False

            for a, b, c in orders:
                if a * new_t_c + b * new_t_m > c:
                    return False

            return True

        # Binary search on the minimum total upgrades
        min_moonies = float('inf')
        for upgrades_c in range(t_c):
            low, high = 0, t_m - 1
            while low <= high:
                upgrades_m = (low + high) // 2
                if can_satisfy(upgrades_c, upgrades_m):
                    min_moonies = min(min_moonies, upgrades_c + upgrades_m)
                    high = upgrades_m - 1
                else:
                    low = upgrades_m + 1

        results.append(min_moonies)

    return results

def generate_test_case(T_min=1, T_max=1, N_min=1, N_max=5, t_min=1, t_max=10, a_b_c_min=1, a_b_c_max=10):
    T = random.randint(T_min, T_max)
    test_cases = []

    for _ in range(T):
        N = random.randint(N_min, N_max)
        t_c = random.randint(t_min, t_max)
        t_m = random.randint(t_min, t_max)

        orders = []
        for __ in range(N):
            a = random.randint(a_b_c_min, a_b_c_max)
            b = random.randint(a_b_c_min, a_b_c_max)
            c = random.randint(a + b, 2 * (a + b))
            orders.append((a, b, c))

        test_cases.append({"N": N, "t_c": t_c, "t_m": t_m, "orders": orders})

    return T, test_cases

def write_test_case_to_file(file_path, T, test_cases):
    with open(file_path, 'w') as f:
        f.write(f"{T}\n\n")
        for t in range(T):
            N, t_c, t_m = test_cases[t]["N"], test_cases[t]["t_c"], test_cases[t]["t_m"]
            f.write(f"{N} {t_c} {t_m}\n")
            for a, b, c in test_cases[t]["orders"]:
                f.write(f"{a} {b} {c}\n")
            if t < T - 1:
                f.write("\n")

def read_output_from_file(file_path):
    with open(file_path, 'r') as f:
        return list(map(int, f.read().strip().split()))

def main():
    # Generate test case
    while True:
      T, test_cases = generate_test_case(T_min=1, T_max=1, N_min=1, N_max=5)

      # Write test case to input file
      input_file = "main.in"
      output_file = "test_output.txt"
      write_test_case_to_file(input_file, T, test_cases)

      # Run the naive solution
      naive_result = naive_solution(T, test_cases)

      # Run the main executable and capture its output
      try:
          with open(output_file, 'w') as f:
              subprocess.run(["python3", "main.py"], stdin=open(input_file, 'r'), stdout=f, check=True)
          main_result = read_output_from_file(output_file)
      except Exception as e:
          print(f"Error running main executable: {e}")
          return

      # Compare results
      if naive_result != main_result:
          print(f"Mismatch found!")
          print(f"Test case:")
          print(f"T: {T}")
          for test_case in test_cases:
              print(test_case)
          print(f"Naive result: {naive_result}")
          print(f"Main result: {main_result}")
          break
      else:
          print("Test case passed.")

if __name__ == "__main__":
    main()
