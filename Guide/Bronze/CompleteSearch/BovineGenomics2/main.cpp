#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <unordered_set>

int main() {
    std::ifstream infile("cownomics.in");
    std::ofstream outfile("cownomics.out");

    int n, m;
    infile >> n >> m;
    infile.ignore(); // Ignore the newline character

    std::vector<std::string> genomes(2 * n);
    for (int i = 0; i < 2 * n; ++i) {
        std::getline(infile, genomes[i]);
    }

    std::vector<std::tuple<int, int, int>> perms;
    for (int i = 0; i < m - 2; ++i) {
        for (int j = i + 1; j < m - 1; ++j) {
            for (int k = j + 1; k < m; ++k) {
                perms.emplace_back(i, j, k);
            }
        }
    }

    int count = 0;
    for (int p = 0; p < perms.size(); ++p) {
        std::unordered_set<std::string> spotty_perms;
        for (int i = 0; i < n; ++i) {
            std::string pattern = {genomes[i][std::get<0>(perms[p])], genomes[i][std::get<1>(perms[p])], genomes[i][std::get<2>(perms[p])]};
            spotty_perms.insert(pattern);
        }

        bool found = false;
        for (int i = n; i < 2 * n; ++i) {
            std::string pattern = {genomes[i][std::get<0>(perms[p])], genomes[i][std::get<1>(perms[p])], genomes[i][std::get<2>(perms[p])]};
            if (spotty_perms.count(pattern)) {
                found = true;
                break;
            }
        }
        if (!found) {
            ++count;
        }
    }

    outfile << count << std::endl;

    infile.close();
    outfile.close();
    return 0;
}