"""
ID: lucaski2
LANG: PYTHON3
TASK: crypt1
"""

def is_valid_number(num, length, allowed_digits):
    """Check if all digits in num are in allowed_digits and has specified length."""
    num_str = str(num)
    return len(num_str) == length and all(int(d) in allowed_digits for d in num_str)

def count_cryptarithm_solutions(allowed_digits):
    solutions = 0
    # Generate all valid 3-digit numbers (abc)
    for a in allowed_digits:
        for b in allowed_digits:
            for c in allowed_digits:
                abc = 100 * a + 10 * b + c

                # Generate all valid 2-digit numbers (de)
                for d in allowed_digits:
                    for e in allowed_digits:
                        de = 10 * d + e
                        
                        # Calculate partial products
                        partial1 = e * abc
                        partial2 = d * abc
                        
                        # Calculate the final product
                        product = de * abc
                        
                        # Check all conditions
                        if (is_valid_number(partial1, 3, allowed_digits) and
                            is_valid_number(partial2, 3, allowed_digits) and
                            is_valid_number(product, 4, allowed_digits)):
                            solutions += 1
    return solutions

# Main function to read input and write output
def main():
    with open("crypt1.in", "r") as fin:
        N = int(fin.readline().strip())
        allowed_digits = list(map(int, fin.readline().strip().split()))
    
    result = count_cryptarithm_solutions(allowed_digits)

    with open("crypt1.out", "w") as fout:
        fout.write(f"{result}\n")

# Run the main function
if __name__ == "__main__":
    main()

