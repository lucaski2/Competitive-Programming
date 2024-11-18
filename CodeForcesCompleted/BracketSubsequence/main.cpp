#include <bits/stdc++.h>    
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    int cur_unclosed = 0;
    vector<char> ans;
    
    for (int i = 0; i < n; i++)
    {
        if (ans.size() + cur_unclosed < k)
        {
            char chur = s[i];
            if (chur == '(')
            {
                ans.push_back(chur);
                cur_unclosed++;
            }
            else
            {
                ans.push_back(chur);
                cur_unclosed--;
            }
        }
    }
    for (int i = 0; i < cur_unclosed; i++)
    {
        ans.push_back(')');
    }
    cout << string(ans.begin(), ans.end()) << endl;
    
}
