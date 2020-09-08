#include <bits/stdc++.h>
using namespace std;

void input(int& rnMaxNum, int& rnWinPnt)
{
  cin >> rnMaxNum >> rnWinPnt;
}

double calcWinRate(int nMaxNum, int nWinPnt)
{
  vector<int> vnBorder;

  int nBorder = nWinPnt;
  vnBorder.push_back( nBorder );

  while (nBorder > 1)
  {
    nBorder = (nBorder + 1) / 2;           // 切り上げ
    vnBorder.push_back( nBorder );
  }
  double nWinRate = 0.0;

  for (int nPower = vnBorder.size() - 1; nPower > 0; nPower--)
  {
    double nOneRate = 0.0;
    int nNum = vnBorder[nPower];

    while (nNum < min(vnBorder[nPower - 1], nMaxNum + 1))
    {
      nOneRate += 1.0 / nMaxNum;
      nNum++;
    }
    for (int n = 0; n < nPower; n++)
      nOneRate /= 2;

    nWinRate += nOneRate;
  }
  if (nMaxNum >= vnBorder[0])
  {
    int nDiff = nMaxNum - vnBorder[0] + 1;
    nWinRate += (double)nDiff / nMaxNum;
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
