import hashlib
import random
import time
import requests
import csv

# Replace these with your Codeforces API key, secret, and handle
with open('key.txt', 'r') as file:
    API_KEY = file.read()
with open('secret.txt', 'r') as file:
    API_SECRET = file.read()

HANDLE = "lucaski2"  # Replace with your Codeforces handle

# API Base URL
BASE_URL = "https://codeforces.com/api/"

class Sorter:
    def __init__(self, contest, problem):
        self.contest = contest
        self.problem = problem
    
    def __lt__(self, other):
        if self.contest == other.contest:
            return self.problem < other.problem
        return self.contest < other.contest
    def toString(self):
        return f'{self.contest}-{self.problem}'
    # equals method for set
    def __eq__(self, other):
        return self.contest == other.contest and self.problem == other.problem
    def __hash__(self):
        return hash((self.contest, self.problem))



# Generate API signature
def generate_api_signature(method, params):
    rand_str = str(random.randint(100000, 999999))  # Random 6-digit number
    params_sorted = "&".join(f"{key}={value}" for key, value in sorted(params.items()))
    to_hash = f"{rand_str}/{method}?{params_sorted}#{API_SECRET}"
    hashed = hashlib.sha512(to_hash.encode()).hexdigest()
    return rand_str + hashed

# Fetch all rated problems from Codeforces
def fetch_problems():
    method = "problemset.problems"
    params = {
        "apiKey": API_KEY,
        "time": int(time.time())
    }
    api_sig = generate_api_signature(method, params)
    params["apiSig"] = api_sig

    try:
        response = requests.get(BASE_URL + method, params=params)
        response_data = response.json()
        if response_data["status"] != "OK":
            print("Error fetching problems:", response_data.get("comment", "Unknown error"))
            return []

        problems = response_data["result"]["problems"]
        rated_problems = [
            Sorter(problem["contestId"], problem["index"])
            for problem in problems
            if "rating" in problem
        ]

        return rated_problems

    except requests.RequestException as e:
        print("Request failed:", str(e))
        return []

# Process submissions to extract solved problems
def get_solved_problems(submissions):
    solved_problems = set()
    unsolved = set()
    for submission in submissions:
        if submission.get("verdict") == "OK":
            
            problem = submission["problem"]
            if int(problem['contestId']) > 2500:
                continue
            solved_problems.add(Sorter(problem["contestId"], problem["index"]))
        else:
            
            problem = submission["problem"]
            if int(problem['contestId']) > 2500 or Sorter(problem["contestId"], problem["index"]) in solved_problems:
                continue

            unsolved.add(Sorter(problem["contestId"], problem["index"]))
    solved_problems = list(solved_problems)
    unsolved = list(unsolved)
    solved_problems.sort()
    unsolved.sort()
    
    return solved_problems, unsolved        
    
    

# Save solved problems to a CSV file
def save_to_csv(problems, filename="solved_problems.csv"):
    with open(filename, mode="w", newline="") as file:
        writer = csv.writer(file)
        for problem in problems:
            writer.writerow([problem.toString()])
    print(f"{filename.split('_')[0]} problems saved to {filename}")

# Main function with rate limiting
def main():
    submissions = fetch_submissions()
    if not submissions:
        print("No submissions fetched.")
        return

    solved_problems, unsolved = get_solved_problems(submissions)
    if not solved_problems:
        print("No solved problems found.")
    else:
        save_to_csv(solved_problems)
    if not unsolved:
        print("All problems solved")
    else:
        save_to_csv(unsolved, "unsolved_problems.csv")

    # Enforce rate limiting (1 request per 2 seconds)
    time.sleep(2)

if __name__ == "__main__":
    main()
