#include <iostream>
#include <vector>
#include <cmath>

using namespace std;


int main() {
  
  vector<int> a;
  for (int i = 0; i < 20; i++)
  {
    int ra = rand() % 100 + 20;
    // check if ra is in a
    if (find(a.begin(), a.end(), ra) == a.end())
    {
      a.push_back(ra);
    }
  }
  sort(a.begin(), a.end());

  for (int i = 1; i <= *min_element(a.begin(), a.end()) / 4; i++)
  {
    for (int j = 0; j < a.size(); j++)
    {
      cout << a[j] % i << " ";
    }
    cout << endl;
  }

}
