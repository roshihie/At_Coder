#include <bits/stdc++.h>
using namespace std;

void input(int& rnShortHnd, int& rnLongHnd, int& rnHour, int& rnMinute)
{
  cin >> rnShortHnd >> rnLongHnd >> rnHour >> rnMinute;
}

double calcClockHndsDist(int nShortHnd, int nLongHnd, int nHour, int nMinute)
{
  static const double PI = 3.141592653589793;

  double nShortAngl = ( nHour + ( nMinute / 60.0 )) / 12.0 * 2 * PI;
  double nLongAngl = ( nMinute / 60.0 ) * 2 * PI;
  double nDiffAngl = abs(nShortAngl - nLongAngl);
  if (nDiffAngl > PI)
    nDiffAngl = 2 * PI - nDiffAngl;

  double nHandsDist = nShortHnd * nShortHnd + nLongHnd * nLongHnd 
                      - 2 * nShortHnd * nLongHnd * cos(nDiffAngl);
  return sqrt(nHandsDist);
}
  
int main()
{
  int nShortHnd, nLongHnd, nHour, nMinute;

  input(nShortHnd, nLongHnd, nHour, nMinute);
  cout << fixed << setprecision(10) << calcClockHndsDist(nShortHnd, nLongHnd, nHour, nMinute);
  cout << endl;

  return 0;
}
