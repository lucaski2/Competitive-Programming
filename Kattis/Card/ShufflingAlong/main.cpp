#include <iostream>
#include <cmath>
using namespace std;

int main(void)
{
    int deck_size;
    string type;
    cin >> deck_size >> type;

    bool is_in = type == "in";

    int deck[deck_size];
    int deck_half2[(int)(is_in ? ceil(deck_size / 2.0) : floor(deck_size / 2.0))];
    int deck_half1[(int)(is_in ? floor(deck_size / 2.0) : ceil(deck_size / 2.0))];
    for (int i = 0; i < deck_size; i++)
    {
        deck[i] = i;
    }
    // printf("%d", (int)(is_in ? ceil(deck_size / 2.0) : floor(deck_size / 2.0)));
    // printf("%d", (int)(is_in ? floor(deck_size / 2.0) : ceil(deck_size / 2.0)));
    int i;

    while (true)
    {
        // split deck into two halves
        for (int j = 0; j < deck_size; j++)
        {
            if (j < sizeof(deck_half1) / sizeof(deck_half1[0]))
            {
                deck_half1[j] = deck[j];
            }
            else
            {
                deck_half2[j - sizeof(deck_half1) / sizeof(deck_half1[0])] = deck[j];
            }
            
        }

        for (int j = 0; j < deck_size; j++)
        {
            if (is_in)
            {
                deck[j] = (j % 2 == 0) ? deck_half2[j / 2] : deck_half1[j / 2];
            }
            else
            {
                deck[j] = (j % 2 == 0) ? deck_half1[j / 2] : deck_half2[j / 2];
            }
        }
        // check if deck is in order
        bool is_in_order = true;
        for (int j = 0; j < deck_size; j++)
        {
            if (deck[j] != j)
            {
                is_in_order = false;
            }
        }
        i++;

        if (is_in_order)
        {
            break;
        }
    }
    cout << i << endl;

}