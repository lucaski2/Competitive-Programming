#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

bool is_palindrome(const string& substring) {
    int left = 0, right = substring.length() - 1;
    while (left < right) {
        if (substring[left] != substring[right]) {
            return false;
        }
        left++;
        right--;
    }
    return true;
}

int dfs(string& current, unordered_map<char, int>& remaining, int n, int k) {
    if (static_cast<int>(current.length()) == n) {
        for (int i = 0; i <= n - k; i++) {
            if (is_palindrome(current.substr(i, k))) {
                return 0;
            }
        }
        return 1;
    }

    int count = 0;
    for (auto it = remaining.begin(); it != remaining.end();) {
        char c = it->first;
        current.push_back(c);
        it->second--;

        if (it->second == 0) {
            it = remaining.erase(it);
        } else {
            ++it;
        }

        count += dfs(current, remaining, n, k);

        current.pop_back();
        remaining[c]++;

        if (it == remaining.end()) {
            break;
        }
    }

    return count;
}

int count_non_palindrome_perms(const string& s, int k) {
    int n = s.length();
    unordered_map<char, int> char_count;
    for (char c : s) {
        char_count[c]++;
    }

    string current;
    return dfs(current, char_count, n, k);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    string s;
    cin >> s;

    cout << count_non_palindrome_perms(s, k) << endl;

    return 0;
}