import subprocess
import random

def generate_test_case(max_n=100000, max_k=100000, max_coord=10**9, max_t=100000):
    """
    Generates a random large test case based on the problem constraints.
    :param max_n: Maximum number of trees.
    :param max_k: Maximum number of restrictions.
    :param max_coord: Maximum absolute value for tree coordinates.
    :param max_t: Maximum value for t_i in restrictions.
    """
    # Randomize the number of trees and restrictions
    n = max_n # Ensure the range is large but not too extreme
    k = max_k

    # Generate tree positions
    trees = sorted(random.sample(range(-max_coord, max_coord), n))

    # Generate restrictions
    restrictions = []
    for _ in range(k):
        l = random.randint(-max_coord, max_coord - 1)
        r = random.randint(l, max_coord)
        t = random.randint(1, min(n, max_t))
        restrictions.append((l, r, t))

    return n, k, trees, restrictions


def format_test_case(n, k, trees, restrictions):
    """
    Formats the test case into a string for input to the programs.
    """
    test_case = f"{n} {k}\n"
    test_case += " ".join(map(str, trees)) + "\n"
    for l, r, t in restrictions:
        test_case += f"{l} {r} {t}\n"
    return test_case


def run_program(executable, test_case):
    """
    Runs the given executable with the test case as input.
    """
    try:
        result = subprocess.run(
            executable,
            input=test_case,
            text=True,
            stdout=subprocess.PIPE,
            stderr=subprocess.PIPE,
            timeout=10
        )
        return result.stdout.strip()
    except subprocess.TimeoutExpired:
        return "TIMEOUT"


def stress_test(iterations=100, max_n=100000, max_k=100000):
    """
    Performs the stress test for the given number of iterations with large test cases.
    """
    for i in range(iterations):
        # Generate a large random test case
        n, k, trees, restrictions = generate_test_case(max_n, max_k)
        test_case = format_test_case(n, k, trees, restrictions)
        
        # Run both programs
        main_output = run_program("./main", test_case)
        naive_output = run_program("./naive", test_case)
        
        # Compare results
        if main_output != naive_output:
            print(f"Test case {i + 1} failed!")
            print("Test case:")
            print(test_case)
            print("Main output:")
            print(main_output)
            print("Naive output:")
            print(naive_output)
            return  # Stop on the first failure
        else:
            print(f"Test case {i + 1} passed.")

    print("All test cases passed!")


if __name__ == "__main__":
    stress_test()