#include <bits/stdc++.h>
using namespace std;

int main()
{
  int nNum, nKnum;
  cin >> nNum >> nKnum;

  int nComb = nKnum;
  for (int n = 2; n <= nNum; n++)
    nComb *= (nKnum - 1);

  cout << nComb << endl;
  return 0;
}
