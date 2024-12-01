import random
import os
import subprocess

def naive_solution(T, test_cases):
  results = []
  for case in test_cases:
      N, h, a, t = case
      # Sort plants by their target t in descending order (highest rank first)
      target_order = sorted(range(N), key=lambda i: t[i])

      # Simulate day by day
      day = 0
      while day < 1e2:  # Arbitrary large limit to avoid infinite loops
          # Calculate current heights
          heights = [h[i] + day * a[i] for i in range(N)]
          # Sort plants by their heights in descending order
          sorted_by_height = sorted(range(N), key=lambda i: heights[i], reverse=True)

          # Map current order to the target order
          current_rank = {plant: rank for rank, plant in enumerate(sorted_by_height)}

          # Check if the condition is met
          if all(current_rank[i] == t[i] for i in range(N)):
              results.append(day)
              break

          # Check impossibility (e.g., same growth rates but conflicting targets)
          impossible = True
          for i in range(N):
              for j in range(i + 1, N):
                  if a[i] != a[j]:
                      impossible = False
                      break
              if not impossible:
                  break
          if impossible:
              results.append(-1)
              break

          day += 1
      else:
          results.append(-1)  # If no solution within the limit

  return results



def generate_test_case(N_min=1, N_max=3, h_min=1, h_max=5, a_min=1, a_max=5):
    N = random.randint(N_min, N_max)
    h = [random.randint(h_min, h_max) for _ in range(N)]
    a = [random.randint(a_min, a_max) for _ in range(N)]
    t = list(range(N))
    random.shuffle(t)
    return (N, h, a, t)

def write_test_case_to_file(file_path, T, test_cases):
    with open(file_path, 'w') as f:
        f.write(f"{T}\n")
        for case in test_cases:
            N, h, a, t = case
            f.write(f"{N}\n")
            f.write(" ".join(map(str, h)) + "\n")
            f.write(" ".join(map(str, a)) + "\n")
            f.write(" ".join(map(str, t)) + "\n")

def read_output_from_file(file_path):
    with open(file_path, 'r') as f:
        return [int(line.strip()) for line in f.readlines()]

def main():
    # Number of test cases
    T = 10000
    test_cases = [generate_test_case(N_min=2, N_max=10) for _ in range(T)]

    # Write test cases to input file
    input_file = "test_input.txt"
    output_file = "test_output.txt"
    write_test_case_to_file(input_file, T, test_cases)

    # Run the naive solution
    naive_results = naive_solution(T, test_cases)

    # Run the main executable and capture its output
    try:
        with open(output_file, 'w') as f:
            subprocess.run(["./main"], stdin=open(input_file, 'r'), stdout=f, check=True)
        main_results = read_output_from_file(output_file)
    except Exception as e:
        print(f"Error running main executable: {e}")
        return

    # Compare results
    for i in range(T):
        if naive_results[i] != main_results[i]:
            print(f"Mismatch found in test case {i+1}!")
            print(f"Test case: {test_cases[i]}")
            print(f"Naive result: {naive_results[i]}")
            print(f"Main result: {main_results[i]}")
            exit()
        if (i+1) % 100 == 0:
            print(f"Completed {i+1} test cases")

if __name__ == "__main__":
    main()
