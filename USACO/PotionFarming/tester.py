import os
import random
import subprocess

def generate_test_case(N):
    """Generates a random test case for the problem."""
    potions = [random.randint(1, N) for _ in range(N)]
    edges = []

    for i in range(2, N + 1):
        parent = random.randint(1, i - 1)
        edges.append((parent, i))

    return N, potions, edges

def naive_solution(N, potions, edges):
    from collections import defaultdict, deque

    # Build adjacency list
    tree = defaultdict(list)
    for a, b in edges:
        tree[a].append(b)
        tree[b].append(a)

    visited = [False] * (N + 1)
    traversals = 0
    potion_count = 0

    def bfs(start):
        queue = deque([start])
        local_visited = []

        while queue:
            current = queue.popleft()
            if not visited[current]:
                visited[current] = True
                local_visited.append(current)
                for neighbor in tree[current]:
                    if not visited[neighbor]:
                        queue.append(neighbor)

        return local_visited

    for potion_room in potions:
        if not visited[potion_room]:
            traversals += 1
            visited_in_traversal = bfs(1)

            if potion_room in visited_in_traversal:
                potion_count += 1

    return potion_count

def write_test_case_to_file(filename, N, potions, edges):
    with open(filename, "w") as f:
        f.write(f"{N}\n")
        f.write(" ".join(map(str, potions)) + "\n")
        for a, b in edges:
            f.write(f"{a} {b}\n")

def read_output_from_file(filename):
    with open(filename, "r") as f:
        return int(f.read().strip())

def compare_outputs(test_case_file, main_cpp_output):
    # Parse test case
    with open(test_case_file, "r") as f:
        lines = f.readlines()

    N = int(lines[0].strip())
    potions = list(map(int, lines[1].strip().split()))
    edges = [tuple(map(int, line.strip().split())) for line in lines[2:]]

    # Run naive solution
    naive_output = naive_solution(N, potions, edges)

    # Compare outputs
    if naive_output == main_cpp_output:
        print("PASS")
    else:
        print("FAIL")
        print(f"Naive Output: {naive_output}, Main.cpp Output: {main_cpp_output}")

if __name__ == "__main__":
    # Settings
    NUM_TESTS = 10
    MAX_N = 10  # Change to higher values for stress testing

    for test_num in range(1, NUM_TESTS + 1):
        print(f"Running Test {test_num}")

        # Generate test case
        N = random.randint(2, MAX_N)
        N, potions, edges = generate_test_case(N)

        # Write test case to file
        test_case_file = "test_case.txt"
        write_test_case_to_file(test_case_file, N, potions, edges)

        # Run main.cpp
        subprocess.run(["./main"], stdin=open(test_case_file, "r"), stdout=open("main_output.txt", "w"))

        # Read output from main.cpp
        main_cpp_output = read_output_from_file("main_output.txt")

        # Compare outputs
        compare_outputs(test_case_file, main_cpp_output)

        # Clean up
        os.remove(test_case_file)
        os.remove("main_output.txt")
