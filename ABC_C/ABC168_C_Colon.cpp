#include <bits/stdc++.h>
using namespace std;

void fnInput(int& rnShtHand, int& rnLngHand, int& rnHour, int& rnMinute)
{
  cin >> rnShtHand >> rnLngHand >> rnHour >> rnMinute;
}

double fnClockHandsDist(int nShtHand, int nLngHand, int nHour, int nMinute)
{
  static const double pi = 3.141592653589793;

  double nShtAngl = (nHour + (nMinute / 60.0)) / 12.0 * 360;
  double nLngAngl = (nMinute / 60.0) * 360;
  double nDiffAngl = abs(nShtAngl - nLngAngl);
  if (nDiffAngl > 180)
    nDiffAngl = 360 - nDiffAngl;

  double nHandsDist = nShtHand * nShtHand + nLngHand * nLngHand 
                      - 2 * nShtHand * nLngHand * cos(2 * pi * nDiffAngl / 360);
  return sqrt(nHandsDist);
}
  
int main()
{
  int nShtHand, nLngHand, nHour, nMinute;

  fnInput(nShtHand, nLngHand, nHour, nMinute);
  cout << fixed << setprecision(10) << fnClockHandsDist(nShtHand, nLngHand, nHour, nMinute);
  cout << endl;

  return 0;
}
