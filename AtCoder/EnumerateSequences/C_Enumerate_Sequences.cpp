#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, K;
vector<int> R;

// Recursive function to generate sequences
void generateSequences(vector<int>& sequence, int index, int sum) {
    if (index == N) {
        if (sum % K == 0) {  // Check if sum is a multiple of K
            for (int num : sequence) {
                cout << num << " ";
            }
            cout << endl;
        }
        return;
    }
    
    for (int i = 1; i <= R[index]; ++i) {
        sequence[index] = i;
        generateSequences(sequence, index + 1, sum + i);
    }
}

int main() {
    // Input reading
    cin >> N >> K;
    R.resize(N);
    for (int i = 0; i < N; ++i) {
        cin >> R[i];
    }

    vector<int> sequence(N, 0);
    generateSequences(sequence, 0, 0);
    
    return 0;
}
