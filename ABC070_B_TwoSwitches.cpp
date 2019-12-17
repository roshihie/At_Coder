#include <bits/stdc++.h>
using namespace std;

int main()
{
  int nAmin, nAmax, nBmin, nBmax;
  cin >> nAmin >> nAmax >> nBmin >> nBmax;

  int nSameTime = min(nAmax, nBmax) - max(nAmin, nBmin);
  if (nSameTime < 0)  nSameTime = 0;

  cout << nSameTime << endl;

  return 0;
}
