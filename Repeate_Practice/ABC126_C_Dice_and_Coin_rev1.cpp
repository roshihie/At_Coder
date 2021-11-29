#include <bits/stdc++.h>
using namespace std;

void input(int& rnMaxNum, int& rnWinPnt)
{
  cin >> rnMaxNum >> rnWinPnt;
}

double calcWinRate(int nMaxNum, int nWinPnt)
{
  double nWinRate = 0.0;

  for (int nx = 1; nx <= nMaxNum; ++nx)
  {
    int nPoint = nx;
    double nOneRate = 1.0 / nMaxNum;

    while (nPoint < nWinPnt)
    {
      nOneRate /= 2;
      nPoint   *= 2;
    }
    nWinRate += nOneRate;
  }
  return nWinRate;
}
 
int main()
{
  int nMaxNum, nWinPnt;
  input(nMaxNum, nWinPnt);
  cout << fixed << setprecision(10) << calcWinRate(nMaxNum, nWinPnt) << endl;

  return 0;
}
