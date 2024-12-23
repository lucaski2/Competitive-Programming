sequence_length, threshold = map(int, input().split())

pair_counts = [[0] * 26 for _ in range(26)]

input_chars = list(input())
char_indices = []
for index in range(sequence_length):
    char_indices.append(ord(input_chars[index]) - ord('a'))

for index in range(sequence_length - 2):
    first_char = char_indices[index]
    second_char = char_indices[index + 1]
    third_char = char_indices[index + 2]
    if first_char != second_char and second_char == third_char:
        pair_counts[first_char][second_char] += 1

matching_pairs = []
for first_index in range(26):
    for second_index in range(26):
        if first_index == second_index:
            continue
        if pair_counts[first_index][second_index] >= threshold:
            matching_pairs.append(chr(first_index + ord('a')) + chr(second_index + ord('a')) * 2)
        elif pair_counts[first_index][second_index] == threshold - 1:
            for char_pos in range(sequence_length):
                if (
                    (char_pos + 2 < sequence_length and char_indices[char_pos] == first_index and char_indices[char_pos + 1] == second_index and char_indices[char_pos + 2] == second_index) or
                    (char_pos + 1 < sequence_length and char_pos > 0 and char_indices[char_pos - 1] == first_index and char_indices[char_pos] == second_index and char_indices[char_pos + 1] == second_index) or
                    (char_pos > 1 and char_indices[char_pos - 2] == first_index and char_indices[char_pos - 1] == second_index and char_indices[char_pos] == second_index)
                ):
                    continue

                original_char = char_indices[char_pos]
                char_indices[char_pos] = first_index
                if (
                    (char_pos + 2 < sequence_length and char_indices[char_pos] == first_index and char_indices[char_pos + 1] == second_index and char_indices[char_pos + 2] == second_index) or
                    (char_pos + 1 < sequence_length and char_pos > 0 and char_indices[char_pos - 1] == first_index and char_indices[char_pos] == second_index and char_indices[char_pos + 1] == second_index) or
                    (char_pos > 1 and char_indices[char_pos - 2] == first_index and char_indices[char_pos - 1] == second_index and char_indices[char_pos] == second_index)
                ):
                    matching_pairs.append(chr(first_index + ord('a')) + chr(second_index + ord('a')) * 2)
                    break

                char_indices[char_pos] = second_index
                if (
                    (char_pos + 2 < sequence_length and char_indices[char_pos] == first_index and char_indices[char_pos + 1] == second_index and char_indices[char_pos + 2] == second_index) or
                    (char_pos + 1 < sequence_length and char_pos > 0 and char_indices[char_pos - 1] == first_index and char_indices[char_pos] == second_index and char_indices[char_pos + 1] == second_index) or
                    (char_pos > 1 and char_indices[char_pos - 2] == first_index and char_indices[char_pos - 1] == second_index and char_indices[char_pos] == second_index)
                ):
                    matching_pairs.append(chr(first_index + ord('a')) + chr(second_index + ord('a')) * 2)
                    break

                char_indices[char_pos] = original_char

print(len(matching_pairs))
matching_pairs.sort()
print('\n'.join(matching_pairs))