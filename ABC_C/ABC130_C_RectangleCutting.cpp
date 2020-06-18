#include <bits/stdc++.h>
using namespace std;
using llong = long long;
using ldouble = long double;

void fnInput(int& rnWide, int& rnHigh, int& rnx, int& rny)
{
  cin >> rnWide >> rnHigh >> rnx >> rny;
}

void fnRectCutArea(int nWide, int nHigh, int nx, int ny)
{
  llong nRectArea = (llong)nWide * nHigh;
  ldouble nRectCutArea = nRectArea / 2.0;
  cout << nRectCutArea << " ";

  double nCenterx = nWide / 2.0;
  double nCentery = nHigh / 2.0;
  if (nCenterx == nx && nCentery == ny)
    cout << "1" << endl;
  else
    cout << "0" << endl;
}
  
int main()
{
  int nWide, nHigh, nx, ny;

  fnInput(nWide, nHigh, nx, ny);
  fnRectCutArea(nWide, nHigh, nx, ny);

  return 0;
}
