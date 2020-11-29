#include <bits/stdc++.h>
using namespace std;

int main()
{
  int nNum;
  cin >> nNum;

  long nFact = 1;
  const int cnnMod = 1e9 + 7;

  for (int nx = 1; nx <= nNum; ++nx)
  {
    nFact *= nx;
    nFact %= cnnMod;
  }

  cout << nFact << endl;
  return 0;
}
