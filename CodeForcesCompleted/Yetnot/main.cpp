#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int main() {
    int t;
    std::cin >> t;
    std::cin.ignore(); // Consume newline

    while (t--) {
        std::string s;
        std::getline(std::cin, s);
        std::vector<int> uppers, lowers;

        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == 'b') {
                if (!lowers.empty()) lowers.pop_back();
                continue;
            }
            if (s[i] == 'B') {
                if (!uppers.empty()) uppers.pop_back();
                continue;
            }
            if (std::isupper(s[i])) {
                uppers.push_back(i);
            } else {
                lowers.push_back(i);
            }
        }

        std::string end;
        int ind1 = 0, ind2 = 0;

        while (ind1 < uppers.size() || ind2 < lowers.size()) {
            if (ind1 < uppers.size() && ind2 >= lowers.size()) {
                end += s[uppers[ind1]];
                ind1++;
                continue;
            }
            if (ind1 >= uppers.size() && ind2 < lowers.size()) {
                end += s[lowers[ind2]];
                ind2++;
                continue;
            }
            if (uppers[ind1] < lowers[ind2]) {
                end += s[uppers[ind1]];
                ind1++;
            } else {
                end += s[lowers[ind2]];
                ind2++;
            }
        }
        std::cout << end << std::endl;
    }

    return 0;
}