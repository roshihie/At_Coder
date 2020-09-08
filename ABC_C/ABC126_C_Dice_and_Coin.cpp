#include <bits/stdc++.h>
using namespace std;

void input(int& rnMaxNum, int& rnWinPnt)
{
  cin >> rnMaxNum >> rnWinPnt;
}

double calcWinRate(int nMaxNum, int nWinPnt)
{
  double nWinRate = 0;

  for (int n = 1; n <= nMaxNum; n++)
  {
    double nOneRate = 1.0 / nMaxNum;
    int nCur = n;

    while (nCur < nWinPnt)
    {
      nOneRate /= 2;
      nCur *= 2;
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
