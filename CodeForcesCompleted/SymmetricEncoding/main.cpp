#include <bits/stdc++.h>
#include <iostream>
using namespace std;


string removeDuplicates(string s, int n)
{
    unordered_map<char, int> exists;
    string ans = "";
    for (int i = 0; i < n; i++) {
        if (exists.find(s[i]) == exists.end()) {
            ans.push_back(s[i]);
            exists[s[i]]++;
        }
    }
    return ans;
}





int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        int n;
        cin >> n; cin >> s;
        string r = removeDuplicates(s, n);
        sort(r.begin(), r.end());
        string reverse_r = r;
        reverse(reverse_r.begin(), reverse_r.end());
        
        for (int i = 0; i < s.length(); i++)
        {
            s[i] = reverse_r[r.find(s[i])];
        }
        cout << s << endl;

    }
}