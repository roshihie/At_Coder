#include <bits/stdc++.h>
using namespace std;

int main()
{
  int nNum;
  cin >> nNum;

  int64_t nFact = 1;
  for (int n = 1; n <= nNum; n++)
  {
    nFact *= n;
    nFact %= 1000000007;
  }

  cout << nFact << endl;
  return 0;
}
