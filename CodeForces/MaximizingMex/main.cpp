#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int main() {
    long long t;
    cin >> t;  // Read number of test cases
    while (t--) {
        long long n, x;
        cin >> n >> x;  // Read n and x
        vector<long long> a(n);  // Vector to store the array
        for (long long i = 0; i < n; ++i) {
            cin >> a[i];  // Read elements of the array
        }

        // Create a frequency map
        map<long long, long long> what_we_have;
        for (long long i = 0; i < n; ++i) {
            what_we_have[a[i]]++;  // Increment frequency of each element
        }

        // Process each unique element
        vector<long long> cur;
        for (auto &p : what_we_have) {
            cur.push_back(p.first);  // Extract keys (unique elements)
        }

        for (long long element : cur) {
            long long am = element + x;
            while (what_we_have[element] > 1) {  // While there are duplicates
                if (what_we_have.find(am) == what_we_have.end()) {
                    what_we_have[am] = 1;  // Insert new element
                    what_we_have[element]--;  // Decrease the frequency
                }
                am += x;
            }
        }

        // Find the MEX
        vector<long long> sorted_elements;
        for (auto &p : what_we_have) {
            sorted_elements.push_back(p.first);  // Store unique elements
        }
        sort(sorted_elements.begin(), sorted_elements.end());  // Sort the unique elements

        long long mex = 0;
        for (long long i = 0; i < sorted_elements.size(); ++i) {
            if (sorted_elements[i] != mex) {
                break;  // Break if the element is not equal to the expected MEX
            }
            mex++;
        }

        // Output the result
        cout << mex << endl;
    }
    return 0;
}
