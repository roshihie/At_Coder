#include <bits/stdc++.h>
using namespace std;
using llong = long long;

void input(llong& rnMax)
{
  cin >> rnMax;
}
  
llong calcCommaCnt(llong nMax)
{
  const vector<llong> cnvnBound = 
    { (llong)1e3  - 1, (llong)1e6  - 1, (llong)1e9  - 1,  
      (llong)1e12 - 1, (llong)1e15 - 1, (llong)1e18 - 1 };

  llong nCommaCnt = 0;
  int nx = 0;

  while (cnvnBound[nx] < nMax)
    nCommaCnt += nMax - cnvnBound[nx++];

  return nCommaCnt;
}

int main()
{
  llong nMax;
  input(nMax);
  cout << calcCommaCnt(nMax) << endl;

  return 0;
}
