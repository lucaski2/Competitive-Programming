#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>

using namespace std;

struct State {
    string config;
    int moves;
    State(const string& c, int m) : config(c), moves(m) {}
};

int main() {
    int n;
    cin >> n;

    string start, end;
    cin >> start >> end;

    start += "..";
    end += "..";

    queue<State> q;
    q.push(State(start, 0));

    set<string> visited;
    visited.insert(start);

    while (!q.empty()) {
        State current = q.front();
        q.pop();

        if (current.moves > 25) {
            cout << -1 << endl;
            return 0;
        }

        if (current.config == end) {
            cout << current.moves << endl;
            return 0;
        }

        int dot_index = current.config.find('.');

        for (int i = 0; i < n + 1; ++i) {
            if (current.config[i] == '.') continue;

            string next = current.config;
            swap(next[i], next[dot_index]);
            swap(next[i+1], next[dot_index+1]);

            if (visited.find(next) == visited.end()) {
                visited.insert(next);
                q.push(State(next, current.moves + 1));
            }
        }
    }

    cout << -1 << endl;
    return 0;
}