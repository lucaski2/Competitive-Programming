def check_substring(s, queries):
    s_list = list(s)
    n = len(s)
    indices = set(i for i in range(n - 3) if s_list[i:i+4] == list("1100"))

    for idx, val in queries:
        idx -= 1
        val = str(val)
        old_val = s_list[idx]

        # Remove old index if necessary
        for i in range(max(0, idx - 3), min(n - 3, idx + 1)):
            if s_list[i:i+4] == list("1100") and i in indices:
                indices.remove(i)

        s_list[idx] = val

        # Add new index if necessary
        for i in range(max(0, idx - 3), min(n - 3, idx + 1)):
            if s_list[i:i+4] == list("1100") and i not in indices:
                indices.add(i)

        print("YES" if indices else "NO")


def main():
    t = int(input())

    for _ in range(t):
        s = input()
        q = int(input())
        queries = [list(map(int, input().split())) for _ in range(q)]

        check_substring(s, queries)


if __name__ == "__main__":
    main()