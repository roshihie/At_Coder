#include <bits/stdc++.h>
using namespace std;

int main()
{
  long nAnum, nBnum, nXpos;
  cin >> nAnum >> nBnum >> nXpos;

  long nDivHigh = nBnum / nXpos;
  long nDivLow;

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
