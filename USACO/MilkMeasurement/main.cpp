#include <bits/stdc++.h>
using namespace std;

struct Measurement {
    int day;
    string cow;
    int change;
};

bool compareMeasurements(const Measurement& a, const Measurement& b) {
    return a.day < b.day;
}

int main() {
    ifstream inp("measurement.in");
    ofstream out("measurement.out");

    int N;
    inp >> N;

    vector<Measurement> measurements(N);
    for (int i = 0; i < N; ++i) {
        inp >> measurements[i].day >> measurements[i].cow >> measurements[i].change;
    }

    // Sort measurements by day
    sort(measurements.begin(), measurements.end(), compareMeasurements);

    // Initial milk production
    map<string, int> milk = {{"Bessie", 7}, {"Elsie", 7}, {"Mildred", 7}};

    set<string> currentLeaders = {"Bessie", "Elsie", "Mildred"};
    int changeCount = 0;

    for (const auto& m : measurements) {
        // Update the milk output of the specified cow
        milk[m.cow] += m.change;

        // Find the maximum milk production
        int maxMilk = max({milk["Bessie"], milk["Elsie"], milk["Mildred"]});

        // Determine the new set of leaders
        set<string> newLeaders;
        for (const auto& pair : milk) {
            if (pair.second == maxMilk) {
                newLeaders.insert(pair.first);
            }
        }

        // Compare the new leaders with the current leaders
        if (newLeaders != currentLeaders) {
            ++changeCount;
            currentLeaders = newLeaders;
        }
    }

    out << changeCount << endl;

    return 0;
}
