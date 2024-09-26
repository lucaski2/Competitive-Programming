#include <iostream>
#include <string>

using namespace std;

int main() {
    string line;
    getline(cin, line);

    string st = "";
    for (int i = 0; i < line.length() - 1; i++) {
        if (!(line[i + 1] == '<' || line[i] == '<')) {
            st += line[i];
        }
        if (line[i] == '<' && line[i + 1] == '<') {
            st = st.substr(0, st.length() - 1);
        }
    }

    if (line[line.length() - 1] != '<') {
        cout << st + line[line.length() - 1] << endl;
    } else {
        cout << st << endl;
    }

    return 0;
}