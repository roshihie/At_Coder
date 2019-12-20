#include <bits/stdc++.h>
using namespace std;

int main()
{
  int64_t nAnum, nBnum, nXpos;
  cin >> nAnum >> nBnum >> nXpos;

  int64_t nDivHigh = nBnum / nXpos;
  int64_t nDivLow;

  if (nAnum - 1 < 0)
  {
    nDivHigh++;
    nDivLow = 0;
  }
  else
    nDivLow = (nAnum - 1) / nXpos;

  cout << (nDivHigh - nDivLow) << endl;
  return 0;
}
