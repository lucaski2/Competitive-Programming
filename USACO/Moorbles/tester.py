import random
import subprocess

def generate_testcases():
    # Generate random testcases
    T = 1
    testcases = []

    for _ in range(T):
        N = random.randint(1, 10**9)  # Elsie's initial marbles
        M = random.randint(1, 16) if T == 3 else random.randint(1, 10) if 4 <= T <= 6 else random.randint(1, 10)
        K = random.randint(1, 4)  # Number of possible moves per turn

        possible_moves = []
        for _ in range(M):
            moves = random.sample(range(1, 10), K)  # Ensure unique moves per turn
            possible_moves.append(moves)

        testcases.append((N, M, K, possible_moves))

    return testcases

def naive_solution(N, M, K, possible_moves):
    # A naive solution to ensure Elsie does not lose
    marbles = N
    sequence = []

    for i in range(M):
        if marbles == 0:
            return -1  # Elsie loses

        if all(m % 2 == 0 for m in possible_moves[i]):
            sequence.append("Even")
        elif all(m % 2 == 1 for m in possible_moves[i]):
            sequence.append("Odd")
        else:
            sequence.append("Even") if marbles % 2 == 0 else sequence.append("Odd")

        # Simulate a possible game scenario to update marbles
        move = min(possible_moves[i])  # Choose the smallest move
        if (sequence[-1] == "Even" and move % 2 == 0) or (sequence[-1] == "Odd" and move % 2 == 1):
            marbles += move
        else:
            marbles = max(0, marbles - move)

    return sequence

def main():
    # Generate test cases
    testcases = generate_testcases()

    # Write test cases to a file
    with open("main.in", "w") as f:
        f.write(f"{len(testcases)}\n")
        for N, M, K, moves in testcases:
            f.write(f"{N} {M} {K}\n")
            for move_set in moves:
                f.write(" ".join(map(str, move_set)) + "\n")

    # Generate outputs for comparison
    with open("output_naive.txt", "w") as f:
        for N, M, K, moves in testcases:
            result = naive_solution(N, M, K, moves)
            if result == -1:
                f.write("-1\n")
            else:
                f.write(" ".join(result) + "\n")

    # Run the main program
    with open("main.in", "r") as input_file, open("output_main.txt", "w") as output_file:
        subprocess.run(["python3", "main.py"], stdin=input_file, stdout=output_file, text=True)

    # Compare outputs
    with open("output_naive.txt", "r") as naive, open("output_main.txt", "r") as main_out:
        naive_output = naive.readlines()
        main_output = main_out.readlines()

        if naive_output == main_output:
            print("Outputs match!")
        else:
            print("Outputs differ!")
            for i, (naive_line, main_line) in enumerate(zip(naive_output, main_output), 1):
                if naive_line != main_line:
                    print(f"Mismatch at line {i}:\nNaive: {naive_line}Main: {main_line}")

if __name__ == "__main__":
    main()
