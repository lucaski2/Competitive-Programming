
def extract_layer(matrix, layer_num):
    n = len(matrix)
    m = len(matrix[0])
    if layer_num >= min(n, m) // 2:
        return []
    
    result = []
    # Top row (left to right)
    for j in range(layer_num, m - layer_num):
        result.append(matrix[layer_num][j])
    
    # Right column (top to bottom)
    for i in range(layer_num + 1, n - layer_num):
        result.append(matrix[i][m - 1 - layer_num])
    
    # Bottom row (right to left)
    for j in range(m - 2 - layer_num, layer_num - 1, -1):
        result.append(matrix[n - 1 - layer_num][j])
    
    # Left column (bottom to top)
    for i in range(n - 2 - layer_num, layer_num, -1):
        result.append(matrix[i][layer_num])
    
    return result

def count_pattern_occurrences(sequence):
    if not sequence:
        return 0
        
    pattern = "1543"
    count = 0
    n = len(sequence)
    
    sequence_str = ''.join(map(str, sequence * 2))
    
    for i in range(n):
        if sequence_str[i:i+4] == pattern:
            count += 1
            
    return count

def solve_test_case():
    n, m = map(int, input().split())
    
    carpet = []
    for _ in range(n):
        row = list(map(int, input().strip()))
        carpet.append(row)
    
    total_occurrences = 0
    num_layers = min(n, m) // 2
    
    for layer in range(num_layers):
        layer_sequence = extract_layer(carpet, layer)
        occurrences = count_pattern_occurrences(layer_sequence)
        total_occurrences += occurrences
    
    return total_occurrences

def main():
    t = int(input())
    
    for _ in range(t):
        result = solve_test_case()
        print(result)

if __name__ == "__main__":
    main()