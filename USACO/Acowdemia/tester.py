# tester.py
import random
import subprocess

def generate_test_case(max_n=1000, max_l=10**5, max_c=10**5):
    """Generate a random test case."""
    n = random.randint(1, max_n)
    l = random.randint(0, max_l)
    citations = [random.randint(0, max_c) for _ in range(n)]
    return n, l, citations

def run_script(script, n, l, citations):
    """Run a script with input and return its output."""
    input_data = f"{n} {l}\n" + " ".join(map(str, citations)) + "\n"
    result = subprocess.run(["python3", script], input=input_data, text=True, capture_output=True)
    return result.stdout.strip()

if __name__ == "__main__":
    for _ in range(1000):
        n, l, citations = generate_test_case()
        naive_output = run_script("naive.py", n, l, citations)
        main_output = run_script("main.py", n, l, citations)
        if naive_output != main_output:
            print("Mismatch found!")
            print(f"Input: {n} {l} {citations}")
            print(f"Naive Output: {naive_output}")
            print(f"Main Output: {main_output}")
            break
    else:
        print("All test cases passed!")
