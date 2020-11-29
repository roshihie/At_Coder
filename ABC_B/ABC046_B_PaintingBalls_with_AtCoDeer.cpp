#include <bits/stdc++.h>
using namespace std;

int main()
{
  int nNum, nKnum;
  cin >> nNum >> nKnum;

  int nComb = nKnum;
  for (int nx = 2; nx <= nNum; ++nx)
    nComb *= (nKnum - 1);

  cout << nComb << endl;
  return 0;
}
