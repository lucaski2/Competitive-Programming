#include <iostream>
#include <unordered_map>
#include <strings.h>
#include <stdlib.h>
#include <cstring>
using namespace std;

int main(void)
{
    int N;
    char B;
    cin >> N >> B;
    int total = 0;
    unordered_map<char, int> tableD;
    tableD['A'] = 11;
    tableD['K'] = 4;
    tableD['Q'] = 3;
    tableD['J'] = 20;
    tableD['T'] = 10;
    tableD['9'] = 14;
    tableD['8'] = 0;
    tableD['7'] = 0;
    unordered_map<char, int> tableND;
    tableND['A'] = 11;
    tableND['K'] = 4;
    tableND['Q'] = 3;
    tableND['J'] = 2;
    tableND['T'] = 10;
    tableND['9'] = 0;
    tableND['8'] = 0;
    tableND['7'] = 0;
    
    char current_card[2];

    for (int i = 0; i < N * 4; i++)
    {
        cin >> current_card;
        if (memcmp(&current_card[1], &B, sizeof(char)) == 0)
        {
            auto n = tableD.find(current_card[0]);
            if (n != tableD.end())
            {
                total += n->second;
            }
        }
        else
        {
            auto n = tableND.find(current_card[0]);
            if (n != tableND.end())
            {
                total += n->second;
            }
        }
    }
    cout << total;
}